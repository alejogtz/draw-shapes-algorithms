#ifndef GRAFICADOR_H
#define GRAFICADOR_H

#include "Pila.h"

void _init();/*Prepara el entorno grafico*/

void finalizar();

void linea(punto x1, punto x2);/*Traza una linea entre 2 puntos*/

ptrNodo pointsOfLine(int, int, int, int);/*Obtener los puntos a graficar*/

void graficaPuntos(ptrNodo);

void plotPoints(ptrNodo);

#endif
