#ifndef FIGURE_H
#define FIGURE_H
#include "cell.h"

class Figure
{
public:
    Color figureColor;
    int arrayCellX[4];
    int arrayCellY[4];
    int serialNumber;
    Figure();
    void stepDown();
};

#endif // FIGURE_H
