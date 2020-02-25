#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

float xc, yc, r;

void draw8points(float xc,float yc, float x,float y){
	glBegin(GL_POINTS);
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

void bres(float xc,float yc,float r){
	float x = 0;
	float y = r;
	float dec_param = 3-2*r;
	while(x<=y){
		draw8points(xc,yc,x,y);
		x++;
		if(dec_param < 0){
			dec_param = dec_param + 4*x + 6;
		}
		else{
			y--;
			dec_param = dec_param + 4*(x-y) + 10;	
		}
	}
	glFlush();
}

void initialize(){
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.0, 1.0, 0.0); 
	gluOrtho2D(-780, 780, -420, 420); 
	glClear(GL_COLOR_BUFFER_BIT);
}

void display(){
	bres(xc,yc,r);
}

int main(int argc,char* argv[]){
	

	printf("Enter the centre of the circle : ");
	scanf("%f %f",&xc, &yc);

	printf("Enter the radius of the circle : ");
	scanf("%f",&r);

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0,0);

	glutCreateWindow("Bresenham-circle");
	initialize();
	glutDisplayFunc(display);
	glutMainLoop();
}