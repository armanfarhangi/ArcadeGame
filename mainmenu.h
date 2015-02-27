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
class MainMenu : public QWidget {
    Q_OBJECT
public:
    MainMenu(QWidget* parent=0);
    //make BATTLE! button a member so you can pass it to main.cpp connect function
    QPushButton* battle;
    QString character;
public slots:
    void new_game();
};

#endif // MAINMENU

