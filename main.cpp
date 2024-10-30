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
    // now else
    
}