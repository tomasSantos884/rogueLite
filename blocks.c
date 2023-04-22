//blocos que compoem o mapa

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#define WALL '#'
#define CAVE '-'
#define FLOOR '.'


char insertBlock(int a) {
   if (a == 0) return FLOOR;
   if (a == 1) return WALL;
   if (a == 2) return CAVE;
   return '?'; // handle unknown input
}
