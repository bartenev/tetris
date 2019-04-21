#include "field.h"
#include "cell.h"
#include <iostream>
#include <windows.h>
using namespace std;
Field::Field()
{

}
void Field::clearField(){
    for (int i = 0; i < 22; ++i) {
        for (int j = 0; j < 12; ++j) {
            matrix[i][j].state = 0;
            matrix[i][j].color = NONE;
        }
    }
    for (int i = 0; i < 22; ++i) {
        matrix[i][0].state = 1;
        matrix[i][0].color = BORDER;
        matrix[i][11].state = 1;
        matrix[i][11].color = BORDER;
    }
    for (int i = 0; i < 12; ++i) {
        matrix[21][i].state = 1;
        matrix[21][i].color = BORDER;
    }
}

void Field::paint(){
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6);
    for (int i = 2; i < 22; ++i) {
        cout << "\t";
        for (int j = 0; j < 12; ++j) {
            if (matrix[i][j].state == 1 && matrix[i][j].color != NONE) {
                switch (matrix[i][j].color) {
                    case DARKBLUE:
                        SetConsoleTextAttribute(hConsole, 1);
                        break;
                    case GREEN:
                        SetConsoleTextAttribute(hConsole, 2);
                        break;
                    case BLUE:
                        SetConsoleTextAttribute(hConsole, 3);
                        break;
                    case RED:
                        SetConsoleTextAttribute(hConsole, 4);
                        break;
                    case PURPLE:
                        SetConsoleTextAttribute(hConsole, 5);
                        break;
                    case YELLOW:
                        SetConsoleTextAttribute(hConsole, 6);
                        break;
                    case GRAY:
                        SetConsoleTextAttribute(hConsole, 8);
                        break;
                    case BORDER:
                        SetConsoleTextAttribute(hConsole, 15);
                        break;
                    case NONE:
                        break;
                }
                cout << char(219) << char(219);
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}




















