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
        //moves bullet down
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
