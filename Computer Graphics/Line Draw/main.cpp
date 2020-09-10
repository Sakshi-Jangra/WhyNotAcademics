#include<graphics.h>
#include<iostream>

using namespace std;

int main(){
	int start;
	cout<<"Enter the shape you want to be displayed: 1 for Line, 2 for Cross, 3 for Circle, 4 for Circle with pattern"<<endl;
	cin>>start;
	
	// size of the output window | how much display you need
	initwindow(700,700);
	
	// set the colour of graphics
	setcolor(2); // green
	
	if(start == 1){
		// display a line within the window frame
		line(120,120, 400,400);
	}
	else if(start == 2){
		// display a line within the window frame
		line(120,120, 400,400);	
		// now drawing a cross
		line(420,120, 120,400);
	}
	else if(start == 3){	
		// draw circle
		circle(250,250, 100);
		// fill circle with 3 (cyan)
		setfillstyle(SOLID_FILL, 3);
		
		// fill until we get colour 2
		floodfill(250,250,2);
	}
	else if(start == 4){
		// draw circle
		circle(250,250, 100);
		// fill circle with 3 (cyan)
		setfillstyle(HATCH_FILL, 3);
		
		// fill until we get colour 2
		floodfill(250,250,2);
	}
	
	// to hold the graphics until we press anything
	getch();
	
	return 0;
}
