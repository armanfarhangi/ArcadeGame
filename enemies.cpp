//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#include "enemies.h"
#include <QTimer>
#include <QGraphicsScene>
#include "enemy_beam.h"
#include <cmath>

XEnemy::XEnemy(Player* player, int y_coor){
    //in order to
    target = player;

    //constantly store player's coordinates
    QTimer* coor_timer = new QTimer;
    connect(coor_timer, SIGNAL(timeout()), this, SLOT(set_coor()));
    coor_timer->start(40);

    //to make enemy movement less predictable; every 2 - 5 seconds, 50% chance of changing direction
    QTimer* timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(randomize()));
    timer->start((rand() % 3001) + 2000);

    //set random position along platform edge
    setPos((rand() % 557) + 100, y_coor);

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

void XEnemy::set_coor(){
    // +25 so that they aim at player's center instead of default left side
    target_x = target->x() + 25;
    target_y = target->y();
}

void XEnemy::randomize()
{
    //50% chance; if it was 0, changes to 1; if it was 1, changes to 0
    if (rand() % 2 == 0)
        direction = (direction + 1) % 2;
}

void XEnemy::move_and_shoot()
{
    //depending on the edge enemy is on, they will shoot in a certain direction
    if (y() == -10) move_and_shoot_down();
    else move_and_shoot_up();
}

void XEnemy::move_and_shoot_down()
{
    //if enemy is on-line with player (give or take 8 units), then they shoot down
    if (abs(x()-target_x) <= 8){
        //1 is used to later allow beam know to move down
        EnemyBeam* beam = new EnemyBeam(1);
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

void XEnemy::move_and_shoot_up()
{
    //if enemy is on-line with player (give or take 8 units), then they shoot up
    if (abs(x()-target_x) <= 8){
        //2 is used to later let beam know the beam should move up
        EnemyBeam* beam = new EnemyBeam(2);
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

YEnemy::YEnemy(Player* player, int x_coor){
    //in order to
    target = player;

    //constantly store player's coordinates
    QTimer* coor_timer = new QTimer;
    connect(coor_timer, SIGNAL(timeout()), this, SLOT(set_coor()));
    coor_timer->start(40);

    //to make enemy movement less predictable; every 2 - 5 seconds, 50% chance of changing direction
    QTimer* timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(randomize()));
    timer->start((rand() % 3001) + 2000);

    //set random position along left and right platform edges
    setPos(x_coor, (rand() % 390) + 150);

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

void YEnemy::set_coor(){
    // +25 so that they aim at player's center instead of default left side
    target_x = target->x() + 25;
    target_y = target->y();
}

void YEnemy::randomize()
{
    //50% chance; if it was 0, changes to 1; if it was 1, changes to 0
    if (rand() % 2 == 0)
        direction = (direction + 1) % 2;
}

void YEnemy::move_and_shoot()
{
    //depending on the edge enemy is on, they will shoot in a certain direction
    if (x() == 80) move_and_shoot_right();
    else move_and_shoot_left();
}

void YEnemy::move_and_shoot_right()
{
    //if enemy is on-line with player (give or take 8 units), then they shoot right
    if (abs(y()-target_y) <= 8){
        //1 is used to later allow beam know to move down
        EnemyBeam* beam = new EnemyBeam(3);
        beam->setPos(x() + 10, y());
        scene()->addItem(beam);
    }

    //if enemy moves past top edge, change direction
    if (direction == 1)
        setPos(x(), y() - speed);
        if (y() < 60)
            direction = 0;
    //if enemy moves below bottom edge, change direction
    if (direction == 0)
        setPos(x(), y() + speed);
        if (y() > 510)
            direction = 1;
}

void YEnemy::move_and_shoot_left()
{
    //if enemy is on-line with player (give or take 8 units), then they shoot left
    if (abs(y()-target_y) <= 8){
        //1 is used to later allow beam know to move down
        EnemyBeam* beam = new EnemyBeam(4);
        beam->setPos(x() + 10, y());
        scene()->addItem(beam);
    }

    //if enemy moves past top edge, change direction
    if (direction == 1)
        setPos(x(), y() - speed);
        if (y() < 60)
            direction = 0;
    //if enemy moves past bottom edge, change direction
    if (direction == 0)
        setPos(x(), y() + speed);
        if (y() > 510)
            direction = 1;
}
