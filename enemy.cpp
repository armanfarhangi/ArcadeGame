#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>

Enemy::Enemy(){
    //set random position along the top platform edge
    setPos((rand() % 557) + 100, -10);

    //to determine what random direction enemy will start in (1 right, 0 left)
    direction = rand() % 2;

    //set image to the abstract enemy object
    setPixmap(QPixmap(":/Images/enemy.png"));

    //connects a timer with the move function to create a moving enemy
    QTimer* timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(45);
}

void Enemy::move()
{
    //as long as enemy doesn't move past the right of top platform edge, then it moves right
    if (direction == 1)
        setPos(x() + 3, y());
        if (x() > 595)
            direction = 0;
    //as long as enemy doesn't move past the left of top platform edge, then it moves left
    if (direction == 0)
        setPos(x() - 3, y());
        if (x() < 120)
            direction = 1;
}

