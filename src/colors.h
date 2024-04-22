#pragma once
#include <raylib.h> // Include Raylib library
#include <vector> // Include vector container

// Declare external constants for different colors
extern const Color darkGrey;
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;
extern const Color lightBlue;
extern const Color darkBlue;

// Declare function prototype for getting cell colors
std::vector<Color> GetCellColors();
