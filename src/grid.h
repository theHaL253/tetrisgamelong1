#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
public:
    Grid(); // Constructor to initialize Grid
    void Initialize(); // Function to initialize the grid
    void Print(); // Function to print the grid
    void Draw(); // Function to draw the grid on the screen
    bool IsCellOutside(int row, int column); // Function to check if a cell is outside the grid
    bool IsCellEmpty(int row, int column); // Function to check if a cell is empty
    int ClearFullRows(); // Function to clear full rows in the grid
    int grid[20][10]; // Grid data structure

private:
    bool IsRowFull(int row); // Function to check if a row is full
    void ClearRow(int row); // Function to clear a row
    void MoveRowDown(int row, int numRows); // Function to move a row down by given number of rows
    int numRows; // Number of rows in the grid
    int numCols; // Number of columns in the grid
    int cellSize; // Size of each cell in the grid
    std::vector<Color> colors; // Vector to store colors for cells
};
