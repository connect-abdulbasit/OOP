#include "grid.h"
#include <iostream>
#include "colors.h"
using namespace std;
Grid::Grid()
{
    rows = 20;
    colums = 20;
    cellsize = 30;
    initialize();
    colors = GetColors();
}
void Grid::initialize()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colums; j++)
        {
            grid[i][j] = 0;
        }
    }
}
void Grid::print()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colums; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool Grid::IsCellOutside(int row, int column)
{
    if (row >= 0 && row < this->rows && column >= 0 && column < this->colums)
    {
        return false;
    }
    return true;
}

void Grid::draw()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colums; j++)
        {
            int cellValue = grid[i][j];
            DrawRectangle(j * cellsize + 1, i * cellsize + 1, cellsize - 1, cellsize - 1, colors[cellValue]);
        }
    }
}
void Grid::reset()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colums; j++)
        {
            grid[i][j] = 0;
        }
    }
}