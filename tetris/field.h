#ifndef FIELD_H
#define FIELD_H
#include "cell.h"


class Field
{
private:

public:
    Cell matrix[22][12];
    Field();
    void clearField();
    void paint();

};

#endif // FIELD_H
