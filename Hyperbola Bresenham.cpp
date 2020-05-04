#include<iostream>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>

using namespace std;

void plotpixel(int x, int y)
{
	putpixel((x+300),(240-y),15);
	putpixel((-x+300),(240-y),15);
	putpixel((x+300),(240+y),15);
	putpixel((-x+300),(240+y),15);
	delay(20);
}

void hyperbola_draw(double a,double b)
{
	int cx=0, cy=0;
	setcolor(BLUE);
	line(300,0,300,479);
	setcolor(RED);
	line(0,240,639,240);
	double x=a,y=0;  /* initial coorodinates */
	double d1 = (2*a*a) - (b*b) - (2*a*b*b);
	plotpixel(x,y);
	while((a*a*y) <= (b*b*x))
	{
		if(d1<= (-1*b*b*0.5))
		{
			d1+= 2*a*a*(2*y+3);
			plotpixel(x,y);
			y++;
		}
		else
		{
			d1+= 2*a*a*(2*y+3) - 4*b*b*(x+1);
			plotpixel(x,y);
			x++;
			y++;
		}
		plotpixel(x,y);
	}
	d1 = a*a*(y+1)*(y+1) + a*a*y*y + 2*a*a*b*b - 2*a*a*b*b*(x+1)*(x+1);
	while(y<220)
	{
		if(d1<= (a*a*0.5))
		{
			d1+= a*a*4*(y+1) - 2-a*a*b*b*(2*x+3)*(2*x+3);
			y++;
			x++;
		}
		else
		{
			d1+= -2.0*b*b*a*a*(2*x+3);
			x++;
		}
		plotpixel(x,y);
	}
}

int main()
{
	double a,b;
	cout<<"Enter a and b\n";
	cin>>a>>b;
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, " ");
	hyperbola_draw(a,b);
	getch();
	closegraph();
	return 0;
}
