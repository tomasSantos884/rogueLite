#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#include "state.h"

#include "mapa.h"

#include "jogador.c"
#include "blocks.c"


int main(){

	STATE st;

	WINDOW *wnd = initscr();
	int ncols,nrows;
	getmaxyx(wnd,nrows,ncols);

	
	st.nRows = nrows;
	st.nCols = ncols;

	st.playerX = 20;
	st.playerY = 20;

	st.borderLength = 1;

	st.probWall = 0.30;

	st.nFstPass = 0;
	st.nSndPass = 0;

	st.nCols = ncols;
	st.nRows = nrows;

	BLOCK map[nrows][ncols];

	initializeBlocks((BLOCK*)map,&st); //inicializa os blocos para por as propriedades tudo a zero

	srandom(time(NULL));
	start_color();

	cbreak();
	noecho();
	nonl();
	intrflush(stdscr, false);
	keypad(stdscr, true);
	curs_set(0);


	init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
        init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
        init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);

	setBorders((BLOCK*)map,&st);
	fillMap((BLOCK*)map,&st);

	genMap((BLOCK*)map,&st);

	drawMap((BLOCK*)map,&st);

	/* for (int i = 0; i < st.nRows; i++){
		for (int j = 0; j < st.nCols; j++){
			insertBlock(map[i][j].isWall,map[i][j].isVisible,map[i][j].seen);
		}
		
	} */
	

	drawMap((BLOCK*)map,&st);


	while(1) {
		attron(COLOR_PAIR(COLOR_WHITE));
		mvaddch(st.playerX, st.playerY, '@' | A_BOLD);
		attroff(COLOR_PAIR(COLOR_WHITE));

		move(st.playerX, st.playerY);
		update(&st);
	}


	return 0;
}
