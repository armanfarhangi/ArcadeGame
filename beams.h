#ifndef BEAM
#define BEAM

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

//inherited from QGraphicsRectItem so it has coordinates, length, and width
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

