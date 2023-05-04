#ifndef ___STATE_H___
#define ___STATE_H___
#include <ncurses.h>

#define rows 100
#define cols 100


typedef struct {
    int isWall;
	int isVisible;   // 1 se é parede, 0 se não
} BLOCK;


typedef struct state {
	//coordenadas do jogador
	int playerX;
	int playerY;

	int borderLength; //valor definido para a grossura das bordas do mapa

	double probWall; //valor definido para a probabilidade de ser parede

	int nRows; //valor definido para o numero de linhas do mapa
	int nCols; //valor definido para o numero de colunas do mapa

	int nFstPass; //numero de vezes que vai ser corrido o primeiro algoritmo para organizar o mapa
	int nSndPass; //numero de vezes que vai ser corrido o segundo algoritmo para organizar o mapa

	BLOCK map[rows][cols];
} STATE;
#endif
