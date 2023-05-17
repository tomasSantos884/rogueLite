//modulo para a visibilidade do jogador

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

#include "state.h"

#include "mapa.h"

#define RANGE_OF_SIGHT 5

// x e y sao coordenadas do jogador, rows e collums sao coordenadas do mapa
void playerVisibility(BLOCK *map,STATE *st){


    for (int i=0; i < st->nRows; i++){
        for (int j=0; j< st->nCols; j++){
            int dx = i - st->playerX;
            int dy = j - st->playerY;
            double distance = sqrt(dx * dx + dy * dy); // calcucar a tangente para verificar as posiçoes de uma forma circular

            if (distance <= RANGE_OF_SIGHT){
                int isObject = 0;

                // loop para verificar se existe um obstaculo entre a posiçao do jogador e a posiçao que estamos a verificar
                for (double t = 0; t < 1.0; t+= 0.1){
                    int cx = st->playerX + t * dx;
                    int cy = st->playerY + t * dy;

                    // verificar se o bloco é um obstaculo neste caso parede ou caverna
                    if (map[cy * st->nCols + cx].isWall == 1){
                        isObject=1;
                        break;
                    }
                }

                 if (isObject){
                    map[i * st->nCols + j].isVisible = 1;
                    map[i * st->nCols + j].seen = 1;// ja encontrou uma parece por isso nao consegue ver mais 
                } else {
                    map[i * st->nCols + j].isVisible = 1;
                    map[i * st->nCols + j].seen = 1; // bloco visivel
                } 

                map[i * st->nCols + j].isVisible = 1;
                map[i * st->nCols + j].seen = 1;
                

            } else {
                    map[i * st->nCols + j].isVisible = 0;// esta fora da range
                }
        }
    }
}
