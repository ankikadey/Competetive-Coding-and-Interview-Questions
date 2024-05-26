#include <iostream>
#include <string>
using namespace std;

bool returnToOrigin(int n, string moves) {
    int x = 0, y = 0; // Starting position
    
    // Iterate through each move
    for (char move : moves) {
        if (move == 'U') {
            y++; // Move upwards
        } else if (move == 'D') {
            y--; // Move downwards
        } else if (move == 'R') {
            x++; // Move to the right
        } else if (move == 'L') {
            x--; // Move to the left
        }
    }
    
    // Check if returned to origin
    return x == 0 && y == 0;
}

int main() {
    int n;
    string moves;
    
    // Input number of moves and the sequence of moves
    cin >> n >> moves;
    
    // Check if Raju returns to the origin
    if (returnToOrigin(n, moves)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
