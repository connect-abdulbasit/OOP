#include "block.h"
#include <iostream>
using namespace std;
Block::Block()
{
    cellsize = 30;
    rotationState = 0;
    rowOffSet = 0;
    colOffSet = 0;
    colors = GetColors();
}
void Block::Draw()
{
    vector<position> tiles = GetCellPosition();
    for (position item : tiles)
    {
        DrawRectangle(item.column * cellsize + 1, item.row * cellsize + 1, cellsize - 1, cellsize - 1, colors[id]);
    }
}
void Block::Move(int a, int b)
{
    rowOffSet += a;
    colOffSet += b;
}
vector<position> Block::GetCellPosition()
{
    vector<position> tiles = cells[rotationState];
    vector<position> movedTiles;
    for (position item : tiles)
    {
        movedTiles.push_back(position(item.row + rowOffSet, item.column + colOffSet));
    }
    return movedTiles;
}
void Block::Rotate()
{
    rotationState++;
    if (rotationState == 4)
    {
        rotationState = 0;
    }
}
void Block::undoRotate()
{
    rotationState--;
    if (rotationState == -1)
    {
        rotationState = 3;
    }
}