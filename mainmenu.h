//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#ifndef MAINMENU
#define MAINMENU

#include <QWidget>
#include <QPushButton>

//main window at beginning to select character and difficulty
class MainMenu : public QWidget {
public:
    MainMenu(QWidget* parent=0);
    //make BATTLE! button a member so you can pass it to main.cpp connect function
    QPushButton* battle;
};

#endif // MAINMENU

