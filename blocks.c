//blocos que compoem o mapa

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#include "mapa.h"

#include "state.h"


//funçao serve para inicializar todos os blocos do mapa com as propriedades de é parede, visto e visivel a zero
void initializeBlocks(BLOCK* map,STATE *st){
   for (int i = 0; i < st->nRows; i++)
   {
      for (size_t j = 0; j < (size_t)st->nCols; j++)
      {
         map[i * st->nCols + j].isWall = 0;
         map[i * st->nCols + j].seen = 0;
         map[i * st->nCols + j].isVisible = 0;
      }
   }
}

//funçao pinta cada bloco do mapa consoante as suas propriedades
void drawMap(BLOCK *map,STATE *st){
	for (int i = 0; i < st->nRows; i++){
		for (int j = 0; j < st->nCols; j++){
			if (map[i * st->nCols + j].isWall == 1 && map[i * st->nCols + j].isVisible == 1){ //se for parede e estiver visivel desenha '#' branco
				attron(COLOR_PAIR(COLOR_WHITE));
				mvaddch(i, j, '#' | A_BOLD);
				attroff(COLOR_PAIR(COLOR_WHITE));
			} else if (map[i * st->nCols + j].isWall == 0 && map[i * st->nCols + j].isVisible == 1){ //se for chao e estiver visivel desenha '.' branco
                attron(COLOR_PAIR(COLOR_YELLOW));
				mvaddch(i, j, '.' | A_BOLD);
				attroff(COLOR_PAIR(COLOR_YELLOW));
            } else if (map[i * st->nCols + j].isWall == 1 && map[i * st->nCols + j].isVisible == 0 && map[i * st->nCols + j].seen == 1){ //se for parede e nao estiver visivel mas ja foi visto desenha '#' azul
                attron(COLOR_PAIR(COLOR_BLUE));
				mvaddch(i, j, '#' | A_BOLD);
				attroff(COLOR_PAIR(COLOR_BLUE));
            } else if (map[i * st->nCols + j].isWall == 0 && map[i * st->nCols + j].isVisible == 0 && map[i * st->nCols + j].seen == 1){ //se for chao e estiver visivel desenha '.' azul
                attron(COLOR_PAIR(COLOR_BLUE));
				mvaddch(i, j, '.' | A_BOLD);
				attroff(COLOR_PAIR(COLOR_BLUE));
            } else if (map[i * st->nCols + j].isVisible == 0 && map[i * st->nCols + j].seen == 0){ //se um bloco nao esta visivel e nunca foi visto desenha um espaço vazio
                attron(COLOR_PAIR(COLOR_BLACK));
				mvaddch(i, j, ' ' | A_BOLD);
				attroff(COLOR_PAIR(COLOR_BLACK));
            }
		}
	}
}
