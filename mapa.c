#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#include "mapa.h"

#include "state.h"




void setBorders(STATE *s, int nRows, int nCols, int borderLength) { //funcçao que irá percorrer o mapa e modificar as bordas destes de acordo com o tamanho da borda escolhido
	for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            if (i < borderLength || i >= nRows - borderLength || j < borderLength || j >= nCols - borderLength) {
                printf("position [%d][%d] is border", i, j);
				s->map[i][j].isWall = 1;
            }
        }
    }
}


void fillMap(STATE *s,int nRows, int nCols){ //esta funçao irá preencher o interior do mapa(excluindo as bordas) de forma aleatoria com paredes, gerando para cada bloco um numero, caso o numero seja menor do que a probabilidade de ser parede definida em probWall, esse bloco passará a ser uma parede
	srand48(time(NULL)); //Seed the random number generator with the current time
	double rand; //declara a variavel que vai ser usada para guardar os valores gerados aleatóriamente

	for (int i = 1; i < nRows - 1; i++){
		for (int j = 1; j < nCols - 1; j++){
			rand = drand48();
			s->map[i][j].isWall = rand < s->probWall;
		}
	}
}



int wallCountInRad(STATE *s, int posX, int posY, int radius, int nRows, int nCols) {
    int wallCount = 0;
    for (int i = posX - radius; i <= posX + radius; i++) {
        for (int j = posY - radius; j <= posY + radius; j++) {
            if (i > 0 && i < nRows - 1 && j > 0 && j < nCols - 1 && (i != nRows || j != nCols)) {
                if (s->map[i*nCols+j]->isWall){
                    wallCount++;
                }
            }
        }
    }
    return wallCount;
}


void genMap(STATE *s){

	setBorders(s,s->nRows,s->nCols,s->borderLength); //o 2 corresponde à grossura da borda do mapa

	fillMap(s,s->nRows,s->nCols); //este 40 corresponda à probabildade de certa 'casa' do mapa tem de ser parede ou não


	//primeiro algoritmo de organização
	//este algoritmo atravessa a matriz do mapa e para cada bloco é chamada a funcao wallCountInRad
	for (int i = 0; i < s->nFstPass; i++){

		char tempMap[s->nRows][s->nCols];

		for (int i = 1; i < s->nRows - 1; i++){
			for (int j = 1; j < s->nCols - 1; j++){
				tempMap[i][j] = (wallCountInRad(s,i,j,1,s->nRows,s->nCols) >= 5) || (wallCountInRad(s,i,j,2,s->nRows,s->nCols) <= 2);
			}
		}

		for (int i = 1; i < s->nRows - 1; i++){
			for (int j = 1; j < s->nCols - 1; j++){
				s->map[i][j].isWall = tempMap[i][j];
			}
		}
	}

	for (int i = 0; i < s->nSndPass; i++){

		char tempMap[s->nRows][s->nCols];

		for (int i = 1; i < s->nRows - 1; i++){
			for (int j = 1; j < s->nCols - 1; j++){
				tempMap[i][j] = (wallCountInRad(s,i,j,1,s->nRows,s->nCols) >= 5);
			}
		}

		for (int i = 1; i < s->nRows - 1; i++){
			for (int j = 1; j < s->nCols - 1; j++){
				s->map[i][j].isWall = tempMap[i][j];
			}
		}
	}




	for (int i = 0; i < s->nRows - 1; i++){
		for (int j = 0; j < s->nCols - 1; j++){
			if (s->map[i][j].isWall){
				printw("%c",'#');
			}
		}
	}
}
