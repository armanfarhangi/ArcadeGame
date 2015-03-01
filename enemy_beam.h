//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#ifndef ENEMY_BEAM
#define ENEMY_BEAM

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include "game.h"

//inherited from QObject so it can connect
//need to put in Q_OBJECT, a macro that allows for connecting signals and slots
class EnemyBeam : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    EnemyBeam(int direction, Game* param_game);
    void game_over();
public slots:
    void move_down();
    void move_up();
    void move_right();
    void move_left();
private:
    Game* game;
};

#endif // ENEMY_BEAM

