//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#include "enemy_beam.h"
#include <QTimer>
#include <QGraphicsScene>


EnemyBeam::EnemyBeam(int direction)
{
    //creates a beam
    setPixmap(QPixmap(":/Images/up_beam.png"));

    //connects a timer with the move function to create a moving beam
    QTimer* timer = new QTimer;
    if (direction == 1){
        connect(timer, SIGNAL(timeout()), this, SLOT(move_down()));
        timer->start(40);
    }
    else{
        connect(timer, SIGNAL(timeout()), this, SLOT(move_up()));
        timer->start(40);
    }
}

void EnemyBeam::move_down(){
    //moves beam down (slower than player beams)
    setPos(x(), y() + 6);
    //when bullet reaches end of view, it gets removed and deleted
    if (y() > 630){
        scene()->removeItem(this);
        delete this;
    }
}

void EnemyBeam::move_up(){
    //moves beam down (slower than player beams)
    setPos(x(), y() - 6);
    //when bullet reaches end of view, it gets removed and deleted
    if (y() < -20){
        scene()->removeItem(this);
        delete this;
    }
}
