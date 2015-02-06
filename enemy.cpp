#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>

Enemy::Enemy(){
    //set random position along the top coordinate
    int random_number = rand() % 700; //700 instead of 800 because enemies have 100 width
    setPos(random_number, 0);

    //creates an enemy
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
    if (pos().y() > 600){
        scene()->removeItem(this);
        delete this;
    }
}

