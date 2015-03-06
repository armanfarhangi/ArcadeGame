//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#include "game.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QButtonGroup>
#include "player.h"
#include "enemies.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QApplication>

//creates the main window
Game::Game(QWidget*)
{
    //Title of game
    QLabel* heading = new QLabel("<h1>KAMEHAMEHA ATTACK!</h1>");
    heading->setAlignment(Qt::AlignCenter);

    //Choose character instruction
    QLabel* pick_char = new QLabel("<h2>Pick your character:</h2>");
    pick_char->setAlignment(Qt::AlignCenter);

    //Character select images
    QLabel* goku_label = new QLabel;
    QString fileName(":/Images/Goku_select.png");
    QPixmap* goku_image = new QPixmap(fileName);
    goku_label->setPixmap(*goku_image);
    QLabel* hercule_label = new QLabel;
    fileName = ":/Images/Hercule_select.png";
    QPixmap* hercule_image = new QPixmap(fileName);
    hercule_label->setPixmap(*hercule_image);
    QLabel* saiyaman_label = new QLabel;
    fileName = ":/Images/Saiyaman_select.png";
    QPixmap* saiyaman_image = new QPixmap(fileName);
    saiyaman_label->setPixmap(*saiyaman_image);
    QHBoxLayout* char_images = new QHBoxLayout;
    char_images->addWidget(goku_label);
    char_images->addWidget(hercule_label);
    char_images->addWidget(saiyaman_label);
    char_images->setAlignment(Qt::AlignCenter);

    //Character select buttons
    QRadioButton* goku_button = new QRadioButton("Goku");
    QRadioButton* hercule_button = new QRadioButton("Hercule");
    QRadioButton* saiyaman_button = new QRadioButton("Saiyaman");
    QHBoxLayout* char_buttons = new QHBoxLayout;
    char_buttons->addWidget(goku_button);
    char_buttons->addWidget(hercule_button);
    char_buttons->addWidget(saiyaman_button);
    char_buttons->setAlignment(Qt::AlignCenter);
    //So char buttons don't share toggle with difficulty select
    QButtonGroup* char_select = new QButtonGroup;
    char_select->addButton(goku_button);
    char_select->addButton(hercule_button);
    char_select->addButton(saiyaman_button);

    //Select difficulty text
    QLabel* choose_difficulty = new QLabel("<h2>Choose Difficulty:</h2>");
    choose_difficulty->setAlignment(Qt::AlignCenter);

    //Difficulty select buttons
    QRadioButton* easy = new QRadioButton("Human");
    QRadioButton* medium = new QRadioButton("Saiyan");
    QRadioButton* hard = new QRadioButton("Super Saiyan");
    QVBoxLayout* difficulties = new QVBoxLayout;
    difficulties->addWidget(easy);
    difficulties->addWidget(medium);
    difficulties->addWidget(hard);
    difficulties->setAlignment(Qt::AlignCenter);
    //So difficulty buttons don't share toggle with char buttons
    QButtonGroup* difficulty_select = new QButtonGroup;
    difficulty_select->addButton(easy);
    difficulty_select->addButton(medium);
    difficulty_select->addButton(hard);

    //Instructions button that shows instructions when clicked
    QPushButton* instructions = new QPushButton("INSTRUCTIONS");
    QApplication::connect(instructions, SIGNAL(clicked()), this, SLOT(show_instructions()));

    //BATTLE! button
    QPushButton* battle = new QPushButton("BATTLE!");

    //Organizing all the previous elements vertically
    QVBoxLayout* vlay = new QVBoxLayout;
    vlay->addWidget(heading);
    vlay->addWidget(pick_char);
    vlay->addLayout(char_images);
    vlay->addLayout(char_buttons);
    vlay->addWidget(choose_difficulty);
    vlay->addLayout(difficulties);
    vlay->addWidget(instructions);
    vlay->addWidget(battle);

    //Set organized elements to the menu window
    this->setLayout(vlay);

    //setting character
    QObject::connect(goku_button, SIGNAL(clicked()), this, SLOT(goku_set()));
    QObject::connect(hercule_button, SIGNAL(clicked()), this, SLOT(hercule_set()));
    QObject::connect(saiyaman_button, SIGNAL(clicked()), this, SLOT(saiyaman_set()));

    //setting difficulty
    QObject::connect(easy, SIGNAL(clicked()), this, SLOT(easy_set()));
    QObject::connect(medium, SIGNAL(clicked()), this, SLOT(medium_set()));
    QObject::connect(hard, SIGNAL(clicked()), this, SLOT(hard_set()));

    //when BATTLE! is clicked, the menu window is hidden and the battle window is created and shown
    //hide menu window, don't destroy it; this way you can save character and difficulty information
    QApplication::connect(battle, SIGNAL(clicked()), this, SLOT(hide()));
    QApplication::connect(battle, SIGNAL(clicked()), this, SLOT(start_battle()));
}

