#ifndef GAME_H
#define GAME_H

/* 다른 헤더파일 추가 */
#include <iostream>
#include "ncurses.h"
#include "curses.h"

using namespace std;

class Game {
    private:

    public:
    Game();
    ~Game();
    void run();
};

#endif