//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#include <QApplication>
#include <characters.h>
#include <game.h>
#include "mainmenu.h"
#include <ctime>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //set random seed so rand() returns a different random number for spawn coordinates
    srand(time(NULL));

    //create and show menu window
    MainMenu* menu = new MainMenu;
    menu->show();

    //create game window
    Game* game = new Game;

    //when BATTLE! is clicked, the game window is shown and the menu window is closed
    QApplication::connect(menu->battle, SIGNAL(clicked()), game, SLOT(show()));
    QApplication::connect(menu->battle, SIGNAL(clicked()), menu, SLOT(close()));

    return a.exec();
}
