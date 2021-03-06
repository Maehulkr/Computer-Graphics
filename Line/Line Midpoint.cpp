#include<iostream>
#include<graphics.h>
#include<conio.h> 
using namespace std; 

// midPoint function for line generation 
void midPoint(int X1, int Y1, int X2, int Y2) 
{ 
	// calculate dx & dy 
	int dx = X2 - X1; 
	int dy = Y2 - Y1; 

	// initial value of decision parameter d 
	int d = dy - (dx/2); 
	int x = X1, y = Y1; 

	// Plot initial given point 
	putpixel(x,y,WHITE); 
	
	// iterate through value of X 
	while (x < X2) 
	{ 
		x++; 

		// E or East is chosen 
		if (d < 0) 
			d = d + dy; 

		// NE or North East is chosen 
		else
		{ 
			d += (dy - dx); 
			y++; 
		} 

		// Plot intermediate points 
		putpixel(x,y,WHITE); 
	} 
} 

int main() 
{ 
	int gd = DETECT, gm; 
	int X1, Y1, X2, Y2; 
	cout<<"Coordinates of point A\n";
	cin>>X1>>Y1;
	cout<<"Coordinates of point B\n";
	cin>>X2>>Y2;
	//iniitalise the graphics function
	initgraph (&gd, &gm, "");
	midPoint(X1, Y1, X2, Y2); 
	getch();
	return 0; 
} 

