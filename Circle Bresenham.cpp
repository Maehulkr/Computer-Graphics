#include<iostream>
#include<graphics.h>
#include<conio.h> 

using namespace std;

//function for drawing the circle 
void drawCircle(int xc, int yc, int x, int y) 
{ 
	putpixel(xc+x, yc+y, RED); 
	putpixel(xc-x, yc+y, RED); 
	putpixel(xc+x, yc-y, RED); 
	putpixel(xc-x, yc-y, RED); 
	putpixel(xc+y, yc+x, RED); 
	putpixel(xc-y, yc+x, RED); 
	putpixel(xc+y, yc-x, RED); 
	putpixel(xc-y, yc-x, RED); 
} 

void circleBres(int xc, int yc, int r) 
{ 
	int x = 0, y = r; 
	int d = 3 - 2 * r; 
	drawCircle(xc, yc, x, y); 
	while (y >= x) 
	{ 
		x++; 
		if (d > 0) 
		{ 
			y--; 
			d = d + 4 * (x - y) + 10; 
		} 
		else
			d = d + 4 * x + 6; 
		drawCircle(xc, yc, x, y);
	} 
} 
int main() 
{ 
	int xc, yc, r; 
	int gd = DETECT, gm; 
	cout<<"Enter the coordinates of the circle\n";
	cin>>xc>>yc;
	cout<<"Enter the radus of the circle ";
	cin>>r;
	initgraph(&gd, &gm, ""); // initialize graph 
	circleBres(xc, yc, r); // function call 
	getch();
	return 0; 
} 

