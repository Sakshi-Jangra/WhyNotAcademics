
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<math.h>
# define f 0.3
# define projection_angle 45
using namespace std;
void apply_translation(int[8][3],const int,const int,const int);
void apply_scaling(int edge_points[8][3],const float sx,const float sy,const float sz);
void apply_rotation_x(int edge_points[5][3],const int tx);
void apply_rotation_y(int edge_points[5][3],const int tx);
void apply_rotation_z(int edge_points[5][3],const int tx);
void draw_pyramid(int points[5][3]);
void multiply_matrices(const float[4],const float[4][4],float[4]);
void draw_cube(int [8][3]);
void get_projected_point(int&,int&,int&);
void Line(const int,const int,const int,const int);
int main(){
int gd=DETECT,tx,ty,tz;
float sx,sy,sz;
int gm,ch;
char op=’y’;
initgraph(&gd,&gm,””);
do{
int cube[8][3]={{270,200,50},
{370,200,50},
{370,300,50},
{270,300,50},
{270,200,-50},
{370,200,-50},
{370,300,-50},
{270,300,-50}};
int pyramid[5][3]={
{280,130,50},
{360,130,50},
{360,130,-50},
{280,130,-50},
{320,20,0} };
cout<<“Select Your Choice for 3d Transformation\n”;
cout<<“1.Translate\n2.Scale\n3.Rotation along x-axis\n4.Rotation along yaxis\
n5.Rotation along z-axis\n”;
cin>>ch;
switch(ch) {
case 1:
setcolor(15);
draw_cube(cube);
cout<<“Enter the tx,ty and tz values: “;
cin>>tx>>ty>>tz;
apply_translation(cube,tx,ty,tz);
setcolor(9);
draw_cube(cube);
break;
case 2:
setcolor(15);
draw_cube(cube);
cout<<“Enter the sx,sy and sz values: “;
cin>>sx>>sy>>sz;
apply_scaling(cube,sx,sy,sz);
setcolor(9);
draw_cube(cube);
break;
case 3:
setcolor(15);
draw_pyramid(pyramid);
cout<<“Enter the rotation angle tx: “;
cin>>tx;
apply_rotation_x(pyramid,tx);
break;
case 4:
setcolor(15);
draw_pyramid(pyramid);
cout<<“Enter the rotation angle tx: “;
cin>>tx;
apply_rotation_y(pyramid,tx);
break;
case 5:
setcolor(15);
draw_pyramid(pyramid);
cout<<“Enter the rotation angle tx: “;
cin>>tx;
apply_rotation_z(pyramid,tx);
break; }
cout<<“\nDo you want to continue: (y/n): “;
cin>>op;
cleardevice(); }
while(op==’y’);
getch();
closegraph();
return 0;}
void apply_translation(int edge_points[8][3],const int tx,const int ty,const int tz){
for(int count=0;count<8;count++) {
floatmatrix_a[4]={edge_points[count][0],edge_points[count][1],
edge_points[count][2],1};
float matrix_b[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{tx,ty,tz,1}};
float matrix_c[4]={0};
multiply_matrices(matrix_a,matrix_b,matrix_c);
edge_points[count][0]=(int)(matrix_c[0]+0.5);
edge_points[count][1]=(int)(matrix_c[1]+0.5);
edge_points[count][2]=(int)(matrix_c[2]+0.5); }}
void apply_scaling(int edge_points[8][3],const float sx,const float sy,const float sz){
for(int count=0;count<8;count++) {
float matrix_a[4]={edge_points[count][0],edge_points[count][1],
edge_points[count][2],1};
float matrix_b[4][4]={{sx,0,0,0},{0,sy,0,0},{0,0,sz,0},{0,0,0,1}};
float matrix_c[4]={0};
multiply_matrices(matrix_a,matrix_b,matrix_c);
edge_points[count][0]=(int)(matrix_c[0]+0.5);
edge_points[count][1]=(int)(matrix_c[1]+0.5);
edge_points[count][2]=(int)(matrix_c[2]+0.5); }}
void apply_rotation_x(int control_points[5][3],const int theta){
int edge_points[5][3]={0};
float angle=(theta*(M_PI/180));
for(int count=0;count<5;count++) {
edge_points[count][0]=control_points[count][0];
edge_points[count][1]=control_points[count][1];
edge_points[count][2]=control_points[count][2];
float matrix_a[4]={edge_points[count][0],edge_points[count][1],
edge_points[count][2],1};
float matrix_b[4][4]={ { 1,0,0,0 } ,{ 0,cos(angle),sin(angle),0 } ,
{ 0,-sin(angle),cos(angle),0 } ,{ 0,0,0,1 }};
float matrix_c[4]={0};
multiply_matrices(matrix_a,matrix_b,matrix_c);
edge_points[count][0]=(int)(matrix_c[0]+0.5);
edge_points[count][1]=(int)(matrix_c[1]+0.5);
edge_points[count][2]=(int)(matrix_c[2]+0.5); }
setcolor(10);
draw_pyramid(edge_points);}
void apply_rotation_y(int control_points[5][3],const int theta){
int edge_points[5][3]={0};
float angle=(theta*(M_PI/180));
for(int count=0;count<5;count++) {
edge_points[count][0]=control_points[count][0];
edge_points[count][1]=control_points[count][1];
edge_points[count][2]=control_points[count][2];
float matrix_a[4]={edge_points[count][0],
edge_points[count][1], edge_points[count][2],1};
float matrix_b[4][4]={ { cos(angle),0,sin(angle),0 } , { 0,1,0,0 } ,
{ -sin(angle),0,cos(angle),0 } , { 0,0,0,1 }};
float matrix_c[4]={0};
multiply_matrices(matrix_a,matrix_b,matrix_c);
edge_points[count][0]=(int)(matrix_c[0]+0.5);
edge_points[count][1]=(int)(matrix_c[1]+0.5);
edge_points[count][2]=(int)(matrix_c[2]+0.5); }
setcolor(10);
draw_pyramid(edge_points);}
void apply_rotation_z(int control_points[5][3],const int theta) j{
int edge_points[5][3]={0};
float angle=(theta*(M_PI/180));
for(int count=0;count<5;count++) {
edge_points[count][0]=control_points[count][0];
edge_points[count][1]=control_points[count][1];
edge_points[count][2]=control_points[count][2];
float matrix_a[4]={edge_points[count][0],edge_points[count][1],
edge_points[count][2],1};
float matrix_b[4][4]={ { cos(angle),-sin(angle),0,0} ,
{ sin(angle),cos(angle),0,0 } , { 0,0,1,0 } , { 0,0,0,1 } };
float matrix_c[4]={0};
multiply_matrices(matrix_a,matrix_b,matrix_c);
edge_points[count][0]=(int)(matrix_c[0]+0.5);
edge_points[count][1]=(int)(matrix_c[1]+0.5);
edge_points[count][2]=(int)(matrix_c[2]+0.5); }
setcolor(10);
draw_pyramid(edge_points);}
void multiply_matrices(const float matrix_1[4],const float matrix_2[4][4],float
matrix_3[4]){
for(int count_1=0;count_1<4;count_1++) {
for(int count_2=0;count_2<4;count_2++)
matrix_3[count_1]+=(matrix_1[count_2]*matrix_2[count_2][count_1]); }
}
void draw_cube(int edge_points[8][3]){
for(int i=0;i<8;i++)
get_projected_point(edge_points[i][0],edge_points[i][1],edge_points[i][2]);
Line(edge_points[0][0],edge_points[0][1],edge_points[1][0],edge_points[1][1]);
Line(edge_points[1][0],edge_points[1][1],edge_points[2][0],edge_points[2][1]);
Line(edge_points[2][0],edge_points[2][1],edge_points[3][0],edge_points[3][1]);
Line(edge_points[3][0],edge_points[3][1],edge_points[0][0],edge_points[0][1]);
Line(edge_points[4][0],edge_points[4][1],edge_points[5][0],edge_points[5][1]);
Line(edge_points[5][0],edge_points[5][1],edge_points[6][0],edge_points[6][1]);
Line(edge_points[6][0],edge_points[6][1],edge_points[7][0],edge_points[7][1]);
Line(edge_points[7][0],edge_points[7][1],edge_points[4][0],edge_points[4][1]);
Line(edge_points[0][0],edge_points[0][1],edge_points[4][0],edge_points[4][1]);
Line(edge_points[1][0],edge_points[1][1],edge_points[5][0],edge_points[5][1]);
Line(edge_points[2][0],edge_points[2][1],edge_points[6][0],edge_points[6][1]);
Line(edge_points[3][0],edge_points[3][1],edge_points[7][0],edge_points[7][1]);}
void draw_pyramid(int points[5][3]) {
int edge_points[5][3];
for(int i=0;i<5;i++) {
edge_points[i][0]=points[i][0]; edge_points[i][1]=points[i][1];
edge_points[i][2]=points[i][2]; get_projected_point(edge_points[i][0],
edge_points[i][1],edge_points[i][2]); edge_points[i][1]+=240; }
Line(edge_points[0][0],edge_points[0][1],
edge_points[1][0],edge_points[1][1]);
Line(edge_points[1][0],edge_points[1][1],
edge_points[2][0],edge_points[2][1]);
Line(edge_points[2][0],edge_points[2][1],
edge_points[3][0],edge_points[3][1]);
Line(edge_points[3][0],edge_points[3][1],
edge_points[0][0],edge_points[0][1]);
Line(edge_points[0][0],edge_points[0][1],
edge_points[4][0],edge_points[4][1]);
Line(edge_points[1][0],edge_points[1][1],
edge_points[4][0],edge_points[4][1]);
Line(edge_points[2][0],edge_points[2][1],
edge_points[4][0],edge_points[4][1]);
Line(edge_points[3][0],edge_points[3][1],edge_points[4][0],edge_points[4][1]);}
void get_projected_point(int& x,int& y,int& z){
float fcos0=(f*cos(projection_angle*(M_PI/180)));
float fsin0=(f*sin(projection_angle*(M_PI/180)));
float Par_v[4][4]={{1,0,0,0},{0,1,0,0},{fcos0,fsin0,0,0},{0,0,0,1}};
float xy[4]={x,y,z,1};
float new_xy[4]={0};
multiply_matrices(xy,Par_v,new_xy);
x=(int)(new_xy[0]+0.5);
y=(int)(new_xy[1]+0.5);
z=(int)(new_xy[2]+0.5); }
void Line(const int x_1,const int y_1,const int x_2,const int y_2) {
int color=getcolor( );
int x1=x_1;
int y1=y_1;
int x2=x_2;
int y2=y_2;
if(x_1>x_2) {
x1=x_2;
y1=y_2;
x2=x_1;
y2=y_1; }
int dx=abs(x2-x1);
int dy=abs(y2-y1);
int inc_dec=((y2>=y1)?1:-1);
if(dx>dy) {
int two_dy=(2*dy);
int two_dy_dx=(2*(dy-dx));
int p=((2*dy)-dx);
int x=x1;
int y=y1;
putpixel(x,y,color);
while(x<x2) {
x++;
if(p<0)
p+=two_dy;
else {
y+=inc_dec;
p+=two_dy_dx; }
putpixel(x,y,color); } }
else {
int two_dx=(2*dx);
int two_dx_dy=(2*(dx-dy));
int p=((2*dx)-dy);
int x=x1;
int y=y1;
putpixel(x,y,color);
while(y!=y2) {
y+=inc_dec;
if(p<0)
p+=two_dx;
else {
x++;
p+=two_dx_dy; }
putpixel(x,y,color); } } }


