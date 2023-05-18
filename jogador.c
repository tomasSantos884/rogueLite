//atualizar funcao consoante a struct player


//tudo relacionado com o jogador, movimentacao, interacoes etc
//#include "blocks.c"
#include <curses.h>
#include <ncurses.h>
#include "state.h"

void spawnPlayer(BLOCK* map, STATE* st) {
    srand(time(NULL));

    int i = rand() % st->nRows;
    int j = rand() % st->nCols;

    while (map[i * st->nCols + j].isWall == 1) {
        i = rand() % st->nRows;
        j = rand() % st->nCols;
    }

    st->playerX = i;
    st->playerY = j;
}
 void updatePosPlayer(STATE *st,BLOCK *map, int dx, int dy) {

  if (map[(st->playerX + dx) * st->nCols + (st->playerY + dy)].isWall != 1){
    st->playerX += dx;
    st->playerY += dy;
  }
}


void update(STATE *st,BLOCK *map) {
	int key = getch();

	mvaddch(st->playerX, st->playerY, ' ');
	switch(key) {
		case KEY_A1:
		case '7': updatePosPlayer(st,(BLOCK*)map, -1, -1); break;
		case KEY_UP:
		case '8': updatePosPlayer(st,(BLOCK*)map, -1, +0); break;
		case KEY_A3:
		case '9': updatePosPlayer(st,(BLOCK*)map, -1, +1); break;
		case KEY_LEFT:
		case '4': updatePosPlayer(st,(BLOCK*)map, +0, -1); break;
		case KEY_B2:
		case '5': break;
		case KEY_RIGHT:
		case '6': updatePosPlayer(st,(BLOCK*)map, +0, +1); break;
		case KEY_C1:
		case '1': updatePosPlayer(st,(BLOCK*)map, +1, -1); break;
		case KEY_DOWN:
		case '2': updatePosPlayer(st,(BLOCK*)map, +1, +0); break;
		case KEY_C3:
		case '3': updatePosPlayer(st,(BLOCK*)map, +1, +1); break;
		case 'q': endwin(); exit(0); break;
		case 'p': st->playing = false; break;
	}
}


