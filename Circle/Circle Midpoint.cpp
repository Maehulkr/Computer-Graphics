// C++ program for implementing 
// Mid-Point Circle Drawing Algorithm 
#include<iostream> 
#include<graphics.h>
#include<conio.h>
using namespace std; 
void drawcircle(int x0, int y0, int radius)
{
    int x = radius;
    int y = 0;
    int err = 0;
 
    while (x >= y)
    {
	putpixel(x0 + x, y0 + y, 7);
	putpixel(x0 + y, y0 + x, 7);
	putpixel(x0 - y, y0 + x, 7);
	putpixel(x0 - x, y0 + y, 7);
	putpixel(x0 - x, y0 - y, 7);
	putpixel(x0 - y, y0 - x, 7);
	putpixel(x0 + y, y0 - x, 7);
	putpixel(x0 + x, y0 - y, 7);
 
	if (err <= 0)
	{
	    y += 1;
	    err += 2*y + 1;
	}
 
	if (err > 0)
	{
	    x -= 1;
	    err -= 2*x + 1;
	}
    }
}
int main() 
{ 
	int gd=DETECT, gm;
	int xcenter, ycenter, radius;
	cout<<"Enter the center of circle\n";
	cin>>xcenter>>ycenter;
	cout<<"Enter the radius of the circle ";
	cin>>radius; 
	initgraph(&gd, &gm, " ");
	drawcircle(xcenter, ycenter, radius);
	getch(); 
	return 0; 
} 

