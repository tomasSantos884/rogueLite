//atualizar funcao consoante a struct player


//tudo relacionado com o jogador, movimentacao, interacoes etc
#include "blocks.c"
#include <curses.h>
#include <ncurses.h>
#include "state.h"


void drawPlayer(int x,int y, STATE *s)  {} //já não faz nada, a função debaixo já muda o state


void moveJogador(int ch, STATE *s) { 


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
    }


  return 0;
}

int main() {
    STATE *s;
    int c;
    while (c = getch()) {
    //a função getch() lê input do jogador
      moveJogador(c, s);
    }
    return 0;
}

