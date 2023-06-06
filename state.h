#ifndef ___STATE_H___
#define ___STATE_H___
#include <ncurses.h>



typedef struct {
    int isWall; // 1 se é parede
	int isVisible; //1 se é visivel
	int seen; //1 se foi visto
} BLOCK;


typedef struct state{
	//coordenadas do jogador
	int playerX;
	int playerY;

	int borderLength; //valor definido para a grossura das bordas do mapa

	double probWall; //valor definido para a probabilidade de ser parede

	int nRows; //valor definido para o numero de linhas do mapa
	int nCols; //valor definido para o numero de colunas do mapa

	int nFstPass; //numero de vezes que vai ser corrido o primeiro algoritmo para organizar o mapa
	int nSndPass; //numero de vezes que vai ser corrido o segundo algoritmo para organizar o mapa

	bool playing; // Bool para verificar se o jogo está a decorrer ou está em pausa

	int player_health; // vida do jogador
	int player_hunger; // fome do jogador
	int mob_count; // numero de monstros restantes no nivel
} STATE;



#endif
