#include "game.h"
#include <random>
#include <vector>
Game::Game()
{
    blocks = GetBlocks();
    CurrentBlock = GetRandomBlock();
    NextBlock = GetRandomBlock();
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
std::vector<Block> Game::GetBlocks()
{
    return {JBlock(), IBlock(), LBlock(), ZBlock(), OBlock(), SBlock(), TBlock()};
}
void Game::Draw()
{
    grid.draw();
    CurrentBlock.Draw();
}
void Game::HandleInput()
{
    int key = GetKeyPressed();
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
    std::vector<position> tiles = CurrentBlock.GetCellPosition();
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
    std::vector<position> tiles = CurrentBlock.GetCellPosition();
    for (position item : tiles)
    {
        grid.grid[item.row][item.column] = CurrentBlock.id;
    }
    CurrentBlock = NextBlock;
    NextBlock = GetRandomBlock();
}

bool Game::CollideOverOther()
{
    std::vector<position> tiles = CurrentBlock.GetCellPosition();
    for (position item : tiles)
    {
        if (grid.grid[item.row][item.column] != 0)
        {
            return true;
        }
    }
    return false;
}