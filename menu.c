#include "state.h"



    const char* menu_choices[] = {
        "Start Game",
        "Options",
        "Exit"
    };

void printMenu(int menu_choice, STATE* st)
{
    int max_y = st->nRows;
    int max_x = st->nCols;
    
    
    const int num_choices = sizeof(menu_choices) / sizeof(menu_choices[0]);
    int menu_start_y = (max_y - num_choices) / 2;
    int menu_start_x = (max_x - 10) / 2; // Assumes menu items are 10 characters wide
    
    
    
    clear();
    attron(A_BOLD);
    attron(A_STANDOUT);
    mvprintw(menu_start_y - 4, (max_x - 22) / 2, "        Game Menu        ");
    attroff(A_STANDOUT);
    attroff(A_BOLD);
    box(stdscr, 0, 0); // Add a box around the screen
    int inner_start_y = menu_start_y - 2;
    int inner_start_x = menu_start_x - 2;
    int inner_end_y = menu_start_y + num_choices + 2;
    int inner_end_x = menu_start_x + 12; // Assumes menu items are 10 characters wide, plus 2 characters of padding
    box(stdscr, '|', '-'); // Add a box around the menu
    for (int i = inner_start_y + 1; i < inner_end_y; i++) {
        mvhline(i, inner_start_x + 1, ' ', inner_end_x - inner_start_x - 1);
    }
    for (int i = 0; i < num_choices; i++) {
        if (i == menu_choice) {
            mvprintw(menu_start_y + i, menu_start_x, "-> %s", menu_choices[i]);
        } else {
            mvprintw(menu_start_y + i, menu_start_x, "   %s", menu_choices[i]);
        }
    }
    refresh();


}




