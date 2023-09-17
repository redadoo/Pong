#include "../lib/pong.h"


void DrawBackGround(WindowInfo windows)
{
    DrawLine(windows.WindowSize.x / 2,0,windows.WindowSize.x / 2,windows.WindowSize.y,WHITE);
}

int main(void)
{
    WindowInfo windows;

    windows.WindowSize.x = 800;
    windows.WindowSize.y = 450;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow( windows.WindowSize.x,  windows.WindowSize.y, "Pong");


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        Vector2 ballPosition = { (float) windows.WindowSize.x / 2, (float) windows.WindowSize.y / 2 };
        windows.WindowSize.y = GetScreenHeight();
        windows.WindowSize.x = GetScreenWidth();

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);

            DrawBackGround(windows);

            DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

            DrawCircleV(ballPosition, 10, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}