//blocos que compoem o mapa

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#define WALL '#'
#define CAVE '-'
#define FLOOR '.'

void initializeBlocks(BLOCK* map,STATE *st){
   for (int i = 0; i < st->nRows; i++)
   {
      for (size_t j = 0; j < st->nCols; j++)
      {
         map[i * st->nCols + j].isWall = 0;
         map[i * st->nCols + j].seen = 0;
         map[i * st->nCols + j].isVisible = 0;
      }
   }
}


void insertBlock(int isWall, int isVisible, int seen) {
    // enable color output
    start_color();

    // define a cor, nº é o nº do par para chamar quando queremos usar, a primeira cor é a cor do caracter, a segunda cor é a cor de fundo
    init_pair(1, COLOR_WHITE, COLOR_BLACK); // cores para parede e visivel
    init_pair(2, COLOR_GREEN, COLOR_BLACK); // cores para chao visto e visivel
    init_pair(3, COLOR_MAGENTA, COLOR_MAGENTA); // efeito nao visivel mas ja foi visto
    init_pair(4, COLOR_YELLOW, COLOR_RED); // cores para cavernas

    // turn on the color pair
    if (isWall && isVisible) {
        attron(COLOR_PAIR(1));
        attroff(COLOR_PAIR(3));
        printw("%c", WALL);
        attroff(COLOR_PAIR(1));
    } else if (isWall && !isVisible && seen) {
        attron(COLOR_PAIR(1));
        attron(COLOR_PAIR(3));
        printw("%c", WALL);
        attroff(COLOR_PAIR(3));
        attroff(COLOR_PAIR(1));
    } else if (!isWall && isVisible) {
        attron(COLOR_PAIR(2));
        attroff(COLOR_PAIR(3));
        printw("%c", FLOOR);
        attroff(COLOR_PAIR(2));
    } else if (!isWall && !isVisible && seen) {
        attron(COLOR_PAIR(2));
        attron(COLOR_PAIR(3));
        printw("%c", FLOOR);
        attroff(COLOR_PAIR(3));
        attroff(COLOR_PAIR(2));
    } else {
        printw("%c", ' ');
    }
}
