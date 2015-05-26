//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#ifndef POWERUPS
#define POWERUPS

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include "game.h"
#include <QTimer>

/**
 * @brief Powerup that raises speed of player
 */
class SpeedUp : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    SpeedUp(Game* game_arg);
    Game* game;
    bool has_died;
public slots:
    void begone();
    void check_player();
};

/**
 * @brief Powerup that eliminates cooldown of player shot
 */
class Burst : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Burst(Game* game_arg);
    Game* game;
    bool has_died;
public slots:
    void begone();
    void check_player();

};

#endif // POWERUPS

