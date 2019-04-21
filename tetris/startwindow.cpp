#include "startwindow.h"
#include <game.h>
#include <iostream>
#include <string.h>

using namespace std;

StartWindow::StartWindow()
{

}

void StartWindow::drawMenu(){
    string i = "";
    cout << "\n\n\t==========================================" << endl;
    cout << "\t------------------TETRIS------------------" << endl;
    cout << "\t==========================================" << endl;
    cout << "\tdeveloped by bartenev&sotchenko(IDB-18-11)" << endl;
    cout << "\n\nPress any key for start new game...";
    cin >> i;
    startNewGame();
}

void StartWindow::startNewGame(){
    Game game;
    game.newGame();
}
