#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>
using namespace std;
int a, b, c, d;
typedef struct coordinate
{
	int x,y;
	char code[4];
}PT;

PT setcode(PT p)
{
PT ptemp;
if(p.y>=d)
ptemp.code[0]='1'; /* TOP */
else
ptemp.code[0]='0';
if(p.y<=b)
ptemp.code[1]='1'; /* BOTTOM */
else
ptemp.code[1]='0';
if (p.x>=c)
ptemp.code[2]='1'; /* RIGHT */
else
ptemp.code[2]='0';
if (p.x<=a)      /* LEFT */
ptemp.code[3]='1';
else
ptemp.code[3]='0';
ptemp.x=p.x;
ptemp.y=p.y;
return(ptemp);
}


int visibility (PT p1,PT p2)
{
int i,flag=0;
for(i=0;i<4;i++)
{
if((p1.code[i]!='0')||(p2.code[i]!='0'))
flag=1;
}
if(flag==0)
return(0);
for(i=0;i<4;i++)
{
if((p1.code[i]==p2.code[i]) &&(p1.code[i]=='1'))
flag=0;
}
if(flag==0)
return(1);
return(2);
}


void midsub(PT p1,PT p2)
{
 PT mid;
 int v;
 p1=setcode(p1);
 p2=setcode(p2);
 v=visibility(p1,p2);
 switch(v)
  {
  case 0:  /* Line conpletely visible */
    line(p1.x,p1.y,p2.x,p2.y);
    break;
  case 1:  /* Line completely invisible */
    break;
  case 2:  /* line partly visible */
    mid.x = p1.x + (p2.x-p1.x)/2;
    mid.y = p1.y + (p2.y-p1.y)/2;
    midsub(p1,mid);
    mid.x = mid.x+1;
    mid.y = mid.y+1;
    midsub(mid,p2);
    break;
  }
}

int main()
{
 int gd=DETECT, gm,v;
 PT p1,p2,ptemp;
 cout<<"Enter the end point 1\n";
 cin>>p1.x>>p1.y;
 cout<<"Enter the end point 2\n";
 cin>>p2.x>>p2.y;
 cout<<"Enter the coordinates of the window\n";
 cin>>a>>b>>c>>d;
 initgraph(&gd,&gm," ");
 rectangle(a,d,c,b);
 midsub(p1,p2);
 getch();
// closegraph();
 return(0);
}

