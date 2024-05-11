// 23k-0526
#include <raylib.h>
#include "game.h"
#include <iostream>
using namespace std;
int main()
{
    Color blue = {70, 80, 200, 110};
    InitWindow(900, 600, "raylib tatris");
    SetTargetFPS(60);
    Game tatrix;
    int time = 0, started;
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(blue);
        started = tatrix.Draw();
        if (started == 1 && time == 15)
        {
            time = 0;
            tatrix.MoveDown();
            tatrix.CheckRows();
        }
        else if (started == 1)
        {
            time++;
        }

        tatrix.HandleInput();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}