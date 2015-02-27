//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#include <QApplication>
#include <player.h>
#include "game.h"
#include <ctime>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //set random seed so rand() returns a different random number for spawn coordinates on each program run
    srand(time(NULL));

    //create and show menu window
    Game* game = new Game;
    game->show();

    //when BATTLE! is clicked, the menu window is closed and the game window is created and shown
    QApplication::connect(game->battle, SIGNAL(clicked()), game, SLOT(close()));
    QApplication::connect(game->battle, SIGNAL(clicked()), game, SLOT(start_battle()));

    return a.exec();
}
