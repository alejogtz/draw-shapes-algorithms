#ifndef PILA_H
#define PILA_H

struct punto{
	int x;
	int y;
};

struct nodo{
	punto dato;
	struct nodo *siguiente;
};

typedef nodo *ptrNodo;

void insertar(ptrNodo *p, int, int);

punto pop(ptrNodo *p);

ptrNodo flip(ptrNodo *p);

void listarPila(ptrNodo cab);
#endif
