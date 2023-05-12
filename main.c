#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#include "state.h"

#include "mapa.h"

#include "jogador.c"

int main(){
	STATE st;

	st.playerX = 20;
	st.playerY = 20;

	WINDOW *wnd = initscr();
	int ncols, nrows;
	getmaxyx(wnd,nrows,ncols);

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
	move(nrows - 1, 0);

	while(1) {
		move(0, 0);
		attron(COLOR_PAIR(COLOR_BLUE));
		printw("(%d, %d) %d %d", st.playerX, st.playerY, ncols, nrows);
		attroff(COLOR_PAIR(COLOR_BLUE));

		attron(COLOR_PAIR(COLOR_WHITE));
		mvaddch(st.playerX, st.playerY, '@' | A_BOLD);
		attroff(COLOR_PAIR(COLOR_WHITE));

		attron(COLOR_PAIR(COLOR_YELLOW));
		mvaddch(st.playerX - 1, st.playerY - 1, '.' | A_BOLD);
		mvaddch(st.playerX - 1, st.playerY + 0, '.' | A_BOLD);
		mvaddch(st.playerX - 1, st.playerY + 1, '.' | A_BOLD);
		mvaddch(st.playerX + 0, st.playerY - 1, '.' | A_BOLD);
		mvaddch(st.playerX + 0, st.playerY + 1, '.' | A_BOLD);
		mvaddch(st.playerX + 1, st.playerY - 1, '.' | A_BOLD);
		mvaddch(st.playerX + 1, st.playerY + 0, '.' | A_BOLD);
		mvaddch(st.playerX + 1, st.playerY + 1, '.' | A_BOLD);
        attroff(COLOR_PAIR(COLOR_YELLOW));

		move(st.playerX, st.playerY);
		moveJogador(&st);

	}


	return 0;
}
