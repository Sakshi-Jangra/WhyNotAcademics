#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>
using namespace std;


void reflection(int& Xold, int& Yold, int axis) 
{ 
	int reflMat[3][3];
	int res[3][1];
	int oldMat[3][1];
	

	oldMat[0][0] = Xold;
	oldMat[1][0] = Yold;
//	oldMat[2][0] = Zold;
	oldMat[2][0] = 1;
	
	res[2][0] = 1;
	
	if(axis == 1){
		reflMat[0][0] = -1;
		reflMat[1][1] = 1;
		reflMat[2][2] = 1;
//		reflMat[3][3] = 1;
	}
	else if(axis == 2){
		reflMat[0][0] = 1;
		reflMat[1][1] = -1;
		reflMat[2][2] = 1;
//		reflMat[3][3] = 1;
	}
	else if(axis == 3){
		reflMat[0][0] = 1;
		reflMat[1][1] = 1;
		reflMat[2][2] = -1;
//		reflMat[3][3] = 1;
	}
	
	for(int i = 0; i < 3; i++) 
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				res[i][j] += reflMat[i][k]*oldMat[k][j];  	

	Xold = res[0][0];
	Yold = res[1][0];
//	Zold = res[2][0];
	
	return;
} 


int main() 
{ 
	int gd = DETECT, gm;
	initgraph(&gd, &gm, ""); 
	setcolor(15);
		
	int vertex;
	cout<<"Enter Number of vertices of polygon: ";
	cin>>vertex;
	
	int Coordinates[vertex*2], axis, x, y;
	cout<<"(x, y) Coordinates of point: ";
	
	for(int i=0; i<2*vertex; i++)
		cin>>Coordinates[i];
	
	cout<<"Reflection by X-1 , Y-2 axis: ";
	cin>>axis;
	
	drawpoly(vertex, Coordinates);
	
	for(int i=0; i<vertex*2; i+=2){
		x = Coordinates[i];
		y = Coordinates[i+1];
		reflection(x, y, axis);
		Coordinates[i] = x;
		Coordinates[i+1] = y;
	}
	
	drawpoly(vertex, Coordinates);
	
		
	getch();

	return 0; 
} 
















































/*
						FOR #D REFLECTION
*/





/*

#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>
using namespace std;


void disp(int n,float c[][3])
{
	float maxx,maxy;
	int i;
	maxx=getmaxx();
	maxy=getmaxy();
	maxx=maxx/2;
	maxy=maxy/2;
	i=0;
	while(i<n-1)
	{
		line(maxx+c[i][0],maxy-c[i][1],maxx+c[i+1][0],maxy-c[i+1][1]);
		i++; 
	}
	
	i=n-1;
	line(maxx+c[i][0],maxy-c[i][1],maxx+c[0][0],maxy-c[0][1]);
	setcolor(GREEN);
	line(0,maxy,maxx*2,maxy);
	line(maxx,0,maxx,maxy*2);
	setcolor(WHITE);
}


void reflection(int& Xold, int& Yold, int& Zold, int axis) 
{ 
	int reflMat[4][4];
	int res[4][1];
	int oldMat[4][1];
	

	oldMat[0][0] = Xold;
	oldMat[1][0] = Yold;
	oldMat[2][0] = Zold;
	oldMat[3][0] = 1;
	
	res[3][0] = 1;
	
	if(axis == 1){
		reflMat[0][0] = 1;
		reflMat[1][1] = 1;
		reflMat[2][2] = -1;
		reflMat[3][3] = 1;
	}
	else if(axis == 2){
		reflMat[0][0] = -1;
		reflMat[1][1] = 1;
		reflMat[2][2] = 1;
		reflMat[3][3] = 1;
	}
	else if(axis == 3){
		reflMat[0][0] = 1;
		reflMat[1][1] = -1;
		reflMat[2][2] = 1;
		reflMat[3][3] = 1;
	}
	
	for(int i = 0; i < 4; i++) 
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				res[i][j] += reflMat[i][k]*oldMat[k][j];  	

	Xold = res[0][0];
	Yold = res[1][0];
	Zold = res[2][0];
	
	return;
} 


int main() 
{ 
	int gd = DETECT, gm;
	initgraph(&gd, &gm, ""); 
	
	int vertex;
	cout<<"Enter Number of vertices of polygon: ";
	cin>>vertex;
	
	int Coordinates[vertex][3], axis;
	cout<<"(x, y, z) Coordinates of point: ";
	
	for(int i=0; i<vertex; i++)
		cin>>Coordinates[i][0]>>Coordinates[i][1]>>Coordinates[i][2];
	
	cout<<"Reflection by XY-1 , YZ-2, ZX-3 axis: ";
	cin>>axis;
	
	drawpoly(vertex, Coordinates);
	
	for(int i=0; i<vertex; i++){
		reflection(Coordinates[i][0], Coordinates[i][1], Coordinates[i][2], axis);
	}
	
	drawpoly(vertex, Coordinates);
	
	return 0; 
} 

*/


