#ifndef PLAYER
#define PLAYER

#include <QGraphicsPixmapItem>

class Player : public QGraphicsPixmapItem {
public:
    void keyPressEvent(QKeyEvent* event);
    Player();
};

#endif // PLAYER

