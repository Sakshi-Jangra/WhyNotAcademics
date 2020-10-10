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

void mul(int n,float b[][3],float c[][3],float a[][3])
{
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<3;j++)
			a[i][j]=0;

	for(i=0;i<n;i++)
		for(j=0;j<3;j++)
			for(k=0;k<3;k++) {
				a[i][j]=a[i][j]+(c[i][k]*b[k][j]);
			}

}

void translation(int n,float c[][3],float tx,float ty)
{
	int i;
	for(i=0;i<n;i++)
	{
		c[i][0]=c[i][0]+tx;
		c[i][1]=c[i][1]+ty;
	}
}

void scaling(int n,float c[][3],float sx,float sy)
{
	float b[10][3],a[10][3];
	int i,j;
	for(j=0;j<3;j++)
		b[i][j]=0;
	
	b[0][0]=sx;
	b[1][1]=sy;
	b[2][2]=1;
	mul(n,b,c,b);
	setcolor(RED);
	disp(n,b);
}

//void rotation(int n,float c[][3],float ra)
//{
//	int i=0,j;
//	float b[10][3],xp,yp,a[10][3];
//	xp=c[0][0];
//	yp=c[0][1];
//		
//	for(i=0;i<3;i++)
//		for(j=0;j<3;j++)
//			b[i][j]=0;
//	
//	b[0][0]=b[1][1]=cos(ra*3.14/180);
//	b[0][1]=sin(ra*3.14/180);
//	b[1][0]=-sin(ra*3.14/180);;
//	b[2][0]=(-xp*cos(ra*3.14/180))+(yp*sin(ra*3.14/180))+xp;
//	b[2][1]=(-xp*sin(ra*3.14/180))-(yp*cos(ra*3.14/180))+yp;
//	b[2][2]=1;
//	
//	mul(n,b,c,a);
//	setcolor(RED);
//	disp(n,a);
//}




int main()
{
	int i, j, k, choice,n,gd=DETECT,gm;

	float c[10][3],tx,ty,sx,sy,ra;
	initgraph(&gd,&gm," ");
	cout<<"Enter no. of vertices";
	cin>>n;
	for (i=0;i<n;i++)
	{
		cout<<"Enter coordinates of vertex",i+1;
		cin>>c[i][0]>>c[i][1];
		c[i][2]=1;
	}
	
	do {
	cleardevice();
	
	cout<<"\n\t\t 1)Translation";
	cout<<"\n\t\t 2)Scaling";
	
	cout<<"\n\t\t 3)EXIT";
	
	cout<<"\n\t Enter your Choice";
	cin>>choice;
	
	switch(choice) {
	case 1:
		cout<<"\n\t Enter translation factor for X and Y axis:\t";
		cin>>tx>>ty;
		cleardevice();
		setcolor(15);
		disp(n,c);
		translation(n,c,tx,ty);
		setcolor(15);
		disp(n,c);
		getch();
		break;
	
	case 2:
		cout<<"\n\t Enter scaling factor for X and Y axis:\t";
		cin>>sx>>sy;
		cleardevice();
		setcolor(15);
		disp(n,c);
		scaling(n,c,sx,sy);
		getch();
		break;
	
	}
	
		getch();
		closegraph();

	}while(choice != 3);
}
