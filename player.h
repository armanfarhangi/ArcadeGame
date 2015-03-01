//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#ifndef PLAYER
#define PLAYER

#include <QGraphicsPixmapItem>
#include <QObject>

class Player : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent *event);
    Player(int value);
    int character;
    bool cooldown;
    bool left;
    bool right;
    bool up;
    bool down;
    bool space;
public slots:
    void cooled_down();
    void check_keys();
};

#endif // PLAYER

