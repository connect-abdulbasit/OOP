#pragma once
#include <vector>
#include <raylib.h>
using namespace std;
class Grid
{
    int rows, colums, cellsize;
    vector<Color> colors;

public:
    Grid();
    void initialize();
    void draw();
    void print();
    int grid[20][20];
    bool IsCellOutside(int row, int column);
    void reset();
};