#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#include "state.h"

#include "mapa.h"

#include "jogador.c"


int main(){


	WINDOW *wnd = initscr();
	int ncols,nrows;
	getmaxyx(wnd,nrows,ncols);


	STATE* st = malloc(sizeof(STATE) + nrows * ncols * sizeof(BLOCK));

	st->nRows = nrows;
	st->nCols = ncols;

	st->playerX = 20;
	st->playerY = 20;

	st->borderLength = 1;

	st->probWall = 0.40;

	st->nFstPass = 0;
	st->nSndPass = 0;

	st->nCols = ncols;
	st->nRows = nrows;

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

	while(1) {

		setBorders(&st,st->nRows,st->nCols,st->borderLength);

		fillMap(&st,st->nRows,st->nCols);

		attron(COLOR_PAIR(COLOR_WHITE));
		mvaddch(st->playerX, st->playerY, '@' | A_BOLD);
		attroff(COLOR_PAIR(COLOR_WHITE));

		move(st->playerX, st->playerY);
		update(st);
	}


	return 0;
}
