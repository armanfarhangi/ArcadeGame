//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#ifndef MAINMENU
#define MAINMENU

#include <QWidget>
#include <QPushButton>
#include <QObject>
#include <QString>

//main window at beginning to select character and difficulty
class Game : public QWidget {
    Q_OBJECT
public:
    Game(QWidget* parent=0);
    //make BATTLE! button a member so you can pass it to main.cpp connect function
    int character;
    int difficulty;
public slots:
    void hercule_set();
    void saiyaman_set();
    void medium_set();
    void hard_set();
    void start_battle();
};

#endif // MAINMENU

