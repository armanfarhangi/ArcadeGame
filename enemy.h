#ifndef ENEMY
#define ENEMY

#include <QObject>
#include <QGraphicsPixmapItem>

//inherited from QObject so it can connect
//need to put in Q_OBJECT, a macro that allows for connecting signals and slots
class Enemy : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy();
public slots:
    void move();
};

#endif // ENEMY

