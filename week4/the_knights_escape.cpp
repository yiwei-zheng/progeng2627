#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

bool reached(int col, int row){
    if (
        !(col == 1 && row == 8) && 
        !(col == 1 && row == 1) &&
        !(col == 8 && row == 1) &&
        !(col == 8 && row == 1)
    )
        return 0;
    return 1;
}

bool is_valid_move(int dx, int dy){
    dx = abs(dx);
    dy = abs(dy);
    return (dx == 2 && dy == 1) || (dy == 2 && dx == 1);
}


int main() {
    // Generate and display a random starting position
    // Seed the random number generator
    std::srand(std::time(NULL));

    // Generate random coordinates from 2 to 7
    int col = std::rand() % 6 + 2;
    int row = std::rand() % 6 + 2;
    std::cout << "the initial position is {" << col << ", " << row << "}\n";

    // Initialise the move counter
    int counter = 0;

    // While the knight has not reached a corner square:
        // Read destination coordinates from the user
        // If the move is valid:
            // Update position, increment move counter, display new position
        // Otherwise:
            // Display invalid move message

    while(!reached(col, row)){
        std::cout << "Enter the postion of next move: ";
        int x, y, dx, dy;
        std::cin >> x >> y;
        dx = x - col;
        dy = y - row;
        if (!is_valid_move(dx, dy) || !(1 <= x && x <= 8 && 1 <= y && y <= 8)){
            std::cout << "invalid move, try again!\n";
        }else{
            col = x;
            row = y;
            counter++;
        }
    }
    std::cout << "used " << counter << " moves to reach the corner square\n";

    // Display the total number of valid moves
    // taken to reach a corner square.
    return 0;
}