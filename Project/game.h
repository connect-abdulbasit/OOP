#pragma once
#include "grid.h"
#include "blocks.cpp"
class Game
{
    Block CurrentBlock;
    Block NextBlock;
    std::vector<Block> blocks;
    void MoveLeft();
    void MoveRight();
    void Rotate();
    void undoRotate();
    void LockBlock();
    bool CellOutside();
    bool CollideOverOther();
    bool GameOver;
    Grid grid;

public:
    void MoveDown();
    Game();
    Block GetRandomBlock();
    std::vector<Block> GetBlocks();
    void Draw();
    void HandleInput();
    int CheckRows();
};