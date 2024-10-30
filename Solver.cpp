#include "Solver.h"
#include "PuzzleState.h"
#include "PuzzleProblem.h"
#include <iostream>

Solver::Solver(const PuzzleProblem& prob) : problem(prob) {}

pair<PuzzleStatePtr, SearchStats> Solver::solve(const string& heuristicType) {
    priority_queue<pair<double, PuzzleStatePtr>, 
                      vector<pair<double, PuzzleStatePtr>>,
                      CompareStates> frontier;
    set<vector<vector<int>>> explored;
    SearchStats stats;

    //frontier stores nodes for expansion, prioritizing based on
    //cost + heurstic
    //initial heurstic: for ucs, sets h(n) = 0.
    //misplaced: set h(n) as count of misplaced tiles.
    //euclidean: h(n) = sum of euclidean distances for each tile
    auto initial = problem.getInitialState();
    double initialH;
    
    if (heuristicType == "uniform") initialH = 0;
    else if (heuristicType == "misplaced") initialH = problem.misplacedTiles(initial);
    else initialH = problem.euclideanDistance(initial);

    frontier.push({initialH, initial});
    stats.maxQueueSize = 1;

    //after retrieving and removing the lowest cost node from queue,
    //solver checks if node's state matches the goal state using
    //problem.isGoal(current). if so, it returns goal state and stats
    //check if current node's board config has been visited before
    //if not, adds to explored and increments nodesExpanded in stats
    while (!frontier.empty()) {
        auto [fCost, current] = frontier.top();
        frontier.pop();

        if (problem.isGoal(current)) {
            stats.depth = current->gCost;
            return {current, stats};
        }

        if (explored.find(current->board) != explored.end()) continue;
        explored.insert(current->board);
        stats.nodesExpanded++;

        //outputs current state, cost, and heuristic
        //call getneighbors on curr state to generate possible neighbors
        cout << "\nExpanding state with g(n) = " << current->gCost;
        if (heuristicType == "uniform") cout << " and h(n) = 0\n";
        else if (heuristicType == "misplaced")
            cout << " and h(n) = " << problem.misplacedTiles(current) << "\n";
        else
            cout << " and h(n) = " << problem.euclideanDistance(current) << "\n";
        cout << current->toString();

        //calculates heurstic value based on heuristic type
        //combines neighbors gCost with h and adds resulting fCost and
        //neighbor to priority queue
        for (const auto& neighbor : current->getNeighbors()) {
            if (explored.find(neighbor->board) == explored.end()) {
                double h;
                if (heuristicType == "uniform") h = 0;
                else if (heuristicType == "misplaced") h = problem.misplacedTiles(neighbor);
                else h = problem.euclideanDistance(neighbor);
                
                frontier.push({neighbor->gCost + h, neighbor});
            }
        }

        stats.maxQueueSize = max(stats.maxQueueSize, (int)frontier.size());
    }

    return {nullptr, stats};
}