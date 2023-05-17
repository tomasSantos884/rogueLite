#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#include "mapa.h"
#include "state.h"




void fillMap(BLOCK* map,STATE *st){
	srand48(time(NULL));
	double rand;

	for (int i = 1; i < st->nRows - 1; i++) {
        for (int j = 1; j < st->nCols - 1; j++) {
			rand = drand48();


			if (rand < st->probWall){
				map[i * st->nCols + j].isWall = 1;
			}
		}
	}
}

void setBorders(BLOCK* map,STATE *st){ //funcçao que irá percorrer o mapa e modificar as bordas destes de acordo com o tamanho da borda escolhido
	
	for (int i = 0;i < st->nRows;i++){
        for (int j = 0; j < st->nCols; j++) {
            if (i < st->borderLength || i >= st->nRows - st->borderLength || j < st->borderLength || j >= st->nCols - st->borderLength) {
				map[i * st->nCols + j].isWall = 1;
            }
        }
	}
}

int wallCountInRad(BLOCK* map, int posX, int posY, int radius,STATE *st) {
    int wallCount = 0;
    for (int i = posX - radius; i <= posX + radius; i++) {
        for (int j = posY - radius; j <= posY + radius; j++) {

            if (i > 1 && i < st->nRows - 1 && j > 1 && j < st->nCols - 1 && (i != posX || j != posY)) {

                if (map[i * st->nCols + j].isWall == 1){
                    wallCount++;
					
                }
            }
        }
    }

	return wallCount;
}


void firstSortAlgorithm(BLOCK* map,STATE *st){
		for (int i = 0; i < st->nFstPass; i++){

		int tempMap[st->nRows][st->nCols];

		for (int i = 1; i < st->nRows - 1; i++){
			for (int j = 1; j < st->nCols - 1; j++){
				tempMap[i][j] = (wallCountInRad((BLOCK*)map,i,j,1,st) >= 5) || (wallCountInRad((BLOCK*)map,i,j,2,st) <= 2);
			}
		}

		for (int i = 1; i < st->nRows - 1; i++){
			for (int j = 1; j < st->nCols - 1; j++){
				map[i * st->nCols + j].isWall = tempMap[i][j];
			}
		}
	}
}


void sndSortAlgorithm(BLOCK* map,STATE *st){
	for (int i = 0; i < st->nSndPass; i++){

		int x,y;
		int tempMap[st->nRows][st->nCols];

		for (int x = 1; x < st->nRows - 1; x++){
			for (int y = 1; y < st->nCols - 1; y++){
				tempMap[x][y] = (wallCountInRad((BLOCK*)map,x,y,1,st) >= 5);
			}
		}

		for (int x = 1; x < st->nRows - 1; x++){
			for (int y = 1; y < st->nCols - 1; y++){
				map[x * st->nCols + y].isWall = tempMap[x][y];
			}
		}
	} 

}	


void genMap(BLOCK* map,STATE *st){
	
	

	setBorders((BLOCK*)map,st); //o 2 corresponde à grossura da borda do mapa

	fillMap((BLOCK*)map,st); //este 40 corresponda à probabildade de certa 'casa' do mapa tem de ser parede ou não


	//primeiro algoritmo de organização
	//este algoritmo atravessa a matriz do mapa e para cada bloco é chamada a funcao wallCountInRad

	firstSortAlgorithm((BLOCK*)map,st);

	//segundo algoritmo de organização
	sndSortAlgorithm((BLOCK*)map,st);

}
