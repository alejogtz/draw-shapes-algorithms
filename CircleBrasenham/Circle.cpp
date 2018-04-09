#include<graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;
void MakeCircle(int Xc, int Yc, int r){
	int x,y,p;
	x=0;
	y=r;
	//pintamos el primer pixel obtenido por el valor del radio dado(Xc,Yc+r) y los pixeles simetricoss
	putpixel(Xc,Yc+r,GREEN);
	putpixel(Xc,Yc-r,GREEN);
	putpixel(Xc+r,Yc,GREEN);
	putpixel(Xc-r,Yc,GREEN);
	
	//calculamos error (parametro de decision)
	p=1-r;
	//iteramos hasta x menor a y
	while(x<y){
		if(p>0){
			y=y-1;
			x=x+1;
			p=p+2*(x-y)+1;
		}
		else{
			x=x+1;
			p=p+2*x+1;
		}
		//pintamos el pixel calculado y los pixeles simetricos a este
		putpixel(Xc+x,Yc+y,GREEN);
			
		putpixel(Xc-x,Yc+y,GREEN);
			
		putpixel(Xc+x,Yc-y,GREEN);
			
		putpixel(Xc-x,Yc-y,GREEN);
			
		putpixel(Xc+y,Yc+x,GREEN);
			
		putpixel(Xc-y,Yc+x,GREEN);
			
		putpixel(Xc+y,Yc-x,GREEN);
			
		putpixel(Xc-y,Yc-x,GREEN);
		
	}
}
	
int main(){   	   	
   
	int gd = DETECT, gm;
   	initgraph(&gd, &gm, "C:\\TC\\BGI");
                    // Valor de X, Valor en Y, El radio
   	MakeCircle(10,10,50);
   	
   	delay(500);
	getch();	
  	closegraph();
  	return 0;	
}