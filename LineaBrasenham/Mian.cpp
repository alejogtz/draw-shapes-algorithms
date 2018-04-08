#include "Pila.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;
ptrNodo pointsOfLine(int, int, int, int);

int main(){
	int x0,y0,x1,y1;
	cin >> x0;
	cin >> y0;
	cin >> x1;
	cin >> y1;
	ptrNodo test = pointsOfLine(x0,y0,x1,y1);
	listarPila(test);
	 return 0;
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

