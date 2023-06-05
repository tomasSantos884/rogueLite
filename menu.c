#include "state.h"



    const char* menu_choices[] = {
        "Start new Game",
        "Continue",
        "Exit"
    };

void printMenu(int menu_choice, STATE* st) // A função printMenu vai desenhar o menu no ecrã
{
    int max_y = st->nRows;      
    int max_x = st->nCols;
    
    
    const int num_choices = 3;
    int menu_start_y = (max_y - num_choices) / 2; // coordenada y de referência para a posição do menu, as coordenadas y estão invertidas (max_y é a linha mais baixa do terminal)
    int menu_start_x = (max_x - 10) / 2; // coordenada x de referência para a posição do menu
    
    
    clear();
    attron(A_BOLD);
    attron(A_STANDOUT);
    mvprintw(menu_start_y - 4, (max_x - 22) / 2, "        Game Menu        ");
    attroff(A_STANDOUT);
    attroff(A_BOLD);
    box(stdscr, '|', '-');
    for (int i = 0; i < num_choices; i++) {
        if (i == menu_choice) {
            mvprintw(menu_start_y + i, menu_start_x, "-> %s", menu_choices[i]);
        } else {
            mvprintw(menu_start_y + i, menu_start_x, "   %s", menu_choices[i]);
        }
    }
    refresh();


}




