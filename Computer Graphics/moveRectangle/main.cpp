#include<bits/stdc++.h> 
#include<graphics.h> 
using namespace std; 

void translateRectangle ( int P[][2], int T[]) 
{ 
	// ----------- BEFORE -------------
	setcolor(GREEN); 
	rectangle(P[0][0], P[0][1], P[1][0], P[1][1]); 

	// calculating translated coordinates 
	P[0][0] = P[0][0] + T[0]; 
	P[0][1] = P[0][1] + T[1]; 
	P[1][0] = P[1][0] + T[0]; 
	P[1][1] = P[1][1] + T[1]; 

	// ----------- After -------------
	setcolor(LIGHTMAGENTA); 
	rectangle (P[0][0], P[0][1], P[1][0], P[1][1]); 
	
	getch();
	closegraph(); 
	return;
} 

// driver program 
int main() 
{ 
	// rectangles's four vertices
	int R[2][2];
	int T[2]; // translation factor 
	
	cout<<"HEy!! Enter boundary Coordinates of Rectangle (top left and bottom right ): "<<endl;
	cin>>R[0][0]>>R[0][1]>>R[1][0]>>R[1][1];
	
	cout<<"how much X and Y shift needed? "<<endl;
	cin>>T[0]>>T[1];
	
	// graph window gets open
	int gd = DETECT, gm, errorcode; 
	initgraph (&gd, &gm, "c:\\tc\\bgi"); 

	translateRectangle (R, T); 
	return 0; 
} 

