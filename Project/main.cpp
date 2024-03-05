//23k-0526
#include <raylib.h>
#include "game.h"
int main()
{
    Color blue = {70, 80, 200, 110};
    InitWindow(600, 600, "raylib tatris");
    SetTargetFPS(60);
    Game tatrix;
    int time = 0;
    while (WindowShouldClose() == false)
    {

        BeginDrawing();
        ClearBackground(blue);
        tatrix.Draw();
        if (time == 30)
        {
            time = 0;
            tatrix.MoveDown();
            tatrix.CheckRows();
        }
        tatrix.HandleInput();
        EndDrawing();
        time++;
    }

    CloseWindow();
    return 0;
}