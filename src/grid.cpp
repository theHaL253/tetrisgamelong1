#include "grid.h"
#include <iostream>
#include "colors.h"

// Constructor implementation to initialize Grid
Grid::Grid()
{
    numRows = 20; // Setting number of rows
    numCols = 10; // Setting number of columns
    cellSize = 30; // Setting cell size
    Initialize(); // Initializing the grid
    colors = GetCellColors(); // Getting cell colors
}

// Function to initialize the grid with zeros
void Grid::Initialize()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            grid[row][column] = 0; // Initializing each cell with zero
        }
    }
}

// Function to print the grid (for debugging purposes)
void Grid::Print()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            std::cout << grid[row][column] << " "; // Printing each cell value
        }
        std::cout << std::endl; // New line after printing each row
    }
}

// Function to draw the grid on the screen
void Grid::Draw()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            int cellValue = grid[row][column]; // Getting cell value
            DrawRectangle(column * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]); // Drawing rectangle for each cell with appropriate color
        }
    }
}

// Function to check if a cell is outside the grid
bool Grid::IsCellOutside(int row, int column)
{
    if (row >= 0 && row < numRows && column >= 0 && column < numCols)
    {
        return false; // Cell is inside the grid
    }
    return true; // Cell is outside the grid
}

// Function to check if a cell is empty
bool Grid::IsCellEmpty(int row, int column)
{
    if (grid[row][column] == 0)
    {
        return true; // Cell is empty
    }
    return false; // Cell is not empty
}

// Function to clear full rows in the grid and return the number of rows cleared
int Grid::ClearFullRows()
{
    int completed = 0; // Variable to store the number of completed rows
    for (int row = numRows - 1; row >= 0; row--)
    {
        if (IsRowFull(row))
        {
            ClearRow(row); // Clear the full row
            completed++; // Increment the number of completed rows
        }
        else if (completed > 0)
        {
            MoveRowDown(row, completed); // Move the row down by the number of completed rows
        }
    }
    return completed; // Return the number of completed rows
}

// Function to check if a row is full
bool Grid::IsRowFull(int row)
{
    for (int column = 0; column < numCols; column++)
    {
        if (grid[row][column] == 0)
        {
            return false; // Row is not full
        }
    }
    return true; // Row is full
}

// Function to clear a row by setting all its cells to zero
void Grid::ClearRow(int row)
{
    for (int column = 0; column < numCols; column++)
    {
        grid[row][column] = 0; // Clearing each cell in the row
    }
}

// Function to move a row down by given number of rows
void Grid::MoveRowDown(int row, int numRows)
{
    for (int column = 0; column < numCols; column++)
    {
        grid[row + numRows][column] = grid[row][column]; // Moving each cell in the row down
        grid[row][column] = 0; // Clearing the original cell
    }
}
