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

    // define a color pair with white foreground and black background
    init_pair(1, COLOR_WHITE, COLOR_BLACK);

    // turn on the color pair
   if (a == 0){
      attron(COLOR_PAIR(1));
      printw ("%c", FLOOR);
      attroff(COLOR_PAIR(1));
   } 
      if (a == 1){
      attron(COLOR_PAIR(1));
      printw ("%c", CAVE);
      attroff(COLOR_PAIR(1));
   } 
      if (a == 2){
      attron(COLOR_PAIR(1));
      printw ("%c", WALL);
      attroff(COLOR_PAIR(1));
   }
}