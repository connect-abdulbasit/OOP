#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"
using namespace std;
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
    vector<position> GetCellPosition();
    int id;
    map<int, vector<position>> cells;
    vector<Color> colors;
};