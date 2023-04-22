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
   if (a == 0) printw ("%c", FLOOR);
   if (a == 1) printw ("%c", CAVE);
   if (a == 2) printw ("%c", WALL);
}
