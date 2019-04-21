#ifndef CELL_H
#define CELL_H

enum Color {
    DARKBLUE,
    GREEN,
    BLUE,
    RED,
    PURPLE,
    YELLOW,
    GRAY,
    BORDER,
    NONE
};

class Cell
{
private:

public:
    bool state;
    Color color;
    Cell();
};

#endif // CELL_H
