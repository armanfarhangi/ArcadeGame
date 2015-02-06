#ifndef CHARACTERS
#define CHARACTERS

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

//inherited from QGraphicsRectItem so it has coordinates, length, and width
class Player : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent* event);
    Player();
public slots:
    //spawning enemies can't be a member function of Enemy; unelegant but it works
    void spawn();
};


//inherited from QGraphicsRectItem so it has coordinates, length, and width
//inherited from QObject so it can connect
//need to put in Q_OBJECT, a macro that allows for connecting signals and slots
class Enemy : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy();
public slots:
    void move();
};

#endif // CHARACTERS

