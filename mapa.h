#ifndef ___MAPA_H___
#define ___MAPA_H___

#include "state.h"

// Função para definir as bordas do mapa
void setBorders(BLOCK* map, STATE *st);

// Função para preencher o mapa com blocos
void fillMap(BLOCK* map, STATE *st);

// Função para gerar o mapa
void genMap(BLOCK* map, STATE *st);

// Função para desenhar o mapa
void drawMap(BLOCK *map, STATE *st);

// Função para contar o número de paredes dentro de um raio dado a partir de uma posição
int wallCountInRad(BLOCK* map, int posX, int posY, int radius, STATE *st);

#endif

