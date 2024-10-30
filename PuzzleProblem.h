#ifndef PUZZLE_PROBLEM_H
#define PUZZLE_PROBLEM_H

#include "PuzzleState.h"
#include <cmath>

class PuzzleProblem {


    private: 
        PuzzleStatePtr initialState; //starting config
        PuzzleStatePtr goalState; //8 puzzle layout

    public:
        PuzzleProblem(const vector<vector<int> >& initial);

        //checks if a given state machines the goal state
        //dereferences the provided and goal state pointer and uses the overloaded operator in uzzle state to compapre configs

        bool isGoal(const PuzzleStatePtr& state) const;

        //PuzzleStatePtr getInitialState() const;

        PuzzleStatePtr getInitialstate() const;

    //counts all tiles that differ in value from the goal config, ignoring blank
    //useful for A* search with misplaced tile heuristic
    int misplacedTiles(const PuzzleStatePtr& state) const;

    //calculates euclidean distance heuristic for a given state
    //for each tile except blank: computes euclidean distance
    //between its current pos and goal pos
    //sum up distances providing a heuristic value guiding the A* algo
    //towards states with tiles closer to their target positions
    double euclideanDistance(const PuzzleStatePtr& state) const;
};

#endif
