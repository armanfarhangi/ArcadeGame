//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#include "enemy_beam.h"
#include <QTimer>
#include <QGraphicsScene>
#include "player.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "game.h"
#include <QObject>
#include <QApplication>
#include <QList>
#include <QGraphicsPixmapItem>


EnemyBeam::EnemyBeam(int direction, Game* param_game)
{
    game = param_game;

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
    //if the beam collides with player, then destroy both player and enemy and open window that says you've died
    //this list holds all the items that the beam collides with
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
        if (typeid(*(colliding_items[i])) == typeid(Player)){ //if type of colliding_items[i] is Player
            QGraphicsPixmapItem* tombstone = new QGraphicsPixmapItem(QPixmap(":/Images/tombstone.png"));
            tombstone->setPos(colliding_items[i]->x(), colliding_items[i]->y());
            scene()->removeItem(game->player->shoot_ready);
            scene()->removeItem(game->player->shield_ready);
            scene()->addItem(tombstone);
            scene()->removeItem(colliding_items[i]); //remove Player
            scene()->removeItem(this); //remove beam
            //memory management (don't delete Player or else glitch)
            delete this;

            //game over menu
            game->game_over();

            //important to return so that the beam that's been deleted doesn't try to move in the code below
            return;
        }

    //moves beam down (slower than player beams)
    setPos(x(), y() + 4);
    //when bullet reaches past view, it gets removed and deleted
    if (y() > 660){
        scene()->removeItem(this);
        delete this;
    }
}

void EnemyBeam::move_up(){
    //if the beam collides with player, then destroy both player and enemy and open window that says you've died
    //this list holds all the items that the beam collides with
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
        if (typeid(*(colliding_items[i])) == typeid(Player)){ //if type of colliding_items[i] is Player
            QGraphicsPixmapItem* tombstone = new QGraphicsPixmapItem(QPixmap(":/Images/tombstone.png"));
            tombstone->setPos(colliding_items[i]->x(), colliding_items[i]->y());
            scene()->removeItem(game->player->shoot_ready);
            scene()->removeItem(game->player->shield_ready);
            scene()->addItem(tombstone);
            scene()->removeItem(colliding_items[i]); //remove Player
            scene()->removeItem(this); //remove Player
            //memory management (don't delete Player or else glitch)
            delete this;

            //game over menu
            game->game_over();

            //important to return so that the beam that's been deleted doesn't try to move in the code below
            return;
        }
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
    //if the beam collides with player, then destroy both player and enemy and open window that says you've died
    //this list holds all the items that the beam collides with
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
        if (typeid(*(colliding_items[i])) == typeid(Player)){ //if type of colliding_items[i] is Player
            QGraphicsPixmapItem* tombstone = new QGraphicsPixmapItem(QPixmap(":/Images/tombstone.png"));
            tombstone->setPos(colliding_items[i]->x(), colliding_items[i]->y());
            scene()->removeItem(game->player->shoot_ready);
            scene()->removeItem(game->player->shield_ready);
            scene()->addItem(tombstone);
            scene()->removeItem(colliding_items[i]); //remove Player
            scene()->removeItem(this); //remove Player
            //memory management (don't delete Player or else glitch)
            delete this;

            //game over menu
            game->game_over();

            //important to return so that the beam that's been deleted doesn't try to move in the code below
            return;
        }
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
    //if the beam collides with player, then destroy both player and enemy and open window that says you've died
    //this list holds all the items that the beam collides with
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
        if (typeid(*(colliding_items[i])) == typeid(Player)){ //if type of colliding_items[i] is Player
            QGraphicsPixmapItem* tombstone = new QGraphicsPixmapItem(QPixmap(":/Images/tombstone.png"));
            tombstone->setPos(colliding_items[i]->x(), colliding_items[i]->y());
            scene()->removeItem(game->player->shoot_ready);
            scene()->removeItem(game->player->shield_ready);
            scene()->addItem(tombstone);
            scene()->removeItem(colliding_items[i]); //remove Player
            scene()->removeItem(this); //remove Beam
            //memory management (don't delete Player or else glitch)
            delete this;

            //game over menu
            game->game_over();

            //important to return so that the beam that's been deleted doesn't try to move in the code below
            return;
        }
    //moves beam down (slower than player beams)
    setPos(x() - 4, y());
    //when bullet reaches end of view, it gets removed and deleted
    if (x() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
