#ifndef PUZZLE_STATE_H
#define PUZZLE_STATE_H

#include <vector>
#include <string>
#include <memory>
#include <sstream>

using namespace std;

//forward declarations
class PuzzleState;
using PuzzleStatePtr = shared_ptr<PuzzleState>; //enables shared ownership of pointer to state

class PuzzleState {

public:
    vector<vector<int>> board; //grid
    PuzzleStatePtr parent;
    string actions; //up, down, etc: moves
    int gCost; //tracks the cost to reach the state from initial state
    int size; //gets the dimension of the puzzle

    //constructor: contains an empty space b, pointer, action and cost
    PuzzleState(const vector<vector<int>>& b, PuzzleStatePtr p = nullptr, const string& act = "", int g = 0);

    //operator overload to compare 2 states for identicalness, board config for goal checks
    bool operator==(const PuzzleState& other) const;

    //locates blank tile (represented by 0) in puzzle and returns coordinates
    //used fpor finding the tiles that can be swapped to generate new states
    pair<int, int> findBlank() const;

    //gens all possible states reachable from the current state by moving the blank tile.
    //for each move, it calculates the new pos of the blank tile.
    //if the move is within board's boundaries, creates new state w/ updated board
    //config, sets current state as parent, gCost++, adds state to neighbors list
    vector<PuzzleStatePtr> getNeighbors() const;

    //converts the pouzzle board to a string, replaces the blank tile with a 'b'
    string toString() const;

};

#endif 