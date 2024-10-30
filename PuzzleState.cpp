#include "PuzzleState.h"

//constructor for the state of the puzles, contains a empty slot b, a parent p, an action, action, a cost, and size 
    //PuzzleState::PuzzleState(const vector<vector<int> >& b, PuzzleStatePtr p = nullptr, const string& act = "", int g = 0) : board(b), parent(p), actions(act), gCost(g), size(b.size()) {}

    //operator overloading comparing 2 states to check if they have identical
    //board configurations for goal checks
    bool PuzzleState::operator==(const PuzzleState& other) const {
        return board == other.board;
    }

    //locates blank tile (represented by 0) in puzzle and returns coords
    //used for finding which tiles can be swapped to generate new states
    pair<int, int> PuzzleState::findBlank() const {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] == 0) return {i, j};
            }
        }
        return {-1, -1};
    }

    //generates all possible states reachable from current state by moving the 
    //blank tile. for each move, it calculates the new pos of the blank tile.
    //if the move is within board's boundaries, creates new state w/ updated board
    //config, sets current state as parent, gCost++, adds state to neighbors list
    vector<PuzzleStatePtr> PuzzleState::getNeighbors() const {
        vector<PuzzleStatePtr> neighbors;
        const vector<pair<string, pair<int, int> > > moves = {
            {"Up", {-1, 0}}, {"Down", {1, 0}},
            {"Left", {0, -1}}, {"Right", {0, 1}}
        };

        auto [blankI, blankJ] = findBlank();

        for (const auto& [actions, delta] : moves) {
            int newI = blankI + delta.first;
            int newJ = blankJ + delta.second;

            if (newI >= 0 && newI < size && newJ >= 0 && newJ < size) {
                auto newBoard = board;
                swap(newBoard[blankI][blankJ], newBoard[newI][newJ]);
                auto newState = make_shared<PuzzleState>(newBoard);
                newState->parent = make_shared<PuzzleState>(*this);
                newState->actions = actions;
                newState->gCost = gCost + 1;
                neighbors.push_back(newState);
            }
        }
        return neighbors;
    }
    //converts puzzle board to string. replaces blank tile with 'b' for readability
    string PuzzleState::toString() const {
        stringstream ss;
        for (const auto& row : board) {
            for (int val : row) {
                ss << (val == 0 ? "b" : to_string(val)) << " ";
            }
            ss << "\n";
        }
        return ss.str();
    }