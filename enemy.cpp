//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include "enemy_beam.h"
#include <cmath>

Enemy::Enemy(Player* player){
    target = player;

    //constantly store player's coordinates
    QTimer* coor_timer = new QTimer;
    connect(coor_timer, SIGNAL(timeout()), this, SLOT(set_coor()));
    coor_timer->start(40);

    //to make enemy movement less predictable; every 3 - 5 seconds, 50% chance of changing direction
    QTimer* timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(randomize()));
    timer->start((rand() % 3001) + 2000);

    //set random position along the top platform edge
    setPos((rand() % 557) + 100, -10);

    //to determine what random direction enemy will start in (1 right, 0 left)
    direction = rand() % 2;

    //to determine the speed of the enemy (3 - 5 pixel movements every 40 ms)
    speed = (rand() % 3) + 3;

    //set image to the abstract enemy object
    setPixmap(QPixmap(":/Images/enemy.png"));

    //connects a timer with the move function to create a moving enemy
    QTimer* moving_timer = new QTimer;
    connect(moving_timer, SIGNAL(timeout()), this, SLOT(move_and_shoot()));
    moving_timer->start(40);
}

void Enemy::set_coor(){
    // +25 so that they should at player's center instead of default left side
    target_x = target->x() + 25;
    target_y = target->y();
}

void Enemy::move_and_shoot()
{
    //if enemy is on-line with player (give or take 8 units), then they shoot down
    if (abs(x()-target_x) <= 8){
        EnemyBeam* beam = new EnemyBeam;
        beam->setPos(x() + 10, y());
        scene()->addItem(beam);
    }

    //as long as enemy doesn't move past the right of top platform edge, then it moves right
    if (direction == 1)
        setPos(x() + speed, y());
        if (x() > 595)
            direction = 0;
    //as long as enemy doesn't move past the left of top platform edge, then it moves left
    if (direction == 0)
        setPos(x() - speed, y());
        if (x() < 120)
            direction = 1;
}

void Enemy::randomize()
{
    //50% chance; if it was 0, changes to 1; if it was 1, changes to 0
    if (rand() % 2 == 0)
    direction = (direction + 1) % 2;
}

