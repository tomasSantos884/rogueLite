#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#include "blocks.c"

struct block{
	int type;
};

// type = 2 -> caverna, = 1 -> parede, = 0 -> chao

struct map{
	int rows;
	int collumns;
	struct block blocks[40][40]; //valores de linhas e colunas apenas para exemplo
};


// função que preeenche as bordas do mapa
int fillBorders(){
	return 0;
}



int main(){

	return 0;
}
