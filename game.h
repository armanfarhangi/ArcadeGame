//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#ifndef GAME
#define GAME

#include <QGraphicsView>

//the game window after the main menu
//inherits from QGraphics
class Game : public QGraphicsView {
public:
    Game(QWidget* parent = 0); //this means that this object will have no parent
};

#endif // GAME

