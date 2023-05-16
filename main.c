#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>
#include <menu.h>
#include "state.h"
#include <string.h>
#include "mapa.h"








int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
	nonl;
	curs_set(0);
	start_color();

    init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
        init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
        init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);

	
	// Get window size
    int ncols,nrows;
	getmaxyx(stdscr,nrows,ncols);
	int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    STATE* st;

	st->nRows = nrows;
	st->nCols = ncols;

	st->playerX = 20;
	st->playerY = 20;

	st->borderLength = 1;

	st->probWall = 0.30;

	st->nFstPass = 0;
	st->nSndPass = 0;

	st->nCols = ncols;
	st->nRows = nrows;
	
	BLOCK map[nrows][ncols];
	initializeBlocks((BLOCK*)map,&st); //inicializa os blocos para por as propriedades tudo a zero
	srandom(time(NULL));
	start_color();
	// Create the menu
    int menu_choice = 0;
    const char* menu_choices[] = {
        "Start Game",
        "Options",
        "Exit"
    };
    const int num_choices = sizeof(menu_choices) / sizeof(menu_choices[0]);
    int menu_start_y = (max_y - num_choices) / 2;
    int menu_start_x = (max_x - 10) / 2; // Assumes menu items are 10 characters wide
    while (true) {
        // Print the menu
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

        // Get input
        int input = getch();
        switch (input) {
            case KEY_UP:
                menu_choice--;
                if (menu_choice < 0) {
                    menu_choice = num_choices - 1;
                }
                break;
            case KEY_DOWN:
                menu_choice++;
                if (menu_choice >= num_choices) {
                    menu_choice = 0;
                }
                break;
            case '\n':
                // Handle menu choice
                switch (menu_choice) {
                    case 0:
                        mvprintw(menu_start_y + num_choices, menu_start_x, "Starting game...");
                        clear();
						setBorders((BLOCK*)map,&st);
						fillMap((BLOCK*)map,&st);

						genMap((BLOCK*)map,&st);
						while(1) {
		playerVisibility((BLOCK*)map,&st);
		drawMap((BLOCK*)map,&st);
		attron(COLOR_PAIR(COLOR_WHITE));
		mvaddch(st.playerX, st.playerY, '@' | A_BOLD);
		attroff(COLOR_PAIR(COLOR_WHITE));

		move(st.playerX, st.playerY);
		update(&st);
	}
						
						break;
                    case 1:
                        mvprintw(menu_start_y + num_choices, menu_start_x, "Options menu...");
                        break;
                    case 2:
                        mvprintw(menu_start_y + num_choices, menu_start_x, "Exiting...");
                        goto end;
                        break;
                }
                mvprintw(menu_start_y + num_choices + 1, menu_start_x, "Press any key to continue...");
                getch();
                break;
        }
    }

end:
    // Clean up ncurses
    endwin();
    return 0;
}