void Game::game_over()
{
    QWidget* game_over_menu = new QWidget;

    QLabel* you_lose = new QLabel("<h1> YOU LOSE! </h1>");
    you_lose->setAlignment(Qt::AlignCenter);
    QPushButton* restart = new QPushButton("TRY AGAIN");
    QPushButton* change_options = new QPushButton("CHANGE OPTIONS");
    QPushButton* quit = new QPushButton("QUIT");

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(you_lose);
    layout->addWidget(restart);
    layout->addWidget(change_options);
    layout->addWidget(quit);

    game_over_menu->setLayout(layout);
    game_over_menu->show();

    connect(restart, SIGNAL(clicked()), view, SLOT(close()));
    connect(restart, SIGNAL(clicked()), game_over_menu, SLOT(close()));
    connect(restart, SIGNAL(clicked()), this, SLOT(start_battle()));

    connect(change_options, SIGNAL(clicked()), view, SLOT(close()));
    connect(change_options, SIGNAL(clicked()), game_over_menu, SLOT(close()));
    connect(change_options, SIGNAL(clicked()), this, SLOT(show()));

    connect(quit, SIGNAL(clicked()), view, SLOT(close()));
    connect(quit, SIGNAL(clicked()), game_over_menu, SLOT(close()));
    connect(quit, SIGNAL(clicked()), this, SLOT(close()));
}

void Game::show_instructions()
{
    QWidget* instruction_window = new QWidget;
    QLabel* instructions1 = new QLabel("<h3>DESTROY YOUR ENEMIES BEFORE THEY DESTROY YOU!</h3>");
    QLabel* instructions2 = new QLabel("*** USE ARROW KEYS TO MOVE AND SPACE BAR TO SHOOT ***");
    instructions2->setAlignment(Qt::AlignCenter);
    QLabel* instructions3 = new QLabel("*** YOU CAN ONLY SHOOT EVERY COUPLE SECONDS ***");
    instructions3->setAlignment(Qt::AlignCenter);
    QPushButton* close = new QPushButton("DONE");

    QVBoxLayout* vlayout = new QVBoxLayout;
    vlayout->addWidget(instructions1);
    vlayout->addWidget(instructions2);
    vlayout->addWidget(instructions3);
    vlayout->addWidget(close);
    instruction_window->setLayout(vlayout);
    instruction_window->show();

    QApplication::connect(close, SIGNAL(clicked()), instruction_window, SLOT(close()));
}

void Game::goku_set()
{
    character = 3;
}

void Game::hercule_set()
{
    character = 1;
}

void Game::saiyaman_set()
{
    character = 2;
}

void Game::easy_set()
{
    difficulty = 3;
}

void Game::medium_set()
{
    difficulty = 1;
}

void Game::hard_set()
{
    difficulty = 2;
}

//slot that starts the game after player clicks BATTLE!
void Game::start_battle()
{
    view = new QGraphicsView;
    //create the scene (which is the abstract graphic space)
    QGraphicsScene* scene = new QGraphicsScene;
    //create the player, a graphic item
    Player* player = new Player(character);
    scene->addItem(player);
    //set scene and its items into the view
    view->setScene(scene);
    //to set focus on player item automatically
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //no scroll bars
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Set sizes of scene(abstract space for graphic objects) and view (what user actually sees)
    view->setFixedSize(657, 670);
    scene->setSceneRect(56, 0, 657, 670); //specific numbers so I could perfectly fit view/scene to background

    //background
    scene->setBackgroundBrush(QBrush(QImage(":/Images/background.png")));

    //spawn enemies
    XEnemy* top_enemy1 = new XEnemy(player, -10, this);
    XEnemy* top_enemy2 = new XEnemy(player, -10, this);
    XEnemy* bottom_enemy1 = new XEnemy(player, 590, this);
    XEnemy* bottom_enemy2 = new XEnemy(player, 590, this);
    scene->addItem(top_enemy1);
    scene->addItem(top_enemy2);
    scene->addItem(bottom_enemy1);
    scene->addItem(bottom_enemy2);
    if (difficulty == 1){
        YEnemy* left_enemy1 = new YEnemy(player, 60, this);
        YEnemy* left_enemy2 = new YEnemy(player, 60, this);
        scene->addItem(left_enemy1);
        scene->addItem(left_enemy2);
    }
    if (difficulty == 2){
        YEnemy* left_enemy1 = new YEnemy(player, 60, this);
        YEnemy* left_enemy2 = new YEnemy(player, 60, this);
        scene->addItem(left_enemy1);
        scene->addItem(left_enemy2);
        YEnemy* right_enemy1 = new YEnemy(player, 655, this);
        YEnemy* right_enemy2 = new YEnemy(player, 655, this);
        scene->addItem(right_enemy1);
        scene->addItem(right_enemy2);
     }
    view->show();
}
