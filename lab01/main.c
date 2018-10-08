#include <ncurses.h>

int main(void) {
    initscr();
    printw("hello, world");
    mvprintw(8, 10, "qwe");
    
    refresh();
    getchar();
    endwin();
    return 0;
}