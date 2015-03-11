#include "powerups.h"
#include "QGraphicsPixmapItem"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>



SpeedUp::SpeedUp(Game* game_arg)
{
    has_died = 0;

    game = game_arg;
    game->speed_out = 1;
    setPixmap(QPixmap(":/Images/speed.png"));
    setPos(rand() % (570 - 130) + 130, rand() % (520 - 80) + 80);
    QTimer* duration = new QTimer;
    connect(duration, SIGNAL(timeout()), this, SLOT(begone()));
    duration->start(8000);

    QTimer* check_life_timer = new QTimer;
    connect(check_life_timer, SIGNAL(timeout()), this, SLOT(check_player_life()));
    check_life_timer->start(1);
}

void SpeedUp::begone()
{
    if (!has_died)
        game->speed_out = 0;
    scene()->removeItem(this);
    delete this;
}

void SpeedUp::check_player_life()
{
    if (game->player_dead)
        has_died = 1;
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

    QTimer* check_life_timer = new QTimer;
    connect(check_life_timer, SIGNAL(timeout()), this, SLOT(check_player_life()));
    check_life_timer->start(1);
}

void Burst::begone()
{
    if (!has_died)
        game->burst_out = 0;
    scene()->removeItem(this);
    delete this;
}

void Burst::check_player_life()
{
    if (game->player_dead)
        has_died = 1;
}
