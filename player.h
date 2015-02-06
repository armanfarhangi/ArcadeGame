#ifndef PLAYER
#define PLAYER

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

#endif // PLAYER

