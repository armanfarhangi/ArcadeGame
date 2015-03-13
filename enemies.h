//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#ifndef ENEMY
#define ENEMY

#include <QObject>
#include <QGraphicsPixmapItem>
#include "player.h"
#include "game.h"

/**
 * @brief Enemy that only changes x-coordinates (top and bottom)
 */
class XEnemy : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    XEnemy(Player* player, int y_coor, Game* param_game);
    void move_and_shoot_down();
    void move_and_shoot_up();
public slots:
    void set_coor();
    void randomize();
    void move_and_shoot();
private:
    bool direction;
    int speed;
    Player* target;
    int target_x;
    int target_y;
    Game* game;
};

/**
 * @brief Enemy that only changes on y-coordinates (left and right)
 */
class YEnemy : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    YEnemy(Player* player, int x_coor, Game* param_game);
    void move_and_shoot_right();
    void move_and_shoot_left();
public slots:
    void set_coor();
    void randomize();
    void move_and_shoot();
private:
    bool direction;
    int speed;
    Player* target;
    int target_x;
    int target_y;
    Game* game;
};

#endif // ENEMY

