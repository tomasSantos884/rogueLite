#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>
#include "state.h"








#define BOARD_DIM 40
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM*2.5

int main(){
	//STATE st = {20,20};
	WINDOW *wnd = initscr();
	int ncols, nrows;
	getmaxyx(wnd,nrows,ncols);



	return 0;
}
