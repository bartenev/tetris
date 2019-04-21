#ifndef GAME_H
#define GAME_H
#include "field.h"
#include "figure.h"
#include "ifigure.h"

class Game
{
public:
    Game();
    void newGame();
    IFigure createFigure(Field& field, unsigned int numberOfVectorElements);
    void fill(Field& field, IFigure& figure, unsigned int numberOfVectorElements);
    bool stepDown(Field& field, Figure& figure);
    bool stepRight(Field& field, Figure& figure);
    bool stepLeft(Field& field, Figure& figure);
    bool cellCheck(Field& field, Figure& figure);
};

#endif // GAME_H
