#include<graphics.h>
#include<conio.h>//La librería conio se utiliza más que nada por sus comandos: getch(), clrscr(), gotoxy(), textcolor(), y textbackground()
#include<dos.h>//es una librería de C++ que contiene funciones muy útiles como delay, sound, etc. 
#include <iostream>

#include "Graficador.h"

using namespace std;

void _init(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	delay(2000);
}

void finalizar(){
		getch();
	closegraph();
}

void linea(punto p0, punto p1){
	/*Obtener los puntos a pintar*/
	ptrNodo aux = pointsOfLine(p0.x, p0.y, p1.x, p1.y);
	while (aux!=NULL){
		putpixel(aux->dato.x, aux->dato.y, RED);
		aux = aux->siguiente;
	}
}

ptrNodo pointsOfLine(int x0, int y0, int x1, int y1){
	int inc = 1, aux, constP, dx, dy;
	ptrNodo sPila = NULL;	
	/*Calcular valor dx y dy signados*/
	dx = x1-x0;
	dy = y1-y0;	
	
	/*Verificar si la linea es descendente o ascendente*/	
	if (dx*dy<0) inc = -1;
	/*ajustar a valores absolutos dx y dy */
	dx = abs(dx); dy = abs(dy);
	
	/*Verificar sobre que eje se va a iterar X o Y*/
	bool sobreX = false;
	if (dx>=dy) 
		sobreX = true;
		
	/*Resolver el problema de los puntos iniciales:.*/
	if ((sobreX & x1<x0) ||  (!sobreX & y1<y0)){
		/*Intercambiar x's*/
		aux = x1; x1 = x0; x0 = aux;
		/*Intercambiar y's*/
		aux = y1; y1 = y0; y0 = aux;
	}
	
	/*El primer punto siempre estará en la Pila*/
	insertar(&sPila, x0, y0);
				
	/*Iterar en X*/
	if ( sobreX) {
		constP = 2*dy - dx;
		while(x0<x1){
			if (constP<0){
				x0 = x0 + 1;				
				constP = constP + 2*(dy);
			}else {
				x0 = x0 + 1; y0 = y0 + inc;				
				constP = constP + 2*(dy-dx);
			}
			insertar(&sPila, x0, y0);
		}		
	}else{		
	/*Iterar en Y*/
		constP = (2*dx)- dy;		
		while(y0<y1){	
			if (constP<0){
				y0 = y0 + 1;
				constP = constP + 2*dx;
			}else {
				x0 = x0 + inc; y0 = y0 + 1;
				constP = constP + 2*(dx-dy);
			}
			insertar(&sPila, x0, y0);
		}
	}	
	return sPila;
}

void graficaPuntos(ptrNodo cab){
	/*Trazar desde el punto p0 hasta el p1*/
	punto p0, p1;
	ptrNodo atras = NULL;
	/*Obtener */
	while(cab->siguiente!=NULL){
		 p0 = cab->dato;
		 cab = cab->siguiente;
		 p1 = cab->dato;
		 linea(p0, p1);
	}
}

void plotPoints(ptrNodo cab){
	while(cab!=NULL){
		 putpixel(cab->dato.x, cab->dato.y, GREEN);
		 cab = cab->siguiente;		 
	}
}
