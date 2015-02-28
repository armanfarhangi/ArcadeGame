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
    if (direction == 1 || direction == 2)
        setPixmap(QPixmap(":/Images/enemy_up_down.png"));
    else
        setPixmap(QPixmap(":/Images/enemy_left_right.png"));

    //connects a timer with the move function to create a moving beam
    QTimer* timer = new QTimer;

    //if 1 was passed, then the beam comes from a top row enemy, so beam shoots down
    if (direction == 1){
        connect(timer, SIGNAL(timeout()), this, SLOT(move_down()));
        timer->start(40);
    }
    //if 2 was passed, then the beam comes from bottom row enemy, so beam shoots down
    else if (direction == 2){
        connect(timer, SIGNAL(timeout()), this, SLOT(move_up()));
        timer->start(40);
    }

    //if 3 was passed, beam comes from left enemy, so beam shoots right
    else if (direction == 3){
        connect(timer, SIGNAL(timeout()), this, SLOT(move_right()));
        timer->start(40);
    }

    else {
        connect(timer, SIGNAL(timeout()), this, SLOT(move_left()));
        timer->start(40);
    }
}

void EnemyBeam::move_down(){
    //moves beam down (slower than player beams)
    setPos(x(), y() + 4);
    //when bullet reaches past view, it gets removed and deleted
    if (y() > 660){
        scene()->removeItem(this);
        delete this;
    }
}

void EnemyBeam::move_up(){
    //moves beam down (slower than player beams)
    setPos(x(), y() - 4);
    //when bullet reaches past view, it gets removed and deleted
    if (y() < -50){
        scene()->removeItem(this);
        delete this;
    }
}

void EnemyBeam::move_right()
{
    //moves beam down (slower than player beams)
    setPos(x() + 4, y());
    //when bullet reaches end of view, it gets removed and deleted
    if (x() > 670){
        scene()->removeItem(this);
        delete this;
    }
}

void EnemyBeam::move_left()
{
    //moves beam down (slower than player beams)
    setPos(x() - 4, y());
    //when bullet reaches end of view, it gets removed and deleted
    if (x() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
