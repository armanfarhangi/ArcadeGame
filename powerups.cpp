#include "powerups.h"
#include "QGraphicsPixmapItem"
#include "game.h"
#include <QTimer>



SpeedUp::SpeedUp(Game* game_arg)
{
    game = game_arg;
    game->speed_out = 1;
    setPixmap(QPixmap(":/Images/speed.png"));
    setPos(rand() % (570 - 130) + 130, rand() % (520 - 80) + 80);
    QTimer* duration = new QTimer;
    connect(duration, SIGNAL(timeout()), this, SLOT(begone()));
    duration->start(8000);
}

void SpeedUp::begone()
{
    game->speed_out = 0;
    scene()->removeItem(this);
    delete this;
}


Burst::Burst(Game* game_arg)
{
    game = game_arg;
    game->burst_out = 1;
    setPixmap(QPixmap(":/Images/burst.png"));
    setPos(rand() % (570 - 130) + 130, rand() % (520 - 80) + 80);
    QTimer* duration = new QTimer;
    connect(duration, SIGNAL(timeout()), this, SLOT(begone()));
    duration->start(8000);
}

void Burst::begone()
{
    game->burst_out = 0;
    scene()->removeItem(this);
    delete this;
}
