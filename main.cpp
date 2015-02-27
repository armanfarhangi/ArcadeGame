//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#include <QApplication>
#include <player.h>
#include <game.h>
#include "mainmenu.h"
#include <ctime>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //set random seed so rand() returns a different random number for spawn coordinates on each program run
    srand(time(NULL));

    //create and show menu window
    MainMenu* menu = new MainMenu;
    menu->show();

    //when BATTLE! is clicked, the menu window is closed and the game window is created and shown
    QApplication::connect(menu->battle, SIGNAL(clicked()), menu, SLOT(close()));
    QApplication::connect(menu->battle, SIGNAL(clicked()), menu, SLOT(new_game()));

    return a.exec();
}
