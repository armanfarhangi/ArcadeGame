//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#include "powerups.h"
#include "QGraphicsPixmapItem"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>


/**
 * @brief creates speed power up
 * @param game_arg: used to update game if speed power up is on battle screen
 */
SpeedUp::SpeedUp(Game* game_arg)
{
    has_died = 0;

    game = game_arg;
    game->speed_out = 1;
    setPixmap(QPixmap(":/Images/speed.png"));
    setPos(rand() % (570 - 130) + 130, rand() % (520 - 80) + 80);
    QTimer* duration = new QTimer;
    connect(duration, SIGNAL(timeout()), this, SLOT(begone()));
    duration->start(5000);

    QTimer* check_life_timer = new QTimer;
    connect(check_life_timer, SIGNAL(timeout()), this, SLOT(check_player()));
    check_life_timer->start(1);
}

/**
 * @brief rids of speed power up
 */
void SpeedUp::begone()
{
    if (!has_died)
        game->speed_out = 0;
    game->powerup_speed_timer->start(20000);
    scene()->removeItem(this);
    delete this;
}

/**
 * @brief checks if player is dead (so multiple power ups don't spawn on restart)
 */
void SpeedUp::check_player()
{
    if (game->player_dead)
        has_died = 1;
}

/**
 * @brief creates burstfire power up
 * @param game_arg: used to update game if burst power up is on battle screen
 */
Burst::Burst(Game* game_arg)
{
    game = game_arg;
    game->burst_out = 1;
    setPixmap(QPixmap(":/Images/burst.png"));
    setPos(rand() % (570 - 130) + 130, rand() % (520 - 80) + 80);
    QTimer* duration = new QTimer;
    connect(duration, SIGNAL(timeout()), this, SLOT(begone()));
    duration->start(5000);

    QTimer* check_life_timer = new QTimer;
    connect(check_life_timer, SIGNAL(timeout()), this, SLOT(check_player()));
    check_life_timer->start(1);
}

/**
 * @brief rids of burst power up
 */
void Burst::begone()
{
    if (!has_died)
        game->burst_out = 0;
    game->powerup_burst_timer->start(20000);
    scene()->removeItem(this);
    delete this;
}

/**
 * @brief checks if player is dead (so multiple power ups don't spawn on restart)
 */
void Burst::check_player()
{
    if (game->player_dead)
        has_died = 1;
}
