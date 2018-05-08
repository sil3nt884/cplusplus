// birthish airways.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "glut.h"
#include "Plane2D.h"
#include "cloud.h"


using namespace std;


const int points = 66;

Plane2D  plane1 [points] ={{112.01, 152.85},{127.84, 159.19},{142.62, 166.57},{160.56, 162.35},{176.4, 159.19},{192.23, 157.07},
{209.12, 156.02},{224.96, 158.13},{258.74, 152.85},{273.51, 144.41},{260.85, 131.74},{245.01, 118.02},{234.46, 103.24},{208.07, 81.07},
{195.4, 69.46},{208.07, 57.85},{222.85, 74.74},{239.74, 87.4},{255.57, 96.9},{272.46, 110.63},{300, 100},{315.74, 106.41},
{329.46, 119.07},{312.57, 134.91},{291.46, 133.85},{310.46, 156.02},{331.57, 154.96},{351.63, 156.02},{380.13, 159.19},
{407.58, 159.19},{433.97, 162.35},{454.02, 164.46},{474.08, 172.91},{469.86, 189.8},{456.13, 198.24},{438.19, 199.3},
{420.24, 199.3},{400, 200},{383.3, 200.35},{361.13, 200.35},{340.02, 198.24},{323.13, 204.58},{317.85, 228.86},{310.46, 246.8},
{294.63, 247.86},{298.85, 228.86},{300, 200},{284.07, 192.96},{267.18, 194.02},{251.35, 194.02},{235.51, 192.96},
{216.51, 191.91},{200, 200},{185.9, 189.8},{169.01, 194.02},{158.45, 207.74},{144.73, 218.3},{132.06, 233.08},
{117.28, 239.41},{116.23, 223.58},{124.67, 208.8},{135.23, 195.08},{128.9, 179.24},{122.03, 169.78},{123.03, 170.78},{124.03,171.78}};

Plane2D world1 [points] ={{68.44, 320.69},{78.37, 341.23},{98.07, 347.79},{46.94, 295.88},{32.06, 257.84},{35.37, 224.77},{37.02, 188.38},{50.25, 160.26},{60.17, 137.11},
{81.67, 117.26},{100, 100},{131.29, 90.8},{156.1, 77.57},{185.87, 90.8},{220.6, 62.69},{253.67, 66},{285.1, 79.23},{319.83, 102.38},{338.02, 137.11},
{364.48, 183.42},{364.48, 236.34},{361.17, 282.65},{334.71, 328.96},{303.29, 358.73},{273.52, 371.96},{235.48, 380.23},{207.37, 376.92},
{177.6, 371.96},{134.6, 368.65},{106.48, 355.42},{139.56, 327.3},{167.67, 333.92},{200, 300},{190.83, 266.11},{172.63, 244.61},{127.98, 219.8},
{114.75, 190.03},{179.25, 165.23},{209.02, 120.57},{136.25, 128.84},{109.79, 156.96},{84.98, 213.19},{75.06, 281},{100, 300},{100.01, 300.01},{100.02, 300.02},{100.03, 300.03},{100.04, 300.04},{100.05, 300.05},{100.06, 300.06},
{100.07, 300.07},{100.08, 300.08},{100.09, 300.09},{100.10, 300.10},{100.11, 300.11},{100.12, 300.12},{100.13, 300.13},{100.14, 300.14},{100.15, 300.15},{100.16, 300.16},{100.17, 300.17},{100.18, 300.18},{100.19, 300.19},{100.20, 300.20},
{100.21, 300.21},{100.22, 300.22}};

cloud cloud1 [19]={{28.4,496.79},{52.58, 505.25},{76.76, 504.04},{87.64, 487.11},{100, 500},{125.12, 508.88},{145.67, 495.58},{171.06, 507.67},
{208.54, 478.65},{223.05, 448.43},{204.92, 427.87},{178.32, 441.17},{158.97, 415.78},{131.17, 420.62},{111.82, 435.13},{84.01, 430.29},
{46.53, 418.2},{25.98, 429.08},{19.94, 458.1}};



int frame=0;
Plane2D  dis[points];
Plane2D  tweenPoly[points];
float proportion =0.0;
int tx=-500, ty=50;	
int textx=800,texty=250;
int screenx, screeny;
float  rot1 =0.0;
int cloudx,cloudy;






void tween(Plane2D  source[points], Plane2D  destination[points], int numPoints, double proportion, Plane2D tweenPoly[points])
{
	
	for( int i = 0; i < numPoints; i++)
        {
     
		    double sourceX = source[i].X;
 		    double sourceY = source[i].Y;

                
 		    double destinationX = destination[i].X;
 		    double destinationY = destination[i].Y;

 		    double differenceX = (destinationX - sourceX);
 		    double differenceY = (destinationY - sourceY);

             
 		    double tweenX = sourceX + ( differenceX * proportion );
 		    double tweenY = sourceY + ( differenceY * proportion );

			tweenPoly[i].X = tweenX;
			tweenPoly[i].Y = tweenY;
        }


}



