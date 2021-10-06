#include <stdbool.h>
#include <ncurses.h>

#include "game.h"


int main(int argc, char *argv[]) {

    initscr(); // ncurses init
    noecho();  // Don't print key inputs on screen
    cbreak();  // No need to press enter after char inputs
    nodelay(stdscr, true); // Getch don't block anymore

    int col, row;
    getmaxyx(stdscr, row, col);

    init_game(row); // Initialize game vars

    int key; // Key inputs

    while(1){
        key = getch();
        if (key > 0)
            update_cursor(key);
        refresh();
    }

    endwin();

    return 0;
}

