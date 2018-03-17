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
	
	int x, y, c, n;
	cout <<"ITERACIONES?: ";	
	cin >> c;
	ptrNodo save = computarFx(0, 0, c);//Obtenemos el puntero de la ultimo punto generado	
	
	_init();//La interfaz Grafica
	unirPuntos(save);
	
	free(save);//libera la memoria usada
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
	insertar(&pila, x,y);
	for ( int f = 1; f<iters; f++){
		getXY(x,y);
		//cout <<"("<<x<<","<<y<<")";
		insertar(&pila, x,y);
	}
	return pila;
}


