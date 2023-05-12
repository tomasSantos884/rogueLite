#ifndef ___MAPA_H___
#define ___MAPA_H___


#include "state.h"

void setBorders(STATE *s, int nRows, int nCols, int borderLength);

void fillMap(struct state *s, int nRows,int nCols);

#endif
