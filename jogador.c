//tudo relacionado com o jogador, movimentacao, interacoes etc

#include <curses.h>
#include <ncurses.h>
#include "state.h"

// A função 'spawnPlayer' gera a posição inicial do jogador no mapa, obtendo coordenadas aleatóriamente selecionadas
// dentro dos limites do mapa, na condição de que o jogador não incia o jogo dentro de uma parede.

void spawnPlayer(BLOCK* map, STATE* st) { 
    srand(time(NULL));

    int i = rand() % st->nRows;         // geração de números aleatórios para i e j separadamente
    int j = rand() % st->nCols;

    while (map[i * st->nCols + j].isWall == 1) {
        i = rand() % st->nRows;
        j = rand() % st->nCols;
    }

    st->playerX = i;   //dá valor às coordenadas na STATE
    st->playerY = j;
}

// 'updatePosPlayer' é uma função auxiliar de 'update', serve para impôr a condição de não entrar numa parede e para mudar 
// os valores correspondentes às coordenadas do jogador na struck state definida.

 void updatePosPlayer(STATE *st,BLOCK *map, int dx, int dy) {

  if (map[(st->playerX + dx) * st->nCols + (st->playerY + dy)].isWall != 1){ //condição
    st->playerX += dx;
    st->playerY += dy;
  }
}

// A função 'update' disponibiliza o movimento do jogador em todas as direções através da função 'getch()' e modifica 
// as suas coordenadas de acordo com a tecla pressionada. Utiliza as setas no teclado e o keypad.

void update(STATE *st,BLOCK *map) {
	int key = getch();

	mvaddch(st->playerX, st->playerY, ' ');
	switch(key) {
		case KEY_A1:
		case '7': updatePosPlayer(st,(BLOCK*)map, -1, -1); break;  //Up+Left
		case KEY_UP:
		case '8': updatePosPlayer(st,(BLOCK*)map, -1, +0); break;  //Up
		case KEY_A3:
		case '9': updatePosPlayer(st,(BLOCK*)map, -1, +1); break;  //Up+Right
		case KEY_LEFT:
		case '4': updatePosPlayer(st,(BLOCK*)map, +0, -1); break; //Left
		case KEY_B2:
		case '5': break;
		case KEY_RIGHT:
		case '6': updatePosPlayer(st,(BLOCK*)map, +0, +1); break; //Right
		case KEY_C1:
		case '1': updatePosPlayer(st,(BLOCK*)map, +1, -1); break; //Down+Left
		case KEY_DOWN:
		case '2': updatePosPlayer(st,(BLOCK*)map, +1, +0); break; //Down
		case KEY_C3:
		case '3': updatePosPlayer(st,(BLOCK*)map, +1, +1); break; //Down+Right
		case 'q': endwin(); exit(0); break;
		case 'p': st->playing = false; break;
	}
}


