#ifndef PUZZLE_STATE_H
#define PUZZLE_STATE_H

#include <vector>
#include <string>
#include <memory>
#include <sstream>

using namespace std;

// Forward declarations
class PuzzleState;
using PuzzleStatePtr = shared_ptr<PuzzleState>; //allows for shared ownership

class PuzzleState {
public:
    vector<vector<int>> board; //grid
    PuzzleStatePtr parent;
    string action; //up, down, etc
    int gCost; //cost to reach this state from initial state
    int size; //dimensions of the puzzle

    //constructor for the state of the puzles, contains a empty slot b, a parent p, an action, action, a cost, and size 
    PuzzleState(const vector<vector<int>>& b, PuzzleStatePtr p = nullptr, const string& act = "", int g = 0);

    //operator overloading comparing 2 states to check if they have identical
    //board configurations for goal checks
    bool operator==(const PuzzleState& other) const;

    //locates blank tile (represented by 0) in puzzle and returns coords
    //used for finding which tiles can be swapped to generate new states
    pair<int, int> findBlank() const;

    //generates all possible states reachable from current state by moving the 
    //blank tile. for each move, it calculates the new pos of the blank tile.
    //if the move is within board's boundaries, creates new state w/ updated board
    //config, sets current state as parent, gCost++, adds state to neighbors list
    vector<PuzzleStatePtr> getNeighbors() const;

    //converts puzzle board to string. replaces blank tile with 'b' for readability
    string toString() const;
};

#endif // PUZZLE_STATE_H