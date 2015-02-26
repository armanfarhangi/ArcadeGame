//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#ifndef BEAM
#define BEAM

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

//inherited from QObject so it can connect
//need to put in Q_OBJECT, a macro that allows for connecting signals and slots
class Beam : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Beam();
public slots:
    void move_and_destroy();
};

#endif // BEAM

