#include<graphics.h>
#include<conio.h>//La librer�a conio se utiliza m�s que nada por sus comandos: getch(), clrscr(), gotoxy(), textcolor(), y textbackground()
#include<dos.h>//es una librer�a de C++ que contiene funciones muy �tiles como delay, sound, etc. 

#include "Graficador.h"
#include <iostream>
using namespace std;
const int BMP_SIZE = 600;

void _init(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	delay(2000);
}


void unirPuntos(ptrNodo raiz){
	int hs = BMP_SIZE >> 1;

	while(raiz!=NULL){		
		putpixel(hs + int((raiz->dato.x)*55.f),
		 BMP_SIZE- 15 - ((raiz->dato.y)*55.f)
		 ,n);
		raiz = raiz->siguiente;
	}
   getch();
   closegraph();
}
