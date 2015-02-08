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
    void move();
private:
    bool direction;
    int speed;
    int player_x;
    int player_y;
};

#endif // ENEMY

