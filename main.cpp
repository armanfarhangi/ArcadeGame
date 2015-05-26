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

    return a.exec();
}
