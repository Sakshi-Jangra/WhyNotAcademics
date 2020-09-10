#include<bits/stdc++.h> 
#include<graphics.h> 

using namespace std; 

// function to translate point 
void translatePoint ( int P[], int T[]) 
{ 	
	putpixel (P[0], P[1], YELLOW); 
	

	// calculating translated coordinates 
	P[0] = P[0] + T[0]; 
	P[1] = P[1] + T[1]; 
	
	// Draw new coordinatses 
	putpixel (P[0], P[1], 3); 
	
	
	cout<<"Original Coordinates :"<<P[0]<<","<<P[1]; 
	cout<<"\nTranslated Coordinates :"<< P[0]<<","<< P[1]; 


	getch();
	closegraph(); 
	return;
} 

int main() 
{ 
	int P[2]; // coordinates of point 
	int T[2]; // translation factor 
	cout<<"Enter Coordinates of point & how much X and Y shift needed:    ";
	
	cin>>P[0]>>P[1]>>T[0]>>T[1];
	cout<<endl;
	int gd = DETECT,gm, errorcode; 
	initgraph(&gd, &gm, "c:\\tc\\bgi"); 

	translatePoint (P, T); 
	return 0; 
} 

