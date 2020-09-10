#include<stdio.h> 
#include<graphics.h> 
#include<iostream>
using namespace std;

int abs (int n) 
{ 
	return ( (n>0) ? n : ( n * (-1))); 
} 

void DDA(int X0, int Y0, int X1, int Y1) 
{ 
	// how much to be moved
	int dx = X1 - X0; 
	int dy = Y1 - Y0; 

	// calculate steps required for generating pixels 
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 

	// calculate increment in x & y for each steps 
	float Xinc = dx / (float) steps; 
	float Yinc = dy / (float) steps; 

	// Put pixel for each step 
	float X = X0; 
	float Y = Y0; 
	for (int i = 0; i <= steps; i++) 
	{ 
		putpixel(X,Y,5); // put pixel at (X,Y) 
		X += Xinc;		 // increment in x at each step 
		Y += Yinc;		 // increment in y at each step 
		delay(10);	 // for visualization of line-generation step by step 
	}
	return;
} 

int main() 
{ 
	int points[4];

	cout<<"Enter coordinates:"<<endl;
	
	// take coordinates from user
	for(int i=0;i<4; i++)
		cin>>points[i];

	int gd = DETECT, gm; 
	initgraph (&gd, &gm, "C:\\Dev-Cpp\\MinGW64\\lib");
	
	DDA(points[0], points[1], points[2], points[3]);
	
	getch();
	return 0; 
} 

