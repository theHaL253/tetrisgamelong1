#pragma once
#include <vector> // Include vector container
#include <map> // Include map container
#include "position.h" // Include position header file
#include "colors.h" // Include colors header file

// Declare Block class
class Block
{
public:
    // Constructor
    Block();
    // Function to draw the block on the screen
    void Draw(int offsetX, int offsetY);
    // Function to move the block by rows and columns
    void Move(int rows, int columns);
    // Function to get cell positions of the block
    std::vector<Position> GetCellPositions();
    // Function to rotate the block clockwise
    void Rotate();
    // Function to undo the last rotation
    void UndoRotation();
    // Block ID
    int id;
    // Map to store cell positions for each rotation state
    std::map<int, std::vector<Position>> cells;

private:
    // Size of each cell
    int cellSize;
    // Current rotation state of the block
    int rotationState;
    // Colors used for rendering the block
    std::vector<Color> colors;
    // Row offset for positioning the block
    int rowOffset;
    // Column offset for positioning the block
    int columnOffset;
};
