#include "Pila.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void insertar(ptrNodo *cab, int px, int py){
	ptrNodo nuevo;
	nuevo = new (struct nodo);
	nuevo->dato.x = px;
	nuevo->dato.y = py;
	nuevo->siguiente = *cab;
	*cab = nuevo;
}

punto pop(ptrNodo *ptrCima){
	ptrNodo ptrTemp; /* apuntador a un nodo temporal */
	punto valorElim; /* valor del nodo */
	ptrTemp = *ptrCima;/*Note que *ptrCima desreferencia y devuelve otr puntero, esta vez al nodo real*/
	valorElim = ( *ptrCima )->dato;
	*ptrCima = ( *ptrCima )->siguiente;
	free( ptrTemp );/*Analizar esta linea de codigo->Maybe libera el espacio de memoria*/
	return valorElim;
}

ptrNodo flip(ptrNodo *ptrCima){
	ptrNodo nuevaPila = NULL;//importante inicializar los punteros en un metodo.
	punto actual;
	while ((*ptrCima)!= NULL ){		
		actual = pop(ptrCima);		
		//cout << *ptrCima<<endl; 
		insertar(&nuevaPila, actual.x, actual.y);
	}
	return nuevaPila;
}

void listarPila(ptrNodo cab){
	int c = 0;
	while(cab!=NULL){	
		cout << ++c<<"-> [" << cab->dato.x <<"\t,  "<< cab->dato.y <<endl;
		cab = cab->siguiente;
	}
}
