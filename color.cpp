#include "colors.h"
const Color darkGrey = {26, 31, 40, 255};
const Color green = {47, 230, 23, 255};
const Color red = {232, 18, 16, 255};
const Color yellow = {255, 255, 0, 255};
const Color orange = {226, 116, 17, 255};
const Color purple = {166, 0, 247, 255};
const Color cyan = {21, 203, 209, 255};
const Color blue = {13, 64, 216, 255};
const Color lightBlue = {59, 85, 162, 255};
std::vector<Color> GetColors()
{
    return {darkGrey, green, red, yellow, orange, purple, cyan, blue};
}