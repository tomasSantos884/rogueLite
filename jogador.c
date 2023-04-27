//atualizar funcao consoante a struct player


//tudo relacionado com o jogador, movimentacao, interacoes etc
#include "blocks.c"
#include <curses.h>



struct block{
	int type;
};

struct map{
	int rows;
	int collumns;
	struct block blocks[40][40]; //valores das colunas e linhas para exemplo apenas
};

struct player{
	int x;
	int y;
	int hp; //health points
};

typedef struct map {
    int rows;
    int columns;
    struct block blocks[40][40];
} mapa;

void drawPlayer(int x,int y, mapa m) {
 m.blocks[x][y] = 3; //3 remete para o personagem
 return 0;
}

void moveJogador(int ch,int x, int y,mapa m) { //mudei de block para char pq char é o tipo do bloco (símbolo), mas em baixo na função é passada na função a struct block

    switch (ch) {
      case KEY_UP: if (m.blocks[x][y+1] != '#') { // verifica se o jogador se está a mover contra uma parede
                   y = y++;
                   drawPlayer(x,y,m);}
        break;
      case KEY_DOWN: if (m.blocks[x][y-1] != '#') {
                     y = y--;
                     drawPlayer(x,y,m);}
        break;
      case KEY_LEFT: if (m.blocks[x-1][y] != '#') {
                     x = x--;
                     drawPlayer(x-1,y,m);}
        break;
      case KEY_RIGHT: if (m.blocks[x+1][y] != '#') {
                      x = x++;
                      drawPlayer(x+1,y,m);}
        break;
    }


  return 0;
}

int main() {
    struct player jogador;
    struct map mapa;
    int c;
    while (c = getch()) {
    //a função getch() lê input do jogador
      moveJogador(c,jogador.x,jogador.y,mapa);
    }
    return 0;
}

