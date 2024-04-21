#include "block.h"
#include "position.h"

class LBlock : public Block
{
public:
// This class represents the L-shaped Tetris block.

    LBlock()
    {
        id = 1; //The block ID is set to 1.
        //Cell positions for each rotation state are defined.
        cells[0] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)};
        cells[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};
        //The Move function is called to position the block.
        Move(0, 3);
    }
};

class JBlock : public Block
{
public:
    JBlock()
    {
        // Set block ID
        id = 2;
        // Define cell positions for each rotation state
        cells[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
        cells[3] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)};
        // Move block to starting position
        Move(0, 3);
    }
};


class IBlock : public Block
{
public:
    IBlock()
    {
        // Set block ID
        id = 3;
        // Define cell positions for each rotation state
        cells[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};
        cells[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};
        cells[2] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)};
        cells[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};
        // Move block to starting position
        Move(-1, 3);
    }
};


class OBlock : public Block
{
public:
    OBlock()
    {
        // Set block ID
        id = 4;
        // Define cell positions
        cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
        // Move block to starting position
        Move(0, 4);
    }
};


class SBlock : public Block
{
public:
    SBlock()
    {
        // Set block ID
        id = 5;
        // Define cell positions for each rotation state
        cells[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
        cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
        cells[2] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)};
        cells[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};
        // Move block to starting position
        Move(0, 3);
    }
};


class TBlock : public Block
{
public:
    TBlock()
    {
        // Set block ID
        id = 6;
        // Define cell positions for each rotation state
        cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
        cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
        // Move block to starting position
        Move(0, 3);
    }
};


class ZBlock : public Block
{
public:
    ZBlock()
    {
        // Set block ID
        id = 7;
        // Define cell positions for each rotation state
        cells[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
        cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};
        // Move block to starting position
        Move(0, 3);
    }
};
