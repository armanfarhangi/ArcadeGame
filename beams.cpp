#include "beams.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "characters.h"

Beam::Beam(){
    //creates a beam
    setPixmap(QPixmap(":/Images/up_beam.png"));

    //connects a timer with the move function to create a moving beam
    QTimer* timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(move_and_destroy()));
    timer->start(50);
}


void Beam::move_and_destroy()
{
    //if the beam collides with an enemy, then destroy both beam and enemy
    //this list holds all the items that the beam collides with
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){ //if type of colliding_items[i] is Enemy
            scene()->removeItem(colliding_items[i]); //remove Enemy
            scene()->removeItem(this); //remove beam
            //memory management
            delete colliding_items[i];
            delete this;
            //important to return so that the beam that's been deleted doesn't try to move in the code below
            return;
        }


    //moves bullet up
    setPos(x(), y() - 10);
    //when bullet reaches end of view, it gets removed and deleted
    if (pos().y() < - 40){
        scene()->removeItem(this);
        delete this;
    }
}
