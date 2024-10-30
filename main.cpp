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
}