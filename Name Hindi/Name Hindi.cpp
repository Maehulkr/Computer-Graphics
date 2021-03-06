#include<iostream>
#include<graphics.h>
#include<math.h>
#define PI 3.14

int n=15;

using namespace std;

int main(){
	int px[] = {10, 10, 0, 20, 20, 35, 35, 35, 35, 35, 35, 65, 65, 80, 0};
	int py[] = {30, 75, 66, 30, 30, 30, 33, 50, 50, 80, 80, 50, 50, 30, 30};
	int qx[] = {10, 0, 20, 20, 0, 35, 35, 35, 35, 26, 40, 60, 75, 80, 90};
	int qy[] = {60, 40, 66, 80, 10, 33, 50, 80, 65, 90, 85, 90, 45, 80, 30};
	int mag[] ={100, 100, 100, 100, 100, 1, 50, 50, 50, 50, 50, 50, 50, 100, 100};
	float degp[] = {90, 215, 0, 90, 215, 90, 180, 180, 0, 0, 180, 215, 280, 90, 0};
	float degq[] = {270, 45, 0, 270, 45, 270, 0, 0, 180, 180, 0, 45, 200, 270, 0};
	float rad, dpx[n],dpy[n],dqx[n],dqy[n];
	for (int i=0;i<n;i++){
		rad=degp[i]*(PI/180);
		dpx[i]=mag[i]*cos(rad);
		dpy[i]=mag[i]*sin(rad);	
		rad=degq[i]*(PI/180);
		dqx[i]=mag[i]*cos(rad);
		dqy[i]=mag[i]*sin(rad);	
	}
	int gd=DETECT,gm;
	initgraph(&gd,&gm," ");
	for(int i=0;i<n;i++){
	//	cout<<"( "<<px[i]<<" , "<<py[i]<<" )";
	//	cout<<"\t( "<<qx[i]<<" , "<<qy[i]<<" )\n";
		for(float u=0;u<1;u+=0.001){
			float h1 =  2*pow(u,3)-3*pow(u,2) + 1;          // calculate basis function 1
 			float h2 = -2*pow(u,3) + 3*pow(u,2);              // calculate basis function 2
  			float h3 =   pow(u,3) - 2*pow(u,2) + u;         // calculate basis function 3
  			float h4 =   pow(u,3) -  pow(u,2);              // calculate basis function 4
  			float x=px[i]*h1+qx[i]*h2+dpx[i]*h3+dqx[i]*h4;
			float y=py[i]*h1+qy[i]*h2+dpy[i]*h3+dqy[i]*h4;
			putpixel(x,y,RED);
	//		cout<<"x = "<<x<<" y = "<<y<<endl;
		}
	//	cout<<"----------------------------------------------------------------------------------------------\n";	
	}
	getch();
	return 0;
}
