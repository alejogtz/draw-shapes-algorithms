#include "Graficador.h"
#include "Pila.h"

#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

ptrNodo pila;//Entrada a la pila

/*Prototipos*/
void getXY(float& x, float& y);
ptrNodo computarFx(float, float, int);

int main(){
	/*Randomizar el generador de aleatorios*/
	srand(time(0));
	/*Numero de iteraciones*/
	int x, y, c, n;
	cout <<"ITERACIONES?: ";	
	cin >> c; 	
	/*Ejecutar Funcion especifica y obtener los puntos a graficar xD;
		---Obtenemos el puntero de la ultimo punto generado---*/
	ptrNodo save = computarFx(0, 0, c);
	/*Inicializar la interfaz Grafica*/
	_init();
	/*Graficar los puntos generados por la funcion*/
	//graficaPuntos(save);
	plotPoints(save);
	
	/*Finalizar Graphics*/
	finalizar();
	/*libera la memoria usada*/
	free(save);
}
float rnd() {
    return static_cast<float>( rand() ) / static_cast<float>( RAND_MAX );
}

void getXY( float& x, float& y ) {
        float g, xl, yl;
        g = rnd();
        if( g < .01f ) { xl = 0; yl = .16f * y; } 
        else if( g < .07f ) {
            xl = .2f * x - .26f * y;
            yl = .23f * x + .22f * y + 1.6f;
        } else if( g < .14f ) {
            xl = -.15f * x + .28f * y;
            yl = .26f * x + .24f * y + .44f;
        } else {
            xl = .85f * x + .04f * y;
            yl = -.04f * x + .85f * y + 1.6f;
        }
        x = xl; y = yl;
}
    
ptrNodo computarFx(float x, float y, int iters){
	const int BMP_SIZE = 600;
	/*Variables para el ajuste del fractal en la pantalla*/
	int hs = BMP_SIZE >> 1;

	insertar(&pila, int(x),int(y));
	for ( int f = 1; f<iters; f++){
		getXY(x,y);
		/*Insertar con ajuste de acuerdo al algoritmo de Wikipedia*/
		insertar(&pila, hs + int(x*55.f), BMP_SIZE- 15 - int(y*55.f));
	}
	return pila;
}


