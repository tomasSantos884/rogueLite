//modulo para a visibilidade do jogador

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

#include "state.h"

#include "mapa.h"

#define RANGE_OF_SIGHT 10 //raio de visao do jogador


// Definir todas as posições do mapa como não visíveis, usada para dar refresh ao campo de visao 
void refreshVisibility(BLOCK *map, STATE *st) {
    for (int i = 0; i < st->nRows; i++) {
        for (int j = 0; j < st->nCols; j++) {
            map[i * st->nCols + j].isVisible = 0;
        }
    }
}


//funçao cria o raio de visao e marca as posiçoes como vistas
void playerVisibility(BLOCK *map,STATE *st){
    for (int i=0; i < st->nRows; i++){
        for (int j=0; j< st->nCols; j++){
            int dx = i - st->playerX;
            int dy = j - st->playerY;
            double distance = sqrt(dx * dx + dy * dy); // calcucar a tangente para verificar a distancia das posiçoes de uma forma circular
            
            if (distance <= RANGE_OF_SIGHT){
                int cx =0;
                int cy =0;
                int isObject = 0;
                
                // loop para verificar se existe um obstaculo entre a posiçao do jogador e a posiçao que estamos a verificar (0.1 é o grau de precisao das leituras que vai fazer)
                for (double t = 0; t < 1.0; t+= 0.1){ 
                    cx = st->playerX + t * dx;
                    cy = st->playerY + t * dy;              

                
                    // verificar se o bloco é um obstaculo neste caso parede e coloca a parede que viu como visivel e vista
                    if (map[cx * st->nCols + cy].isWall == 1){
                        map[cx * st->nCols + cy].isVisible = 1;
                        map[cx * st->nCols + cy].seen = 1;
                        isObject=1;
                        break;                        
                    }

                    //se is object esta a zero significa que ainda nao encontrou o primeiro obstaculo ainda por isso marca essas posiçoes como visivel e visto
                    if(!isObject){
                    map[cx * st->nCols + cy].isVisible = 1;
                    map[cx * st->nCols + cy].seen = 1;
                    } else map[cx * st->nCols + cy].isVisible = 0;
                 }
                } else {
                    map[i * st->nCols + j].isVisible = 0;// esta fora da range

            } 
                }
        }
    }