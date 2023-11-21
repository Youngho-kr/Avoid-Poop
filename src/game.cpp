#include "game.h"

Game::Game() {
    /* Init game */
    cout << "Thanks for Playing!!" << endl;
    initGame();
}

Game::~Game() {
    endwin();               /* ncurses 종료 */
}

/* Private Functions */
void Game::initGame() {
    initscr();              /* screen 초기화 */
    noecho();               /* 입력 표시 제거 */
    curs_set(false);        /* 커서 제거 */
    keypad(stdscr, true);   /* 특수 입력 허용 */

    /* color 설정 */
    /* 글자 색상, 배경 색상 */
    init_pair(1, COLOR_RED, COLOR_BLACK);

    /* Menu 선택 option 초기화 */
    selectMenu = 1;
}
void Game::mainScreen() {
    clear();
    title();
    menu();
    refresh();
    cout << selectMenu << endl;
}
void Game::title() {
    attron(COLOR_PAIR(1));
    printw("#####################################\n");
    printw("## ######  ######  ######  ######  ##\n");
    printw("## #    #  #    #  #    #  #    #  ##\n");
    printw("## #    #  #    #  #    #  #    #  ##\n");
    printw("## ######  #    #  #    #  ######  ##\n");
    printw("## #       #    #  #    #  #       ##\n");
    printw("## #       #    #  #    #  #       ##\n");
    printw("## #       #    #  #    #  #       ##\n");
    printw("## #       ######  ######  #       ##\n");
    printw("#####################################\n");
    printw("\n\n");
    printw("                 @\n");
    printw("                @@@\n");
    printw("               @@@@@\n");
    printw("              @@@@@@@\n");
    printw("             @@@@@@@@@\n");
    printw("            @@@@@@@@@@@\n");
    printw("\n\n");
}
void Game::menu() {
    checkSelect(selectMenu, PLAY);
    printw("Play\n");
    checkSelect(selectMenu, SCORE);
    printw("Score\n");
    checkSelect(selectMenu, EXIT);
    printw("Exit\n");
}

/* Public Functions */
void Game::run() {
    /* Check exit selected */
    bool exit_ = false;
    /* Game loop */
    while(1) {
        mainScreen();
        int input = getch();
        switch(input) {
            case KEY_UP:
                if(selectMenu > MIN_OPTION)
                    selectMenu--;
                break;
            case KEY_DOWN:
                if(selectMenu < MAX_OPTION)
                    selectMenu++;
                break;
            case ' ':
            case '\n':
                exit_ = selectOption();
                break;
        }

        if(exit_)
            break;
    }
}

bool Game::selectOption() {
    if(selectMenu == PLAY)
        play();
    else if(selectMenu == SCORE)
        score();
    else if(selectMenu == EXIT)
        return true;
    selectMenu = 1;
    return false;
}

void Game::play() {
    
}

void Game::score() {

}