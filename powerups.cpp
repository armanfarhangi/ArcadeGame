#include "powerups.h"
#include "QGraphicsPixmapItem"
#include "game.h"




SpeedUp::SpeedUp(Game* game_arg)
{
    game = game_arg;
    setPixmap(QPixmap(":/Images/speed.png"));
    setPos(rand() % (570 - 130) + 130, rand() % (520 - 80) + 80);
}


Burst::Burst(Game* game_arg)
{
    game = game_arg;
    setPixmap(QPixmap(":/Images/burst.png"));
    setPos(rand() % (570 - 130) + 130, rand() % (520 - 80) + 80);
}
