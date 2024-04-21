#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

// Global variable to keep track of the last time an event was triggered
double lastUpdateTime = 0;

// Function to check if an event should be triggered based on a given interval
bool EventTriggered(double interval)
{
    // Get the current time
    double currentTime = GetTime();
    // Check if enough time has elapsed since the last event
    if (currentTime - lastUpdateTime >= interval)
    {
        // Update the last update time
        lastUpdateTime = currentTime;
        // Return true to indicate that the event should be triggered
        return true;
    }
    // Return false if the event should not be triggered yet
    return false;
}

// Main function
int main()
{
    // Initialize the window
    InitWindow(500, 620, "raylib Tetris");
    // Set the target frames per second
    SetTargetFPS(60);

    // Load the font for displaying text
    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    // Create an instance of the Game class
    Game game = Game();

    // Main game loop
    while (WindowShouldClose() == false)
    {
        // Update the music stream
        UpdateMusicStream(game.music);
        // Handle user input
        game.HandleInput();
        // Check if it's time to move the block down
        if (EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }

        // Begin drawing the game
        BeginDrawing();
        // Clear the background with a dark blue color
        ClearBackground(darkBlue);
        // Draw the score text
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        // Draw the "Next" text
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        // Draw "GAME OVER" text if the game is over
        if (game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE);
        }
        // Draw a rounded rectangle for the score display
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        // Convert the score to a string
        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        // Measure the size of the score text
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        // Draw the score text at the center of the rounded rectangle
        DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);
        // Draw a rounded rectangle for the next block display
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
        // Draw the game grid and current block
        game.Draw();
        // End drawing
        EndDrawing();
    }

    // Close the window
    CloseWindow();
}
