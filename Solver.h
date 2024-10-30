#ifndef SOLVER_H
#define SOLVER_H

#include "PuzzleProblem.h"
#include <queue>
#include <set>
#include <map>

struct SearchStats {
    int nodesExpanded = 0;
    int maxQueueSize = 0;
    int depth = -1;
};

//custom comparator for priority queue, prioritizes nodes with the lowest cost
//g(n) + h(n) for expansion in queue. this creates a min heap

struct CompareStates {

    bool operator()(const pair<double, PuzzleStatePtr>& a, const pair<double, PuzzleStatePtr>& b) const {
        return a.first > b.first; //min heap
    }
};

//executes the search algorithms on the 8 puzle problem
//initializes solvder with a puzzle problem instance to use the methods

class Solver {

    private:
        PuzzleProblem problem;

    public:
        Solver(const PuzzleProblem& prob);

        //solve: performs search. heursticType is a string indicating the type to use.
        //eg uniform, misplaced, or euclidean

        pair<PuzzleStatePtr, SearchStats> solve(const string& heuristicType);
};

#endif 
