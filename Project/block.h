#pragma once
#include <vector>
#include <map>
#include "position.h"
#include"colors.h"
class Block
{
    int cellsize;
    int rowOffSet;
    int colOffSet;
    int rotationState;

public:
    Block();
    void Draw();
    void Move(int a, int b);
    void Rotate();
    void undoRotate();
    std::vector<position> GetCellPosition();
    int id;
    std::map<int, std::vector<position>> cells;
    std::vector<Color>colors;
};