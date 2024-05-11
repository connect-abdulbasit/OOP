#include "game.h"
#include <random>
#include <string.h>
#include <vector>
#include "colors.h"
using namespace std;
Game::Game()
{
    blocks = GetBlocks();
    CurrentBlock = GetRandomBlock();
    NextBlock = GetRandomBlock();
    Score = 0;
    GameOver = false;
    GameStarted = false;
}
Block Game::GetRandomBlock()
{
    if (blocks.empty())
    {
        blocks = GetBlocks();
    }

    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}
vector<Block> Game::GetBlocks()
{
    return {JBlock(), IBlock(), LBlock(), ZBlock(), OBlock(), SBlock(), TBlock()};
}
int Game::Draw()
{
    if (!GameStarted)
    {
        DrawText("Press spacebar to start the game", 215, 200, 30, WHITE);
        checkKey();
        return 0;
    }
    else
    {

        grid.draw();
        DrawText("Score", 700, 80, 42, WHITE);
        printScore(Score);
        CurrentBlock.Draw();
        displayMsg();
        if (Score > 99)
        {
            DrawText("Winner", 670, 470, 49, GREEN);
            DrawText("1", 730, 180, 34, WHITE);

            return 0;
        }
        return 1;
    }
}
void Game::displayMsg()
{
    if (GameOver)
    {
        DrawText("Press any key to restart the game", 155, 200, 20, WHITE);
        DrawText("Game Over", 640, 470, 42, RED);
    }
}
void Game::printScore(int score)
{
    int score1, score2;
    score1 = score / 10;
    score2 = score % 10;
    switch (score1)
    {
    case 0:
    case 10:
        DrawText("0", 750, 180, 34, WHITE);
        break;
    case 1:
        DrawText("1", 750, 180, 34, WHITE);
        break;
    case 2:
        DrawText("2", 750, 180, 34, WHITE);
        break;
    case 3:
        DrawText("3", 750, 180, 34, WHITE);
        break;
    case 4:
        DrawText("4", 750, 180, 34, WHITE);
        break;
    case 5:
        DrawText("5", 750, 180, 34, WHITE);
        break;
    case 6:
        DrawText("6", 750, 180, 34, WHITE);
        break;
    case 7:
        DrawText("7", 750, 180, 34, WHITE);
        break;
    case 8:
        DrawText("8", 750, 180, 34, WHITE);
        break;
    case 9:
        DrawText("9", 750, 180, 34, WHITE);
        break;
    default:
        break;
    }
    switch (score2)
    {
    case 0:
    case 10:
        DrawText("0", 770, 180, 34, WHITE);
        break;
    case 1:

        DrawText("1", 770, 180, 34, WHITE);
        break;
    case 2:
        DrawText("2", 770, 180, 34, WHITE);
        break;
    case 3:
        DrawText("3", 770, 180, 34, WHITE);

        break;
    case 4:
        DrawText("4", 770, 180, 34, WHITE);
        break;
    case 5:
        DrawText("5", 770, 180, 34, WHITE);
        break;
    case 6:
        DrawText("6", 770, 180, 34, WHITE);
        break;
    case 7:
        DrawText("7", 770, 180, 34, WHITE);
        break;
    case 8:
        DrawText("8", 770, 180, 34, WHITE);
        break;
    case 9:
        DrawText("9", 770, 180, 34, WHITE);
        break;

    default:
        break;
    }
}
void Game::checkKey()
{
    if (IsKeyPressed(KEY_SPACE))
    {
        GameStarted = true;
    }
}
void Game::HandleInput()
{
    int key = GetKeyPressed();
    if (!GameOver)
    {

        switch (key)
        {
        case KEY_LEFT:
            MoveLeft();
            break;
        case KEY_RIGHT:
            MoveRight();
            break;
        case KEY_UP:
            Rotate();
            break;
        case KEY_DOWN:
            MoveDown();
            break;
        }
    }
    else
    {
        if (IsKeyPressed(key))
        {
            GameOver = false;
            Score = 0;
            grid.reset();
        }
    }
}
int Game::CheckRows()
{
    int completed = 0, error;
    for (int i = 19; i >= 0; i--)
    {
        error = 0;
        for (int j = 0; j < 20; j++)
        {
            if (grid.grid[i][j] == 0)
            {
                error = 1;
                break;
            }
        }
        if (error == 0)
        {
            completed++;
            Score++;
        }
        else
        {
            for (int l = i; l < i + completed; l++)
            {
                for (int k = 0; k < 20; k++)
                {
                    grid.grid[l + 1][k] = grid.grid[l][k];
                }
            }
        }
    }
    return completed;
}
bool Game::CellOutside()
{
    vector<position> tiles = CurrentBlock.GetCellPosition();
    for (position item : tiles)
    {
        if (grid.IsCellOutside(item.row, item.column))
        {
            return true;
        }
    }
    return false;
}
void Game::MoveLeft()
{
    CurrentBlock.Move(0, -1);
    if (CellOutside() || CollideOverOther())
    {
        CurrentBlock.Move(0, 1);
    }
}
void Game::MoveRight()
{
    CurrentBlock.Move(0, 1);
    if (CellOutside() || CollideOverOther())
    {
        CurrentBlock.Move(0, -1);
    }
}
void Game::MoveDown()
{
    CurrentBlock.Move(1, 0);
    if (CellOutside() || CollideOverOther())
    {
        CurrentBlock.Move(-1, 0);
        LockBlock();
    }
}
void Game::Rotate()
{
    CurrentBlock.Rotate();
    if (CellOutside() || CollideOverOther())
    {
        undoRotate();
    }
}
void Game::undoRotate()
{
    CurrentBlock.undoRotate();
}
void Game ::LockBlock()
{
    if (!GameOver)
    {
        vector<position> tiles = CurrentBlock.GetCellPosition();
        for (position item : tiles)
        {
            grid.grid[item.row][item.column] = CurrentBlock.id;
        }
        CurrentBlock = NextBlock;
        if (CollideOverOther())
        {
            GameOver = true;
        }

        NextBlock = GetRandomBlock();
    }
}

bool Game::CollideOverOther()
{
    vector<position> tiles = CurrentBlock.GetCellPosition();
    for (position item : tiles)
    {
        if (grid.grid[item.row][item.column] != 0)
        {
            return true;
        }
    }
    return false;
}