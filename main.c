#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>
#include <menu.h>
#include <string.h>



#include "state.h"
#include "jogador.c"
#include "blocks.c"
#include "vision.c"
#include "mapa.h"
#include "menu.c"





int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
	//nonl();
	curs_set(0);
	start_color();

    init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
        init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
        init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);

	
	// Get window size
    int ncols,nrows;
	getmaxyx(stdscr,nrows,ncols);
	

    STATE st;

	st.nRows = nrows;
	st.nCols = ncols;

	st.playerX = 20;
	st.playerY = 20;

	st.borderLength = 1;

	st.probWall = 0.40;

	st.nFstPass = 4;
	st.nSndPass = 1;

	st.nCols = ncols;
	st.nRows = nrows;
	
	BLOCK map[nrows][ncols];
	initializeBlocks((BLOCK*)map,&st); //inicializa os blocos para por as propriedades tudo a zero
	srandom(time(NULL));
	start_color();

	
	//Menu
	const int num_choices = sizeof(menu_choices) / sizeof(menu_choices[0]);
    int menu_start_y = (st.nRows - num_choices) / 2;
    int menu_start_x = (st.nCols - 10) / 2;
	int menu_choice = 0;
    printMenu(menu_choice, &st);    
	while (1)
	{
	
	
	
	
		bool playing = false;	
		int input = getch();
        switch (input) {
            case KEY_UP:
                menu_choice--;
                if (menu_choice < 0) {
                    menu_choice = num_choices - 1;
                }
                printMenu(menu_choice, &st);
				break;
            case KEY_DOWN:
                menu_choice++;
                if (menu_choice >= num_choices) {
                    menu_choice = 0;
                }
                printMenu(menu_choice, &st);
				break;
            case '\n':
                // Handle menu choice
                switch (menu_choice) {
                    case 0:
                        mvprintw(menu_start_y + num_choices, menu_start_x, "Starting game...");
                        clear();
						refresh();
						playing = true;

						genMap((BLOCK*)map,&st);
						while(playing) {
		playerVisibility((BLOCK*)map,&st);
		drawMap((BLOCK*)map,&st);
		attron(COLOR_PAIR(COLOR_WHITE));
		mvaddch(st.playerX, st.playerY, '@' | A_BOLD);
		attroff(COLOR_PAIR(COLOR_WHITE));

		move(st.playerX, st.playerY);
		update(&st);
		refresh();
	}
		printMenu(menu_choice, &st);				
						break;
                    case 1:
                        printMenu(menu_choice, &st);
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


