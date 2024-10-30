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

#ifndef PUZZLESTATE_H
#define PUZZLESTATE_H

using namespace std;

class PuzzleState;
using PuzzleStatePtr = shared_ptr<PuzzleState>;


class PuzzleState {

    public:
        vector<vector<int>> board; //grid
        PuzzleStatePtr parent;
        string action; //up, down, etc
        int gCost; //cost to reach this state from initial state
        int size; //dimensions of the puzzle

    //constructor for the state of the puzles, contains a empty slot b, a parent p, an action, action, a cost, and size 
    PuzzleState(const vector<vector<int>>& b, PuzzleStatePtr p = nullptr, const string& act = "", int g = 0) : board(b), parent(p), action(act), gCost(g), size(b.size()) {}

    bool operator==(const PuzzleState& other) const;


    pair<int, int> findBlank() const;
    vector<PuzzleStatePtr> getNeighbors() const;
    string toString() const;


};

#endif