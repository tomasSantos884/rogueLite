//modulo para a visibilidade do jogador

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#define RANGE_OF_SIGHT 5

// x e y sao coordenadas do jogador, rows e collums sao coordenadas do mapa
void playerVisibility(int x, int y, int rows, int collums){


    for (int i=0; i < rows; i++){
        for (int j=0; j< collums; j++){
            int dx = j - x;
            int dy = i - y;
            double distance = sqrt(dx * dx + dy * dy); // calcucar a tangente para verificar as posiçoes de uma forma circular

            if (distance <= RANGE_OF_SIGHT){
                int isObject = 0;

                // loop para verificar se existe um obstaculo entre a posiçao do jogador e a posiçao que estamos a verificar
                for (double t = 0; t< 1.0; t+= 0.1){
                    int cx = x + t * dx;
                    int cy = y + t * dy;

                    // verificar se o bloco é um obstaculo neste caso parede ou caverna
                    if (map.block blocks[cy][cx] == '#' || map.block blocks[cy][cx] == '-'){

                        isObject=1;
                        break;
                    }
                }

                if (isObject){
                    printw ("%c", ' ' );// ja encontrou uma parece por isso nao consegue ver mais 
                } else {
                    printw ("%c", map.block blocks[i][j]); // bloco visivel
                }

            } else {
                    printw ("%c", ' '); // esta fora da range
                }
        }
    }
}
