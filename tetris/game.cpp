#include "game.h"
#include "field.h"
#include "figure.h"
#include "ifigure.h"
#include <windows.h>
#include <iostream>
#include <ctime>
#include <vector>
#include <conio.h>
using namespace std;

Game::Game()
{

}

void Game::newGame(){
    Field field;
    field.clearField();
    vector<Figure> vectorOfFigure;
    field.paint();
    while(1) { //временно
        vectorOfFigure.insert(vectorOfFigure.end(),createFigure(field, vectorOfFigure.size()));
        while(stepDown(field, vectorOfFigure.back())){
            system("cls");
            field.paint();
            Sleep(500);
            stepDown(field, vectorOfFigure.back());

//            int key = _getch(); // в key код клавиши, можем привести к char
//            if (key == 0xE0) // значение для навигац. клавиши, в нек-рых компилерах 0
//            {
//              key = _getch(); // собсно код самой навигац. клавиши
//              if (key == 0x50)
//                stepRight(field, vectorOfFigure.back());
//              //else if (key == 0x48)
//                //doUpArrowAction();
//            }

        }
    }
}

IFigure Game::createFigure(Field& field, unsigned int numberOfVectorElements){
    //srand(time(0));
    int randNumber = 1; //+ rand() % 7;
    if (randNumber == 1) {
        IFigure iFigure;
        fill(field, iFigure, numberOfVectorElements);
        return iFigure;
    }
}

void Game::fill(Field& field, IFigure& figure, unsigned int numberOfVectorElements){
    for (int i = 0; i < 4; ++i) {
        field.matrix[figure.arrayCellY[i]][figure.arrayCellX[i]].state = 1;
        field.matrix[figure.arrayCellY[i]][figure.arrayCellX[i]].color = figure.figureColor;
        figure.serialNumber = numberOfVectorElements;
    }
}

bool Game::cellCheck(Field& field, Figure& figure){
    int numberOfEmptyCells = 0;
    for (int i = 0; i < 4; i++) {
        if (!field.matrix[figure.arrayCellY[i] + 1][figure.arrayCellX[i]].state){
            numberOfEmptyCells++;
        } else {
            for (int j = 0; j < 4; j++) {
                if (figure.arrayCellX[i] + 1 == figure.arrayCellX[j]){
                    numberOfEmptyCells++;
                }
            }
        }
    }
    if (numberOfEmptyCells == 4)
        return 1;
    else
        return 0;
}

bool Game::stepDown(Field& field, Figure& figure){
    int numberOfEmptyCells = 0;
    for (int i = 0; i < 4; i++) {
        if (!field.matrix[figure.arrayCellY[i] + 1][figure.arrayCellX[i]].state){
            numberOfEmptyCells++;
        }
    }
    if (numberOfEmptyCells == 4) {
        for (int i = 0; i < 4; i++) {
            field.matrix[figure.arrayCellY[i] + 1][figure.arrayCellX[i]].state = 1;
            field.matrix[figure.arrayCellY[i] + 1][figure.arrayCellX[i]].color = field.matrix[figure.arrayCellY[i]][figure.arrayCellX[i]].color;
            field.matrix[figure.arrayCellY[i]][figure.arrayCellX[i]].state = 0;
            figure.arrayCellY[i]++;
        }
    } else {
        return 0;
    }

    return 1;
}

bool Game::stepRight(Field& field, Figure& figure){
    if (cellCheck(field, figure)) {
        for (int i = 0; i < 4; i++) {
            field.matrix[figure.arrayCellY[i]][figure.arrayCellX[i] + 1].state = 1;
            field.matrix[figure.arrayCellY[i]][figure.arrayCellX[i] + 1].color = field.matrix[figure.arrayCellY[i]][figure.arrayCellX[i]].color;
            field.matrix[figure.arrayCellY[i]][figure.arrayCellX[i]].state = 0;
            figure.arrayCellX[i]++;
        }
    } else {
        return 0;
    }

    return 1;
}

bool Game::stepLeft(Field& field, Figure& figure){
    int numberOfEmptyCells = 0;
    for (int i = 0; i < 4; i++) {
        if (!field.matrix[figure.arrayCellY[i] + 1][figure.arrayCellX[i]].state){
            numberOfEmptyCells++;
        }
    }
    if (numberOfEmptyCells == 4) {
        for (int i = 0; i < 4; i++) {
            field.matrix[figure.arrayCellY[i] + 1][figure.arrayCellX[i]].state = 1;
            field.matrix[figure.arrayCellY[i] + 1][figure.arrayCellX[i]].color = field.matrix[figure.arrayCellY[i]][figure.arrayCellX[i]].color;
            field.matrix[figure.arrayCellY[i]][figure.arrayCellX[i]].state = 0;
            figure.arrayCellY[i]++;
        }
    } else {
        return 0;
    }

    return 1;
}
