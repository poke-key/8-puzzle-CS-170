#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <memory>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include "PuzzleState.h"
#include "Solver.h"

using namespace std;

int main() {

    cout << "Welcome to 8 puzzle solver.\n"; // hi greetigh
    cout << "Type '1' to use a default puzzle, or '2' to enter your own puzzle: ";
    // some inputs
    string choice; 
    cin >> choice;
    vector<vector<int>> initialState(3, vector<int>(3));
    
    //show a sample rxample puzzle if they select choice 1
    if (choice == "1") {
        initialState = {
            {1, 3, 0},
            {4, 2, 6},
            {7, 5, 8}
        };
    } 
    // now else for not choice 1 user input
    else {
        cout << "Enter your puzzle, use a zero to represent the blank\n";
        for (int i = 0; i < 3; i++) {
            cout << "Enter the " << (i == 0 ? "first" : i == 1 ? "second" : "third")
                     << " row, use space or tabs between numbers: "; // prompt to custom enter the user desired puzzle
            for (int j = 0; j < 3; j++) {
                cin >> initialState[i][j]; // get each tile
            }
        }
    }
    // now we want to ask or the desired algorithm below is the prompt
    cout << "\nEnter your choice of algorithm:\n"
              << "1. Uniform Cost Search\n"
              << "2. A* with the Misplaced Tile heuristic\n"
              << "3. A* with the Euclidean distance heuristic\n";
    
    string algorithmChoice;
    cin >> algorithmChoice;

    //now we map a value to each heuristic choice below
    //this helps if we want to add more heuristics, all we would need to do
    //is to add a new key val pair for the heuristic
    map<string, string> heuristicMap;
    heuristicMap["1"] = "uniform";
    heuristicMap["2"] = "misplaced";
    heuristicMap["3"] = "euclidean";

    PuzzleProblem problem(initialState);
    Solver solver(problem);

    //call solve on solver, returning goalState and stats (which contains
    //information about nodes expanded, queue size, solution depth)
    auto [goalState, stats] = solver.solve(heuristicMap[algorithmChoice]);

    if (goalState) {
        // prompt below gfor goalstate
        cout << "\nGoal!!!\n"
                  << "\nTo solve this problem the search algorithm expanded a total of "
                  << stats.nodesExpanded << " nodes.\n"
                  << "The maximum number of nodes in the queue at any one time: "
                  << stats.maxQueueSize << "\n"
                  << "The depth of the goal node was " << stats.depth << "\n";

        //not needed but useful to see the solution path
        //traces back from goalState to initial state using parent pointers
        //gathering each state in the path
        vector<pair<string, PuzzleStatePtr>> path;
        auto current = goalState;
        while (current) {
            path.push_back(make_pair(current->actions, current));
            current = current->parent;
        }

        if (!path.empty()) {
            cout << "\nSolution path:\n";
            for (auto it = path.rbegin() + 1; it != path.rend(); ++it) {
                cout << "\n" << it->first << ":\n";
                cout << it->second->toString();
            }
        }
    } 
    else {
        // edge
        cout << "\nNo solution found!\n";
    }

    return 0;
}