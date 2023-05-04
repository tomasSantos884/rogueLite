#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#include "mapa.c"

int main(){
	//estado inicial;
	STATE st;
	st.borderLength = 1;
	st.probWall = 0.40;
	st.nFstPass = 1;
	st.nSndPass = 1;

	WINDOW *wnd = initscr();
	getmaxyx(wnd,st.nCols,st.nRows);
	

	srand48(time(NULL));
	start_color();

	cbreak();
	noecho();
	nonl();
	intrflush(stdscr, false);
	keypad(stdscr, true);

	init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
        init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
        init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);

	genMap(&st);

	while(1) {
		
	}


	return 0;
}
