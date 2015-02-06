#include "characters.h"
#include <QKeyEvent>
#include "beams.h"
#include <QGraphicsScene>
#include "stdlib.h"
#include <QTimer>
#include <QPixmap>


/********************  GOKU  ********************/

Player::Player()
{
    //creates Goku
        setPixmap(QPixmap(":/Images/goku_stand.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
    //able to move left as long as top left of Goku is right of platform edge
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 90)
            setPos(x() - 10, y());
    }
    //able to move right as long as top left of goku is left of platform edge
    else if (event->key() == Qt::Key_Right){
        if (pos().x()  < 570)
            setPos(x() + 10, y());
    }
    //able to move up as long as goku is under top platform edge
    else if (event->key() == Qt::Key_Up){ //-10 to go up because y axis is inverted
        if (pos().y() > 50)
        setPos(x(), y() - 10);
    }
    //able to move down as long as goku is above bottom platform edge
    else if (event->key() == Qt::Key_Down){//same reason for down being +10
        if (pos().y() < 510)
            setPos(x(), y() + 10);
    }
    else if (event->key() == Qt::Key_Space){
        //create beam and include it to Goku's scene
        Beam* beam = new Beam;
        beam->setPos(x() + 30, y());
        scene()->addItem(beam);
    }
}

void Player::spawn()
{
    //create an enemy
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}

/********************  ENEMY  ********************/

Enemy::Enemy(){
    //set random position along the top coordinate
    int random_number = rand() % 700; //700 instead of 800 because enemies have 100 width
    setPos(random_number, 0);

    //creates an enemy
    setPixmap(QPixmap(":/Images/enemy.png"));

    //connects a timer with the move function to create a moving enemy
    QTimer* timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
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
