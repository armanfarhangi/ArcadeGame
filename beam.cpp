//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#include "beam.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemies.h"

Beam::Beam(int value){
    //creates a beam//sets direction: 1 up 2 down 3 left 4 right
    direction = value;

    if (value == 1 || value == 2)
        setPixmap(QPixmap(":/Images/up_down.png"));
    else if (value == 3 || value == 4)
        setPixmap(QPixmap(":/Images/left_right.png"));

    //connects a timer with the move function to create a moving beam
    QTimer* timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(move_and_destroy()));
    timer->start(40);
}


void Beam::move_and_destroy()
{
    //if the beam collides with an enemy, then destroy both beam and enemy
    //this list holds all the items that the beam collides with
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
        if (typeid(*(colliding_items[i])) == typeid(XEnemy)
        || typeid(*(colliding_items[i])) == typeid(YEnemy)){ //if type of colliding_items[i] is Enemy
            scene()->removeItem(colliding_items[i]); //remove Enemy
            scene()->removeItem(this); //remove beam
            //memory management
            delete colliding_items[i];
            delete this;
            //important to return so that the beam that's been deleted doesn't try to move in the code below
            return;
        }

    if (direction == 1){
        //moves bullet up
        setPos(x(), y() - 6);
        //when bullet reaches end of view, it gets removed and deleted
        if (y() < -50){
            scene()->removeItem(this);
            delete this;
        }
    }
    else if (direction == 2){
        //moves bullet up
        setPos(x(), y() + 6);
        //when bullet reaches end of view, it gets removed and deleted
        if (y() > 660){
            scene()->removeItem(this);
            delete this;
        }
    }
    else if (direction == 3){
        //moves bullet left
        setPos(x() - 6, y());
        //when bullet reaches end of view, it gets removed and deleted
        if (x() < 0){
            scene()->removeItem(this);
            delete this;
        }
    }
    else if (direction == 4){
        //moves bullet right
        setPos(x() + 6, y());
        //when bullet reaches end of view, it gets removed and deleted
        if (x() > 670){
            scene()->removeItem(this);
            delete this;
        }
    }
}
