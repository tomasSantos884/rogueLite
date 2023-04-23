//tudo relacionado com o jogador, movimentacao, interacoes etc

#include <curses.h>

void drawPlayer(int x,int y,block m) {
 m[x][y] = '@';
 return 0;
}

void moveJogador(int ch,int x, int y, block m) {

    switch (ch) {
      case KEY_UP: if (m[x][y+1] != '#') { // verifica se o jogador se está a mover contra uma parede
                   y = y++;
                   drawPlayer(x,y,m);}
        break;
      case KEY_DOWN: if (m[x][y-1] != '#') {
                     y = y--;
                     drawPlayer(x,y,m);}
        break;
      case KEY_LEFT: if (m[x-1][y] != '#') {
                     x = x--;
                     drawPlayer(x-1,y,m);}
        break;
      case KEY_RIGHT: if (m[x+1][y] != '#') {
                      x = x++;
                      drawPlayer(x+1,y,m);}
        break;
    }


  return 0;
}

int main() {
    map m;
    player p;
    int c;
    while (c = getch()) {
    //a função getch() lê input do jogador
      moveJogador(c,p.x,p.y,m.block);
    }
    return 0;
}

