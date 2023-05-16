#ifndef ___MAPA_H___
#define ___MAPA_H___


#include "state.h"

void setBorders(BLOCK* map,STATE *st);

void fillMap(BLOCK* map,STATE *st);

void genMap(BLOCK* map,STATE *st);

void drawMap(BLOCK *map,STATE *st);

int wallCountInRad(BLOCK* map, int posX, int posY, int radius,STATE *st);

#endif
