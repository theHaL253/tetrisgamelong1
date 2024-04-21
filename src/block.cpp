#include "block.h" // Include block header file

// Constructor
Block::Block()
{
    // Set cell size
    cellSize = 30;
    // Set initial rotation state
    rotationState = 0;
    // Get predefined colors
    colors = GetCellColors();
    // Initialize row offset
    rowOffset = 0;
    // Initialize column offset
    columnOffset = 0;
}

// Function to draw the block on the screen
void Block::Draw(int offsetX, int offsetY)
{
    // Get cell positions of the block
    std::vector<Position> tiles = GetCellPositions();
    // Draw each cell of the block
    for (Position item : tiles)
    {
        DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
    }
}

// Function to move the block by rows and columns
void Block::Move(int rows, int columns)
{
    // Update row offset
    rowOffset += rows;
    // Update column offset
    columnOffset += columns;
}

// Function to get cell positions of the block
std::vector<Position> Block::GetCellPositions()
{
    // Get cell positions for the current rotation state
    std::vector<Position> tiles = cells[rotationState];
    // Calculate positions after applying offsets
    std::vector<Position> movedTiles;
    for (Position item : tiles)
    {
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

// Function to rotate the block clockwise
void Block::Rotate()
{
    // Increment rotation state
    rotationState++;
    // Wrap around if exceeds maximum rotation state
    if (rotationState == (int)cells.size())
    {
        rotationState = 0;
    }
}

// Function to undo the last rotation
void Block::UndoRotation()
{
    // Decrement rotation state
    rotationState--;
    // Wrap around if rotation state is less than 0
    if (rotationState == -1)
    {
        rotationState = cells.size() - 1;
    }
}
