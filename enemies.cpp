//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#include "enemies.h"
#include <QTimer>
#include <QGraphicsScene>
#include "enemy_beam.h"
#include <cmath>
#include "player.h"
#include "game.h"
#include "beam.h"

/**
 * @brief creates an x-coordinate moving enemy that can access player and game members
 * @param player: used to access player coordinates to target
 * @param y_coor: sets y-coordinate to spawn at (either top grassy area or bottom)
 * @param param_game: used to let game know when enemy dies (for win screen)
 */
XEnemy::XEnemy(Player* player, int y_coor, Game* param_game){
    //in order to
    target = player;
    game = param_game;

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

/**
 * @brief sets player coordinates (set to timer)
 */
void XEnemy::set_coor(){
    target_x = target->x() + 10;
    target_y = target->y();
}

/**
 * @brief chance of changing direction (set to timer)
 */
void XEnemy::randomize()
{
    //50% chance; if it was 0, changes to 1; if it was 1, changes to 0
    if (rand() % 2 == 0)
        direction = (direction + 1) % 2;
}

/**
 * @brief decides whether to moveand shoot down or up depending on y-coordinate
 */
void XEnemy::move_and_shoot()
{
    //depending on the edge enemy is on, they will shoot in a certain direction
    if (y() == -10) move_and_shoot_down();
    else move_and_shoot_up();
}

/**
 * @brief moves left and right and creates a down beam when x-coordinate matches with player
 */
void XEnemy::move_and_shoot_down()
{
    //if enemy gets hit by beam, then destroy both enemy and beam
    //this list holds all the items that the beam collides with
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
        if (typeid(*(colliding_items[i])) == typeid(Beam)){ //if type of colliding_items[i] is Enemy
            --game->enemy_count;
            scene()->removeItem(colliding_items[i]); //remove Beam
            scene()->removeItem(this); //remove Enemy
            //memory management
            delete colliding_items[i];
            delete this;
            //important to return so that the beam that's been deleted doesn't use code below
            return;
        }

    //if enemy is on-line with player (give or take 8 units), then they shoot down
    if (abs(x()-target_x) <= 8){
        //1 is used to later allow beam know to move down
        EnemyBeam* beam = new EnemyBeam(1, game);
        beam->setPos(x() + 10, y());
        scene()->addItem(beam);
    }

    //as long as enemy doesn't move past the right of top platform edge, then it moves right
    if (direction == 1)
        setPos(x() + speed, y());
        if (x() > 615)
            direction = 0;
    //as long as enemy doesn't move past the left of top platform edge, then it moves left
    if (direction == 0)
        setPos(x() - speed, y());
        if (x() < 100)
            direction = 1;
}

/**
 * @brief moves left and right and creates an up beam when x-coordinate matches with player
 */
void XEnemy::move_and_shoot_up()
{
    //if enemy gets hit by beam, then destroy both enemy and beam
    //this list holds all the items that the beam collides with
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
        if (typeid(*(colliding_items[i])) == typeid(Beam)){ //if type of colliding_items[i] is Enemy
            --game->enemy_count;
            scene()->removeItem(colliding_items[i]); //remove Beam
            scene()->removeItem(this); //remove Enemy
            //memory management
            delete colliding_items[i];
            delete this;
            //important to return so that the beam that's been deleted doesn't use code below
            return;
        }

    //if enemy is on-line with player (give or take 8 units), then they shoot up
    if (abs(x()-target_x) <= 8){
        //2 is used to later let beam know the beam should move up
        EnemyBeam* beam = new EnemyBeam(2, game);
        beam->setPos(x() + 10, y() + 20);
        scene()->addItem(beam);
    }

    //as long as enemy doesn't move past the right of top platform edge, then it moves right
    if (direction == 1)
        setPos(x() + speed, y());
        if (x() > 615)
            direction = 0;
    //as long as enemy doesn't move past the left of top platform edge, then it moves left
    if (direction == 0)
        setPos(x() - speed, y());
        if (x() < 100)
            direction = 1;
}

/**
 * @brief creates a y-coordinate moving enemy that can access player and game members
 * @param player: used to access player coordinates to target
 * @param x_coor: sets x-coordinate to spawn at (either left grassy area or right)
 * @param param_game: used to let game know when enemy dies (for win screen)
 */
YEnemy::YEnemy(Player* player, int x_coor, Game* param_game){
    //in order to
    target = player;
    game = param_game;

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

/**
 * @brief sets player coordinates (set to timer)
 */
void YEnemy::set_coor(){
    // +20 so that they aim at player's center instead of default top left side
    target_x = target->x();
    target_y = target->y();
}

/**
 * @brief chance of changing direction (set to timer)
 */
void YEnemy::randomize()
{
    //50% chance; if it was 0, changes to 1; if it was 1, changes to 0
    if (rand() % 2 == 0)
        direction = (direction + 1) % 2;
}

/**
 * @brief decides whether to moveand shoot down or up depending on y-coordinate
 */
void YEnemy::move_and_shoot()
{
    //depending on the edge enemy is on, they will shoot in a certain direction
    if (x() == 60) move_and_shoot_right();
    else move_and_shoot_left();
}

/**
 * @brief moves up and down and creates a right beam when y-coordinate matches with player
 */
void YEnemy::move_and_shoot_right()
{
    //if enemy gets hit by beam, then destroy both enemy and beam
    //this list holds all the items that the beam collides with
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
        if (typeid(*(colliding_items[i])) == typeid(Beam)){ //if type of colliding_items[i] is Enemy
            --game->enemy_count;
            scene()->removeItem(colliding_items[i]); //remove Beam
            scene()->removeItem(this); //remove Enemy
            //memory management
            delete colliding_items[i];
            delete this;
            //important to return so that the beam that's been deleted doesn't use code below
            return;
        }

    //if enemy is on-line with player (give or take 8 units), then they shoot right
    if (abs(y()-target_y) <= 8){
        //1 is used to later allow beam know to move down
        EnemyBeam* beam = new EnemyBeam(3, game);
        beam->setPos(x(), y() + 20);
        scene()->addItem(beam);
    }

    //if enemy moves past top edge, change direction
    if (direction == 1)
        setPos(x(), y() - speed);
        if (y() < 40)
            direction = 0;
    //if enemy moves below bottom edge, change direction
    if (direction == 0)
        setPos(x(), y() + speed);
        if (y() > 530)
            direction = 1;
}

/**
 * @brief moves up and down and creates a left beam when y-coordinate matches with player
 */
void YEnemy::move_and_shoot_left()
{
    //if enemy gets hit by beam, then destroy both enemy and beam
    //this list holds all the items that the beam collides with
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
        if (typeid(*(colliding_items[i])) == typeid(Beam)){ //if type of colliding_items[i] is Enemy
            --game->enemy_count;
            scene()->removeItem(colliding_items[i]); //remove Beam
            scene()->removeItem(this); //remove Enemy
            //memory management
            delete colliding_items[i];
            delete this;
            //important to return so that the beam that's been deleted doesn't use code below
            return;
        }

    //if enemy is on-line with player (give or take 8 units), then they shoot left
    if (abs(y()-target_y) <= 8){
        //1 is used to later allow beam know to move down
        EnemyBeam* beam = new EnemyBeam(4, game);
        beam->setPos(x(), y() + 20);
        scene()->addItem(beam);
    }

    //if enemy moves past top edge, change direction
    if (direction == 1)
        setPos(x(), y() - speed);
        if (y() < 40)
            direction = 0;
    //if enemy moves past bottom edge, change direction
    if (direction == 0)
        setPos(x(), y() + speed);
        if (y() > 530)
            direction = 1;
}
