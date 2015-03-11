#include "powerups.h"
#include "QGraphicsPixmapItem"
#include "player.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>



SpeedUp::SpeedUp(Player* player_arg)
{
    player = player_arg;
    player->speed_out = 1;
    setPixmap(QPixmap(":/Images/speed.png"));
    setPos(rand() % (570 - 130) + 130, rand() % (520 - 80) + 80);
    QTimer* duration = new QTimer;
    connect(duration, SIGNAL(timeout()), this, SLOT(begone()));
    duration->start(8000);
}

void SpeedUp::begone()
{
    player->speed_out = 0;
    scene()->removeItem(this);
    delete this;
}


Burst::Burst(Player* player_arg)
{
    player = player_arg;
    player->burst_out = 1;
    setPixmap(QPixmap(":/Images/burst.png"));
    setPos(rand() % (570 - 130) + 130, rand() % (520 - 80) + 80);
    QTimer* duration = new QTimer;
    connect(duration, SIGNAL(timeout()), this, SLOT(begone()));
    duration->start(8000);
}

void Burst::begone()
{
    player->burst_out = 0;
    scene()->removeItem(this);
    delete this;
}
