//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#ifndef ENEMY
#define ENEMY

#include <QObject>
#include <QGraphicsPixmapItem>
#include "player.h"

//inherited from QObject so it can connect
//need to put in Q_OBJECT, a macro that allows for connecting signals and slots
class Enemy : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy(Player* player);
public slots:
    void set_coor();
    void move_and_shoot();
    void randomize();
private:
    bool direction;
    int speed;
    Player* target;
    int target_x;
    int target_y;
};

#endif // ENEMY

