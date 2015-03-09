//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#ifndef PLAYER
#define PLAYER

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Player : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent *event);
    Player(int value);
    int character;
    QTimer* shoot_timer;
    bool cooldown;
    bool left;
    bool right;
    bool up;
    bool down;
    bool space;
    void shoot(int value);
public slots:
    void cooled_down();
    void check_keys();
};

class Shield : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Shield(Player* player);
    Player* character;
public slots:
    void follow();
    void stop();
};

#endif // PLAYER

