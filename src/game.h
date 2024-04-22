#pragma once
#include "grid.h"
#include "blocks.cpp" // Include blocks header file

class Game
{
public:
    Game(); // Constructor to initialize the game
    ~Game(); // Destructor to clean up resources
    void Draw(); // Function to draw the game
    void HandleInput(); // Function to handle user input
    void MoveBlockDown(); // Function to move the current block down
    bool gameOver; // Variable to track game over state
    int score; // Variable to store the player's score
    Music music; // Music object for background music

private:
    void MoveBlockLeft(); // Function to move the current block left
    void MoveBlockRight(); // Function to move the current block right
    Block GetRandomBlock(); // Function to get a random block
    std::vector<Block> GetAllBlocks(); // Function to get all block types
    bool IsBlockOutside(); // Function to check if the current block is outside the grid
    void RotateBlock(); // Function to rotate the current block
    void LockBlock(); // Function to lock the current block in place
    bool BlockFits(); // Function to check if the current block fits in the grid
    void Reset(); // Function to reset the game state
    void UpdateScore(int linesCleared, int moveDownPoints); // Function to update the player's score
    Grid grid; // Grid object representing the game grid
    std::vector<Block> blocks; // Vector to store all block types
    Block currentBlock; // Current block being controlled by the player
    Block nextBlock; // Next block to appear on the screen
    Sound rotateSound; // Sound for block rotation
    Sound clearSound; // Sound for clearing rows
};
