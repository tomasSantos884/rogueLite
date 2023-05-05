#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#include "state.h"

#include "mapa.h"


int main(){
	//estado inicial;
	STATE st;
	st.borderLength = 1;
	st.probWall = 0.40;
	st.nFstPass = 1;
	st.nSndPass = 1;

	WINDOW *wnd = initscr();
	getmaxyx(wnd,st.nCols,st.nRows);

	//printf("%d", st.nCols);
	//printf("%d", st.nRows);

	//int i;
	//st.map = malloc(st.nRows*sizeof(BLOCK*));
	//for(i=0;i<st.nRows;i++) st.map[i] = malloc(st.nCols*sizeof(BLOCK));

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


	//setBorders(&st, st.nRows, st.nCols, 2);

//printf("%d", st.nCols);
//	printf("%d", st.nRows);
/* 	for (int i = 0; i < st.nRows - 1; i++){
			//printf("%d ", i);
		for (int j = 0; j < st.nCols - 1; j++){
			printf("%d ", st.map[i][j].isWall);

			if (st.map[i][j].isWall){
				printf("%c",'#');
			}
			else{
				printf("%c",' ');
			}
		}
	} */

	/* while(1) {
		
	} */


	return 0;
}