void world(){
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0,0.0,0.0);
	for(int i=0; i<points; i++){
		glVertex2i(world1[i].X,world1[i].Y);
	}
	glEnd();
}

void plane(){
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0,0.0,1.0);
	for(int i=0; i<points; i++){
		glVertex2i(plane1[i].X,plane1[i].Y);
	}
	glEnd();
}

void cloud2 () {
	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);
	for(int i=0; i<19; i++){
		glVertex2i(cloud1[i].x,cloud1[i].y);
	}
	glEnd();
}






void scene1(){
	glTranslatef(tx,ty,0.0);
	plane();
	tx+=5; ty=50;
	if(tx==510){
		tx=-500;
	}
	
}


void scene2(){

	int i;
  glColor3f(1.0,0.0,0.0);
	   tween(plane1,world1,points,proportion,tweenPoly);

		glBegin(GL_LINE_LOOP);
			for(i=0;i<points;i++)
			{
			 glVertex2i (tweenPoly[i].X,tweenPoly[i].Y);
			
			} 
		glEnd();
}


void renderSpacedBitmapString(
			float x, 
			float y,
			int spacing, 
			void *font,
			char *string) {
  char *c;
  int x1=x;
  for (c=string; *c != '\0'; c++) {
	glRasterPos2f(x1,y);
    	glutBitmapCharacter(font, *c);
	x1 = x1 + glutBitmapWidth(font,*c) + spacing;
  }
}

void Timer( int value )
{
   if( value ) glutPostRedisplay();
   glutTimerFunc(40,Timer,value);
}


void visibility(int state)
{
 switch (state)
 {
   case GLUT_VISIBLE:
             Timer(1);
             break;
   case GLUT_NOT_VISIBLE:
             Timer(0);
             break;
   default:
             break;
 }
}


void drawBackground(){
glColor3f(0.065,0.105,0.225);
	 glBegin(GL_QUADS);
glVertex2f(0, 500); 
glVertex2f(800 ,500); 
glVertex2f(0, 400); 
glVertex2f(800, 400);
glVertex2f(800, 400);
glVertex2f(800 ,500); 
glVertex2f(0, 500);
glVertex2f(0, 400); 
glVertex2f(800, 400);
glVertex2f(0, 400); 
glVertex2f(0, 200);
glVertex2f(800, 200); 
 glEnd();
 glColor3f(0.0,1.0,0.0);
 glBegin(GL_QUADS);
 glVertex2f(0, 200);
 glVertex2f(800, 200);
 glVertex2f(0, 100);
 glVertex2f(800, 100);
 glVertex2f(0, 200);
 glVertex2f(0, 100);
 glVertex2f(800, 200);
  glVertex2f(800, 100);
  glEnd();
   glColor3f(0.139,0.069,0.019);
  glBegin(GL_QUADS);
  glVertex2f(0, 100);
   glVertex2f(800, 100);
    glVertex2f(0, 0);
	 glVertex2f(800, 0);
	  glVertex2f(0, 100);
	  glVertex2f(0, 0);
	  glVertex2f(800, 100);
	  glVertex2f(800, 0);

  glEnd();



  glPushMatrix();
  glTranslatef(cloudx,cloudy,0.0);
  glRotatef(rot1, 0, 0,1.0);
  cloud2();
  cloudx=400;
  glPopMatrix();

  glFlush ();

 

}


void display(void){
	rot1+=0.5;

	
  glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  drawBackground();

  glPushMatrix();
	if(frame==0 || frame <  100){
		scene1();
	}else if(frame== 100 ||  frame < 200){
		glTranslatef(tx,ty,0.0);
		scene2();
		tx=0; ty=50;
		proportion +=0.01;
		if(proportion >1.0) proportion =0.0;
		
	}else if(frame== 200 ||  frame < 400){
		glColor3f(1.0,0,0);
		renderSpacedBitmapString(textx,texty,5,GLUT_BITMAP_HELVETICA_18,"Fly away with british airways");
		textx-=5;
	}
	
	
  glPopMatrix();
   frame++;
  if(frame>=400){
	  frame=0;
	  tx=-500;
	  textx=+500;
  }
    
   glFlush ();

  fprintf(stdout,"frame %i\n",frame);


}

void init (void) 
{
/* select clearing color 	*/
glClearColor(0.1,0.149,0.237,0.0);
   

/* initialize viewing values  */
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
  gluOrtho2D( 0,800,0,500);


}


int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("British Airways");
   init ();
   glutDisplayFunc(display); 
   glutVisibilityFunc(visibility);
   glutMainLoop();   
   return 0;  
}

