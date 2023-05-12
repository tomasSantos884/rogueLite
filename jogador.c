//atualizar funcao consoante a struct player


//tudo relacionado com o jogador, movimentacao, interacoes etc
//#include "blocks.c"
#include <curses.h>
#include <ncurses.h>
#include "state.h"


void drawPlayer(int x,int y, STATE *s)  {} //já não faz nada, a função debaixo já muda o state


/* void moveJogador(STATE *s) { 

    int ch = getchar();
    switch (ch) {
      case KEY_UP: if (s->map[s->playerX][s->playerY++].isWall != 1) { // verifica se o jogador se está a mover contra uma parede
                   s->playerY = s->playerY++;}
        break;
      case KEY_DOWN: if (s->map[s->playerX][s->playerY--].isWall != 1) { 
                     s->playerY = s->playerY--;}
        break;
      case KEY_LEFT: if (s->map[s->playerX--][s->playerY].isWall != 1) { 
                     s->playerX = s->playerX--;}
        break;
      case KEY_RIGHT: if (s->map[s->playerX++][s->playerY].isWall != 1) { 
                     s->playerX = s->playerX++;}
        break;
    } */


//}
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


