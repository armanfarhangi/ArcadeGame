//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#ifndef PLAYER
#define PLAYER

#include <QGraphicsPixmapItem>

class Player : public QGraphicsPixmapItem {
public:
    void keyPressEvent(QKeyEvent* event);
    Player();
};

#endif // PLAYER

