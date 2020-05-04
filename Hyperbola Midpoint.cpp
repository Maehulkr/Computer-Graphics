#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>

using namespace std;
 
void hyperbola_draw(float xc, float yc, float a, float b)
{
	float x,y,d,fx,fy;
	d=b*b*(a+0.5)*(a+0.5)-a*a-a*a*b*b;
	x=a;
	y=0;
	fx=2*b*b*a;
	fy=0;
	setcolor(MAGENTA);
	line(0,240,640,240);
	line(320,0,320,480);
	while(abs(fy)<=fx)
	{
		if(d>=0)
		{
			d=d-a*a*(2*y+3);
		}
		else
		{
			d=d-a*a*(2*y+3)+b*b*(2*x+2);
			x++;
			fx=fx+2*b*b;
		}
		y++;
		fy=fy+2*a*a;
		putpixel(x+320+xc,240-y-yc,GREEN);
		putpixel(x+320+xc,240+y-yc,GREEN);
		putpixel(-x+320+xc,240-y-yc,GREEN);
		delay(20);
		putpixel(-x+320+xc,240+y-yc,GREEN);
		delay(20);
	}
	x=a/2;
	y=a;
	d=-a;
	while(y<3*a)
	{
		x++;
		if(d>=0)
		{
			d=d-2*a;
		}
		else
		{
			d=d+2*y+2-2*a;
			y++;
		}
		putpixel(x+320+xc,240-y-yc,RED);
		delay(20);
		putpixel(x+320+xc,240+y-yc,RED);
		delay(20);
	}
}

int main()
{
	int gd=DETECT, gm;
	float a, b;
	cout<<"Enter a and b\n";
	cin>>a>>b;
	initgraph(&gd,&gm," ");
	hyperbola_draw(0,0,a,b);
	getch();
	return 0;
}
