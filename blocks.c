//blocos que compoem o mapa

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#include "mapa.h"

#include "state.h"

#define WALL '#'
#define CAVE '-'
#define FLOOR '.'

void initializeBlocks(BLOCK* map,STATE *st){
   for (int i = 0; i < st->nRows; i++)
   {
      for (int j = 0; j < st->nCols; j++)
      {
         map[i * st->nCols + j].isWall = 0;
         map[i * st->nCols + j].seen = 0;
         map[i * st->nCols + j].isVisible = 0;
      }
   }
}

void drawMap(BLOCK *map,STATE *st){
	for (int i = 0; i < st->nRows; i++){
		for (int j = 0; j < st->nCols; j++){
			if (map[i * st->nCols + j].isWall == 1 && map[i * st->nCols + j].isVisible == 1){
				attron(COLOR_PAIR(COLOR_WHITE));
				mvaddch(i, j, '#' | A_BOLD);
				attroff(COLOR_PAIR(COLOR_WHITE));
			} else if (map[i * st->nCols + j].isWall == 0 && map[i * st->nCols + j].isVisible == 1){
                attron(COLOR_PAIR(COLOR_YELLOW));
				mvaddch(i, j, '.' | A_BOLD);
				attroff(COLOR_PAIR(COLOR_YELLOW));
            } else if (map[i * st->nCols + j].isWall == 1 && map[i * st->nCols + j].isVisible == 0 && map[i * st->nCols + j].seen == 1){
                attron(COLOR_PAIR(COLOR_BLUE));
				mvaddch(i, j, '#' | A_BOLD);
				attroff(COLOR_PAIR(COLOR_BLUE));
            } else if (map[i * st->nCols + j].isWall == 0 && map[i * st->nCols + j].isVisible == 0 && map[i * st->nCols + j].seen == 1){
                attron(COLOR_PAIR(COLOR_BLUE));
				mvaddch(i, j, '.' | A_BOLD);
				attroff(COLOR_PAIR(COLOR_BLUE));
            } else if (map[i * st->nCols + j].isVisible == 0 && map[i * st->nCols + j].seen == 0){
                attron(COLOR_PAIR(COLOR_BLACK));
				mvaddch(i, j, ' ' | A_BOLD);
				attroff(COLOR_PAIR(COLOR_BLACK));
            }
		}
	}
}
