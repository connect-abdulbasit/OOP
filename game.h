#pragma once
#include "grid.h"
#include "blocks.cpp"
using namespace std;
class Game
{
    Block CurrentBlock;
    Block NextBlock;
    vector<Block> blocks;
    void MoveLeft();
    void MoveRight();
    void Rotate();
    void undoRotate();
    void LockBlock();
    bool CellOutside();
    bool CollideOverOther();
    bool GameOver;
    bool GameStarted;
    int Score;
    void printScore(int score);
    void displayMsg();
    void checkKey();

    Grid grid;
    Block GetRandomBlock();
    vector<Block> GetBlocks();

public:
    void MoveDown();
    Game();
    int Draw();
    void HandleInput();
    int CheckRows();
};