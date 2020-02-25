#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float xc,yc,r,w,h;
void initialize(){
	glClearColor(0, 0, 0, 1);
	gluOrtho2D(-780, 780, -420, 420); 
	glClear(GL_COLOR_BUFFER_BIT);
}

void draw8points(float x,float y){
	glBegin(GL_POINTS);
	glColor3f(0,0,1);

	glVertex2i(xc+x, yc+y);
	glVertex2i(xc+x, yc-y);
	glVertex2i(xc-x, yc+y);
	glVertex2i(xc-x, yc-y);
	
	glVertex2i(xc+y, yc+x);
	glVertex2i(xc+y, yc-x);
	glVertex2i(xc-y, yc+x);
	glVertex2i(xc-y, yc-x);
	glEnd();
}

void circle(){
	float x = 0, y = r;
	float d = 3 - 2*r;
	do{
		draw8points(x,y);
		x++;
		if(d>0){
			y--;
			d = d +4*(x-y) + 10;
		}
		else{
			d = d + 4*x + 6;
		}
	}while(x<=y);

	glFlush();
}

void display(){
	circle();

	float y1,y2;
	y1 = yc + sqrt((double)(r*r+w*w/4));
	y2 = y1 + h;

	glBegin(GL_LINES);
	glColor3f(0,0,1);
	glVertex2f(xc-w/2,y1);
	glVertex2f(xc-w/2,y2);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0,0,1);
	glVertex2f(xc-w/2,y2);
	glVertex2f(xc+w/2,y2);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0,0,1);
	glVertex2f(xc+w/2,y2);
	glVertex2f(xc+w/2,y1);
	glEnd();

	glFlush();

}



int main(int argc,char* argv[]){
	printf("Enter the centre of the circle which is at the bottom of the pendulum : ");
	scanf("%f %f",&xc, &yc);
	printf("Enter its radius : ");
	scanf("%f",&r);

	printf("Enter width of the pendulum (Note : it should be less than radius) : ");
	scanf("%f",&w);
	printf("Enter height of the pendulum (Note : it should be less than to fit in window) : ");
	scanf("%f",&h);

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0,0);

	glutCreateWindow("pendulum");
	initialize();
	glutDisplayFunc(display);
	glutMainLoop();
}
