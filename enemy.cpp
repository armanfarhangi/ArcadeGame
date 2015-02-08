#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include "enemy_beam.h"

Enemy::Enemy(Player* player){
    //store player's coordinates
    player_x = player->x();
    player_y = player->y();

    //set random position along the top platform edge
    setPos((rand() % 557) + 100, -10);

    //to determine what random direction enemy will start in (1 right, 0 left)
    direction = rand() % 2;

    //to determine the speed of the enemy (2 - 5 pixel movements every 40 ms)
    speed = (rand() % 4) + 2;

    //set image to the abstract enemy object
    setPixmap(QPixmap(":/Images/enemy.png"));

    //connects a timer with the move function to create a moving enemy
    QTimer* timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(40);
}

void Enemy::move()
{
    //if enemy is on y-line with player, then they shoot down
    if (x() == player_x){
        EnemyBeam* beam = new EnemyBeam;
        beam->setPos(x(), y());
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

