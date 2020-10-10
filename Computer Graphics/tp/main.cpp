#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<math.h>

using namespace std;

void draw_poly(int n, int x[], int y[])
{
  for(int i=0; i<n-1; i++)
	line(x[i],y[i],x[i+1],y[i+1]);
	
	// close the polygon
    line(x[0],y[0],x[n-1],y[n-1]);
    
    return;
}

//void translate(int &x1,int &y1, int n, int x[], int y[])
//{
//  for(int i=0; i<n; i++)
//  {
//    x[i] = x[i] + x1;
//    y[i] = y[i] + y1;
//  }
//  
//  return;
//}

//void scale(int &x1,int &y1)
//{
//  int a,b;
//  a=x[0];
//  b=y[0];
//  translate(-a,-b);
//  int i;
//  for(i=0;i<n;i++)
//  {
//    x[i]=x[i]*x1;
//    y[i]=y[i]*y1;
//
//  }
//  translate(a,b);
//
//}
//
//void rotate(float theta)
//{
//  int a,b,i,c,d;
//  a=x[0];
//  b=y[0];
//  translate(-a,-b);
//  for(i=0;i<n;i++)
//  {
//    c=x[i]*cos(theta)-y[i]*sin(theta);
//    d=x[i]*sin(theta)+y[i]*cos(theta);
//    x[i]=c;
//    y[i]=d;
//  }
//  translate(a,b);
//}


int main()
{	
	
	int gdriver = DETECT, gmode;
	
	//initialize graphics
	initgraph(&gdriver, &gmode, "");
	
	line(0, getmaxy()/2, getmaxx(), getmaxy()/2);
	line(getmaxx()/2, 0, getmaxx()/2, getmaxy());
	
	int xFactor, yFactor, n;
	
	// Type of Polygon
	cout<<"\nEnter no. of Sides:: ";
	cin>>n;
	
	int EdgeX[n], EdgeY[n];
	cout<<"\nEnter the Co-ordinate of Vertices:: ";	
	
	for(int i=0; i<n; i++)
	    cin>>EdgeX[i]>>EdgeY[i];
	
	cout<<"\nEnter the X-factor to translate";
	cin>>xFactor;
	cout<<"\nEnter the Y-factor to translate";
	cin>>yFactor;
	
	draw_poly(n, EdgeX, EdgeY);
	
//	translate(xFactor, yFactor, n, EdgeX, EdgeY);
  for(int i=0; i<n; i++)
  {
    EdgeX[i] = EdgeX[i] + xFactor;
    EdgeX[i] = EdgeY[i] + yFactor;
  }
	
   	draw_poly(n, EdgeX, EdgeY);
   	
	getch();
   
   
   
   
   
   
   
   
   
   
   
//
//            cout<<"\nFor x-axis::";
//            cin>>x1;
//            cout<<"\nFor y-axis::";
//            cin>>y1;
//            translate(x1,y1);
//            draw_poly();
//            getch();
//            cleardevice();

//        case 2:
//            cout<<"\nEnter the Angle::";
//            cin>>theta;
//            rotate(theta);
//            draw_poly();
//            getch();
//            cleardevice();
//            break;
//
//        case 3:
//            cout<<"\nFor x-axis::";
//            cin>>x1;
//            cout<<"\nFor y-axis::";
//            cin>>y1;
//            scale(x1,y1);
//            draw_poly();
//            getch();
//            cleardevice();
//            break;

   return 0;
}

