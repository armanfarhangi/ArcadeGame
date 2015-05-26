//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#ifndef BEAM
#define BEAM

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

/**
 * @brief Player beam that spawns when player hits space bar
 */
class Beam : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Beam(int value);
    int direction;
public slots:
    void move();
};

#endif // BEAM

