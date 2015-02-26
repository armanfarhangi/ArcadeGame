//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#ifndef ENEMY_BEAM
#define ENEMY_BEAM

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

//inherited from QObject so it can connect
//need to put in Q_OBJECT, a macro that allows for connecting signals and slots
class EnemyBeam : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    EnemyBeam();
public slots:
    void move_and_defeat();
};

#endif // ENEMY_BEAM

