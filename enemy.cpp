#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>

Enemy::Enemy(){
    //set random position along the top platform edge
    setPos((rand() % 557) + 100, 0);

    //set image to the abstract enemy object
    setPixmap(QPixmap(":/Images/enemy.png"));

    //connects a timer with the move function to create a moving enemy
    QTimer* timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(45);
}

void Enemy::move()
{
    //if ()
    //moves enemy down
    setPos(x(), y() + 5);
    //when bottom of enemy reaches the bottom coordinate, 600, it gets removed from scene and then deleted
    if (y() > 600){
        scene()->removeItem(this);
        delete this;
    }
}

