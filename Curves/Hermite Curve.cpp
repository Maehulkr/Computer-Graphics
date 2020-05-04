#include<iostream>
#include<graphics.h>
#include<math.h>
#define PI 3.14
using namespace std;
int main(){
	int px,py,qx,qy,mag;
	float deg, rad,dpx,dpy,dqx,dqy;
	cout<<"Enter the coordinates of Pk:\n";
	cin>>px>>py;
	cout<<"Enter the magnitude of the tangent vector at Pk: ";
	cin>>mag;
	cout<<"Enter the slope of tangent vector at Pk: ";
	cin>>deg;
	rad=deg*(PI/180);
	dpx=mag*cos(rad);
	dpy=mag*sin(rad);	
	cout<<"Enter the coordinates of P(k+1):\n";
	cin>>qx>>qy;
	cout<<"Enter the magnitude of the tangent vector at P(k+1): ";
	cin>>mag;
	cout<<"Enter the slope of tangent vector at P(k+1): ";
	cin>>deg;
	rad=deg*(PI/180);
	dqx=mag*cos(rad);
	dqy=mag*sin(rad);
	int gd=DETECT,gm;
	initgraph(&gd,&gm," ");
	for(float u=0;u<1;u+=0.001){
		float h1 =  2*pow(u,3)-3*pow(u,2) + 1;          // calculate basis function 1
 		float h2 = -2*pow(u,3) + 3*pow(u,2);              // calculate basis function 2
  		float h3 =   pow(u,3) - 2*pow(u,2) + u;         // calculate basis function 3
  		float h4 =   pow(u,3) -  pow(u,2);              // calculate basis function 4
  		float x=px*h1+qx*h2+dpx*h3+dqx*h4;
		float y=py*h1+qy*h2+dpy*h3+dqy*h4;
		putpixel(x,y,RED);
	}
	getch();
	return 0;
}
