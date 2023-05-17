//atualizar funcao consoante a struct player


//tudo relacionado com o jogador, movimentacao, interacoes etc
//#include "blocks.c"
#include <curses.h>
#include <ncurses.h>
#include "state.h"


//void drawPlayer(int x,int y, STATE *s)  {} //já não faz nada, a função debaixo já muda o state


void moveJogador(BLOCK* map,STATE *st) { 

    int ch = getchar();
    int i = st->playerX;
    int j = st->playerY;

    switch (ch) {
      case '8':
      case KEY_UP: if (map[i * st->nCols * (j+1)].isWall != 1) { // verifica se o jogador se está a mover contra uma parede
                   st->playerY++;}                                      // N
        break;
      case '7':
      case KEY_A3: if (map[(i-1) * st->nCols * (j+1)].isWall != 1) { // NW
                     st->playerY++;
                     st->playerX--;}
        break;
      case '9':
      case KEY_C3: if (map[(i+1) * st->nCols * (j+1)].isWall != 1) { //NE
                     st->playerY++;
                     st->playerX++;}
        break;
      case '2':
      case KEY_DOWN: if (map[i * st->nCols * (j-1)].isWall != 1) {  //S
                     st->playerY--;}
        break;
      case '1':
      case KEY_A1: if (map[(i-1) * st->nCols * (j-1)].isWall != 1) { //SW
                     st->playerY--;
                     st->playerX--;}
        break;
      case '3':
      case KEY_C1: if (map[(i+1) * st->nCols * (j-1)].isWall != 1) { //SE
                     st->playerY--;
                     st->playerX++;}
        break;
      case '4':
      case KEY_LEFT: if (map[(i-1) * st->nCols * j].isWall != 1) { //W
                     st->playerX--;}
        break;
      case '6':
      case KEY_RIGHT: if (map[(i+1) * st->nCols * j].isWall != 1) { //E
                     st->playerX++;}
        break;
    } 
}

void spawnPlayer (BLOCK* map,STATE *st) {
  srand(9);
  int i = rand() % st->nCols;
  int j = rand() % st->nRows;
  while (map[i * st->nCols * j].isWall == 1) {
    i = rand() % st->nCols;
    j = rand() % st->nRows;
  }
  st->playerX = i;
  st->playerY = j;
}

 void do_movement_action(STATE *st, int dx, int dy) {
	st->playerX += dx;
	st->playerY += dy;
}


void update(STATE *st) {
	int key = getch();

	mvaddch(st->playerX, st->playerY, ' ');
	switch(key) {
		case KEY_A1:
		case '7': do_movement_action(st, -1, -1); break;
		case KEY_UP:
		case '8': do_movement_action(st, -1, +0); break;
		case KEY_A3:
		case '9': do_movement_action(st, -1, +1); break;
		case KEY_LEFT:
		case '4': do_movement_action(st, +0, -1); break;
		case KEY_B2:
		case '5': break;
		case KEY_RIGHT:
		case '6': do_movement_action(st, +0, +1); break;
		case KEY_C1:
		case '1': do_movement_action(st, +1, -1); break;
		case KEY_DOWN:
		case '2': do_movement_action(st, +1, +0); break;
		case KEY_C3:
		case '3': do_movement_action(st, +1, +1); break;
		case 'q': endwin(); exit(0); break;
	}
}

/*
int main() {
    STATE *s;
    int c;
    while (c = getch()) {
    //a função getch() lê input do jogador
      moveJogador(c, s);
    }
    return 0;
} */


