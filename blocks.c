//blocos que compoem o mapa

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#define WALL '#'
#define CAVE '-'
#define FLOOR '.'


void insertBlock(int a) {

   // enable color output
    start_color();

    // define a cor, nº é o nº do par para chamar quando queremos usar, a primeira cor é a cor do caracter, a segunda cor é a cor de fundo
    init_pair(1, COLOR_WHITE, COLOR_BLACK);  // cores para parede
    init_pair(2, COLOR_GREEN, COLOR_BLACK);  //cores para chao
    init_pair(3, COLOR_YELLOW, COLOR_RED);   // cores para cavernas

    // turn on the color pair 

     if (a == 1){
      attron(COLOR_PAIR(1));
      printw ("%c", WALL);
      attroff(COLOR_PAIR(1));
   } else {
      attron(COLOR_PAIR(2));
      printw ("%c", FLOOR);
      attroff(COLOR_PAIR(2));
   }
}