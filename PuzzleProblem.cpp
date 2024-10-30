#include "PuzzleProblem.h"

PuzzleProblem::PuzzleProblem(const vector<vector<int>>& initial) {

    initialState = make_shared<PuzzleState>(initial);

    vector<vector<int>> goal = {

        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };
    goalState = make_shared<PuzzleState>(goal);
}

bool PuzzleProblem::isGoal(const PuzzleStatePtr &state) const {
    return *state == *goalState;
}

PuzzleStatePtr PuzzleProblem::getInitialstate() const {
    return initialState;
}

int PuzzleProblem::misplacedTiles(const PuzzleStatePtr& state) const {

    int count = 0;
    for(int i = 0; i < state->size; i++) {
        if(state->board[i][j] != 0 && state->board[i][j] != goalState->board[i][j]) 
            count++;
    }
    return count;
}

double PuzzleProblem::euclideanDistance(const PuzzleStatePtr& state) const {

    double total = 0;
    for(int i = 0; i < state->size; i++) {
        for(int j = 0; j < state->size; j++) {
            if(state->board[i][j] != 0) {
                int value = state->board[i][j];
                int goalI = (value - 1) / 3;
                int goalJ = (value - 1) % 3;
                total += sqrt(pow(i - goalI, 2) + pow(j - goalJ, 2));
            }
        }
    }
    return total;
}