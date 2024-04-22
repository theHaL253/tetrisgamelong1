#include "game.h"
#include <random>

// Constructor implementation to initialize the game
Game::Game()
{
    // Initialize game objects and variables
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
    score = 0;

    // Initialize audio resources
    InitAudioDevice();
    music = LoadMusicStream("Sounds/music.mp3");
    PlayMusicStream(music);
    rotateSound = LoadSound("Sounds/rotate.mp3");
    clearSound = LoadSound("Sounds/clear.mp3");
}

// Destructor implementation to clean up resources
Game::~Game()
{
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    UnloadMusicStream(music);
    CloseAudioDevice();
}

// Function to get a random block
Block Game::GetRandomBlock()
{
    // Ensure there are blocks available
    if (blocks.empty())
    {
        blocks = GetAllBlocks();
    }

    // Get a random index
    int randomIndex = rand() % blocks.size();

    // Retrieve the block at the random index
    Block block = blocks[randomIndex];

    // Remove the block from the available blocks
    blocks.erase(blocks.begin() + randomIndex);

    return block;
}

// Function to get all block types
std::vector<Block> Game::GetAllBlocks()
{
    // Return a vector containing all block types
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

// Function to draw the game
void Game::Draw()
{
    // Draw the game elements
    grid.Draw();
    currentBlock.Draw(11, 11);

    // Draw the next block at a specific position
    switch (nextBlock.id)
    {
    case 3:
        nextBlock.Draw(255, 290);
        break;
    case 4:
        nextBlock.Draw(255, 280);
        break;
    default:
        nextBlock.Draw(270, 270);
        break;
    }
}

// Function to handle user input
void Game::HandleInput()
{
    // Get the key pressed by the user
    int keyPressed = GetKeyPressed();

    // Handle game over state
    if (gameOver && keyPressed != 0)
    {
        gameOver = false;
        Reset();
    }

    // Handle movement and rotation based on user input
    switch (keyPressed)
    {
    case KEY_LEFT:
        MoveBlockLeft();
        break;
    case KEY_RIGHT:
        MoveBlockRight();
        break;
    case KEY_DOWN:
        MoveBlockDown();
        UpdateScore(0, 1); // Increment score when moving down
        break;
    case KEY_UP:
        RotateBlock();
        break;
    }
}
// This function moves the current block one position to the left if the game is not over. 
// It checks if the block is outside the grid or if it does not fit in its new position, 
// and if so, it moves the block back to its original position.
void Game::MoveBlockLeft()
{
    if (!gameOver)
    {
        currentBlock.Move(0, -1);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(0, 1);
        }
    }
}

// Similar to MoveBlockLeft(), this function moves the current block one position to the right 
// if the game is not over. It checks if the block is outside the grid or if it does not fit in 
// its new position, and if so, it moves the block back to its original position.
void Game::MoveBlockRight()
{
    if (!gameOver)
    {
        currentBlock.Move(0, 1);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(0, -1);
        }
    }
}

// This function moves the current block one position down if the game is not over. It checks if 
// the block is outside the grid or if it does not fit in its new position. If the block cannot move 
// down anymore, it locks the block in place and checks for completed rows.
void Game::MoveBlockDown()
{
    if (!gameOver)
    {
        currentBlock.Move(1, 0);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(-1, 0);
            LockBlock();
        }
    }
}

// This function checks if any part of the current block is outside the grid boundaries by iterating 
// through the block's cells and checking each cell's position against the grid boundaries.

bool Game::IsBlockOutside()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item : tiles)
    {
        if (grid.IsCellOutside(item.row, item.column))
        {
            return true;
        }
    }
    return false;
}

// This function rotates the current block clockwise if the game is not over. It checks if the block is 
// outside the grid or if it does not fit in its new position after rotation. If the block cannot rotate, 
// it undoes the rotation. Otherwise, it plays a sound effect.
void Game::RotateBlock()
{
    if (!gameOver)
    {
        currentBlock.Rotate();
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.UndoRotation();
        }
        else
        {
            PlaySound(rotateSound);
        }
    }
}

// This function locks the current block in its position on the grid and updates the grid accordingly. 
// It then assigns the next block as the current block and checks if the game is over. 
// If the new block does not fit in its initial position, the game is over. It also checks for completed rows and updates the score accordingly.
void Game::LockBlock()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item : tiles)
    {
        grid.grid[item.row][item.column] = currentBlock.id;
    }
    currentBlock = nextBlock;
    if (BlockFits() == false)
    {
        gameOver = true;
    }
    nextBlock = GetRandomBlock();
    int rowsCleared = grid.ClearFullRows();
    if (rowsCleared > 0)
    {
        PlaySound(clearSound);
        UpdateScore(rowsCleared, 0);
    }
}

// This function checks if the current block can fit into its current position on the grid without overlapping 
// with any occupied cells. It iterates through the block's cells and checks each cell's position against 
// the grid to see if it's empty
bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item : tiles)
    {
        if (grid.IsCellEmpty(item.row, item.column) == false)
        {
            return false;
        }
    }
    return true;
}
// This function resets the game state to its initial state, including resetting the grid, getting new 
// random blocks for the current and next blocks, and resetting the score to zero.
void Game::Reset()
{
    grid.Initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    score = 0;
}

// This function updates the player's score based on the number of lines cleared and the number of points 
// earned for moving the block down. It uses a switch statement to determine the score increment based on 
// the number of lines cleared.
void Game::UpdateScore(int linesCleared, int moveDownPoints)
{
    switch (linesCleared)
    {
    case 1:
        score += 100;
        break;
    case 2:
        score += 300;
        break;
    case 3:
        score += 500;
        break;
    default:
        break;
    }

    score += moveDownPoints;
}