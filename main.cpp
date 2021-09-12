#include <iostream>
#include <vector>
#include <cmath>

// Board object is a 2d array of tiles
// Each tile object contains an x and y parameter
// Each tile contains a piece object or null
// The piece object has parameter player


// Piece object - containing player
class Piece {
    public:
        int player = 0;
};


class Tile {
    public:
        int x;
        int y;
        Piece piece;
};


class Board {
    public:
        Tile** boardState; // Store game board

        Board(){
            // Define 17x17 board array
            boardState = new Tile*[17]; // Pointer array to 17 int arrays of length 17
            for (int i=0; i<17; i++)
                boardState[i] = new Tile[17]; // Create int arrays
            }

    void removeBoard(){
        // Remove 17x17 board array
        for (int i=0; i<17; i++)
            delete[] boardState[i]; // Deallocate memory associated with each int array
        delete[] boardState; // Deallocate pointer array
    }

    // Print the game board to screen
    void printBoard(){
        for (int i=0; i<17; i++){
            for (int j=0; j<17; j++){
                std::cout << boardState[i][j].piece.player;
            }
         std::cout << "\n";
        }
    }

};






int main() {
    Board gameBoard;

    int boardWidths [17] = {1, 2, 3, 4, 13, 12, 11, 10, 9, 10, 11, 12, 13, 4, 3, 2, 1};

    // Create default board state for 15v15 2 player
    for (int y=0; y<17; y++)
    {
        for(int x=0; x < 17; x++){
            int yDiff = std::abs (((y + 8) % 17) - 8);
            std::cout <<yDiff;
            if (  (x > (8 - std::floor (0.5*yDiff)  - 1)) & (x < (8 + std::ceil (0.5*yDiff) )) & (y < 6 | y > 11) )
                gameBoard.boardState[y][x].piece.player = 1;
        }
    }
    gameBoard.printBoard();
    return 0;
}
