#include<iostream>
#include<graphics.h>
#include<conio.h> 
using namespace std; 

// function for line generation 
void bresenham(int x1, int y1, int x2, int y2) 
{ 
	int m_new = 2 * (y2 - y1); 
	int slope_error_new = m_new - (x2 - x1); 
	for (int x = x1, y = y1; x <= x2; x++) 
	{ 
		putpixel(x,y,WHITE);
		// Add slope to increment angle formed 
		slope_error_new += m_new; 
		if (slope_error_new >= 0) 
		{ 
			y++; 
			slope_error_new -= 2 * (x2 - x1); 
		}	 
	}	 	
} 

int main() 
{ 
	int gd=DETECT, gm;
	int x1, y1, x2, y2;
	cout<<"Enter the coordinates of point A ";
	cin>>x1>>y1;
	cout<<"Enter the coordinates of point B ";
	cin>>x2>>y2; 
	initgraph(&gd, &gm, " ");
	bresenham(x1, y1, x2, y2); 
	getch();
	return 0; 
} 

