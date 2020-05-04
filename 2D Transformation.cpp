#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

int main()
{
int ch;
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");

setcolor(6);
outtextxy (100,88,"Object.");
rectangle(100,150,150,100);

int tx,ty;
printf("Enter the factors for translation\ntx: ");
scanf("%d",&tx);
printf("ty: ");
scanf("%d",&ty);

int sx,sy;
printf("Enter the factors for scaling\nsx: ");
scanf("%d",&sx);
printf("sy: ");
scanf("%d",&sy);

float theta;
printf("Enter the angle for rotation: ");
scanf("%f",&theta);

int x1,x2,x3,x4;
int y1,y2,y3,y4;
int ax1,ax2,ax3,ax4,ay1,ay2,ay3,ay4;
int refx,refy;
theta=theta*(3.14/180);
refx=(100+tx)*sx;
refy=(100+ty)*sy;

x1=(100+tx)*sx;
y1=(100+ty)*sy;
x2=(150+tx)*sx;
y2=(100+ty)*sy;
x3=(150+tx)*sx;
y3=(150+ty)*sy;
x4=(100+tx)*sx;
y4=(150+ty)*sy;

ax1=refy+(x1-refx)*cos(theta)-(y1-refy)*sin(theta);
ay1=refy+(x1-refx)*sin(theta)+(y1-refy)*cos(theta);

ax2=refy+(x2-refx)*cos(theta)-(y2-refy)*sin(theta);
ay2=refy+(x2-refx)*sin(theta)+(y2-refy)*cos(theta);

ax3=refy+(x3-refx)*cos(theta)-(y3-refy)*sin(theta);
ay3=refy+(x3-refx)*sin(theta)+(y3-refy)*cos(theta);

ax4=refy+(x4-refx)*cos(theta)-(y4-refy)*sin(theta);
ay4=refy+(x4-refx)*sin(theta)+(y4-refy)*cos(theta);

line(ax1,ay1,ax2,ay2);
line(ax2,ay2,ax3,ay3);
line(ax3,ay3,ax4,ay4);
line(ax4,ay4,ax1,ay1);


getch();
closegraph();
return 0;
}
