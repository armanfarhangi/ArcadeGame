//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#include "player.h"
#include <QKeyEvent>
#include "beam.h"
#include <QGraphicsScene>
#include "stdlib.h"
#include <QPixmap>
#include "enemies.h"
#include <QTimer>


Player::Player(int value)
{
    character = value;
    cooldown = true;
    left = false;
    right = false;
    up = false;
    down = false;
    space = false;

    if (value == 1){
        setPixmap(QPixmap(":/Images/hercule_stand.png"));
        //spawn position for Hercule
        this->setPos(360, 270);
    }

    else if (value == 2){
        //spawn position for Saiyaman
        setPixmap(QPixmap(":/Images/saiyaman_stand.png"));
        this->setPos(360, 270);
   }

    else {
        setPixmap(QPixmap(":/Images/goku_stand.png"));
        //set player spawn position for Goku
        this->setPos(340, 270);
    }

    //every two seconds, the player can shoot again
    shoot_timer = new QTimer;
    connect(shoot_timer, SIGNAL(timeout()), this, SLOT(cooled_down()));

    //very often check which keys have been pressed
    QTimer* smooth_timer = new QTimer;
    connect(smooth_timer, SIGNAL(timeout()), this, SLOT(check_keys()));
    smooth_timer->start(45);
}

void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        left = true;
    }
    else if (event->key() == Qt::Key_Right){
        right = true;
    }
    else if (event->key() == Qt::Key_Up){
        up = true;
    }
    else if (event->key() == Qt::Key_Down){
        down = true;
    }
    else if (event->key() == Qt::Key_Space){
        space = true;
    }
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        left = false;
    }
    else if (event->key() == Qt::Key_Right){
        right = false;
    }
    else if (event->key() == Qt::Key_Up){
        up = false;
    }
    else if (event->key() == Qt::Key_Down){
        down = false;
    }
    else if (event->key() == Qt::Key_Space){
        space = false;
    }
}

void Player::cooled_down()
{
    cooldown = true;
    shoot_timer->stop();
}

void Player::check_keys()
{
    //up-left movement
    if (left && up){
        if (x() > 90 && y() > 50)
            setPos(x() - 6, y() - 6);
    }
    //right-up movement
    else if (right && up){
        if (x() < 570 && y() > 50)
            setPos(x() + 6, y() - 6);
    }
    //left down movement
    else if (left && down){
        if (x() > 90 && y() < 510)
            setPos(x() - 6, y() + 6);
    }
    //right down movement
    else if (right & down){
        if (x() < 570 && y() < 510)
            setPos(x() + 6, y() + 6);
    }
    //able to move left as long as top left of Goku is right of platform edge
    else if (left){
        if (x() > 90)
            setPos(x() - 6, y());
    }
    //able to move right as long as top left of goku is left of platform edge
    else if (right){
        if (x() < 570)
            setPos(x() + 6, y());
    }
    //able to move up as long as goku is under top platform edge
    else if (up){ //-10 to go up because y axis is inverted
        if (y() > 50)
            setPos(x(), y() - 6);
    }
    //able to move down as long as goku is above bottom platform edge
    else if (down){//same reason for down being +10
        if (y() < 510)
            setPos(x(), y() + 6);
    }

    //SHOOTING is not a part of the movement if-tree
    //space by itself will create a shield
    if (space && !up && !down && !left && !right){
        Shield* shield = new Shield(this);
        scene()->addItem(shield);
    }
    else if (up && space)
        shoot(1);
    else if (down && space)
        shoot(2);
    else if (left && space)
        shoot(3);
    else if (right && space)
        shoot(4);
}

void Player::shoot(int value)
{
    //create beam and center it on player (coordinates depend on character selection)
    //beam only created if it's been 3 seconds since last shot
    if (cooldown == true){
        Beam* beam = new Beam(value);
        if (character == 1)
            beam->setPos(x() + 23, y() - 40);
        else if (character == 2)
            beam->setPos(x() + 23, y() - 40);
        else
            beam->setPos(x() + 40, y() - 40);
        scene()->addItem(beam);
        cooldown = false;
        shoot_timer->start(2000);
    }
}


Shield::Shield(Player* player)
{
    character = player;
    setPos(character->x(), character->y());
    setPixmap(QPixmap(":Images/shield_sprite.png"));
    QTimer* follow_timer = new QTimer;
    connect(follow_timer, SIGNAL(timeout()), this, SLOT(follow()));
    follow_timer->start(20);

    QTimer* shield_timer = new QTimer;
    connect(shield_timer, SIGNAL(timeout()), this, SLOT(stop()));
    shield_timer->start(10000);
}

void Shield::follow()
{
    setPos(character->x(), character->y());
}

void Shield::stop()
{
    scene()->removeItem(this);
    delete this;
}
