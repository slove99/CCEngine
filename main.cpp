// Your First C++ Program

#include <iostream>
#include <vector>

// Board object
class Board {
    public:
        int** boardState; // Store game board

    Board(){
        // Define 17x17 board array
        boardState = new int*[17]; // Pointer array to 17 int arrays of length 17
        for (int i=0; i<17; i++)
            boardState[i] = new int[17]; // Create int arrays
        }

    void removeBoard(){
        // Remove 17x17 board array
        for (int i=0; i<17; i++)
            delete[] boardState[i]; // Deallocate memory associated with each int array
        delete[] boardState; // Deallocate pointer array
    }
};


// Piece object - containing player
class Piece {
    public:
        int player;
        int x;
        int y;
};


int main() {
    std::cout << "Hello World!\n";
    Board gameBoard;
    //gameBoard.boardState = 5;
    std::cout << gameBoard.boardState << "\n";
    return 0;
}
