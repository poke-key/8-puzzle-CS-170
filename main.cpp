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
#include "PuzzleProblem.h"

using namespace std;

// Custom comparator for priority queue. prioritize nodes with the lowest cost
//(g(n) + h(n)) for expansion in queue. this creates a min heap.
struct CompareStates {
    bool operator()(const pair<double, PuzzleStatePtr>& a,
                   const pair<double, PuzzleStatePtr>& b) const {
        return a.first > b.first;  // Min heap
    }
};


int main() {

    cout << "Hello World!" << endl;

    return 0;

}