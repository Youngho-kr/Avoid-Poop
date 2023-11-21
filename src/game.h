#ifndef GAME_H
#define GAME_H

/* 다른 헤더파일 추가 */
#include <iostream>
#include "ncurses.h"
#include "curses.h"

/* Macros */
/* Select Menu */
#define checkSelect(num, option) num == option ? printw("            * ") : printw("             ")

#define MIN_OPTION 1
#define MAX_OPTION 3
#define PLAY 1
#define SCORE 2
#define EXIT 3

using namespace std;

class Game {
    private:
    void initGame();
    void mainScreen();

    void title();
    void menu();
    bool selectOption();

    void play();
    void score();
    int selectMenu;

    public:
    Game();
    ~Game();
    void run();
};

#endif