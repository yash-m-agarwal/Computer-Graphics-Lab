#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
//adding comment to remove the prvious commits
float xc,yc,r;
float h = 0.0;
float delta = 10;

void draw8points(float xc,float yc, float x,float y){
	

	glBegin(GL_POINTS);
	glColor3f(0,0,1);

	glVertex2i(xc+x, yc+y+h);
	glVertex2i(xc+x, yc-y+h);
	glVertex2i(xc-x, yc+y+h);
	glVertex2i(xc-x, yc-y+h);
	
	glVertex2i(xc+y, yc+x+h);
	glVertex2i(xc+y, yc-x+h);
	glVertex2i(xc-y, yc+x+h);
	glVertex2i(xc-y, yc-x+h);
	glEnd();

	
}

void bres(float xc,float yc,float r){
	float x = 0;
	float y = r;
	float dec_param = 3-2*r;
	do{
		draw8points(xc,yc,x,y);
		x++;
		if(dec_param < 0){
			dec_param = dec_param + 4*x + 6;
		}
		else{
			y--;
			dec_param = dec_param + 4*(x-y) + 10;	
		}
	}while(x<=y);
   glutSwapBuffers();  // Swap front and back buffers (of double buffered mode)
}

void initialize(){
	glClearColor(0,0,0,1);
	gluOrtho2D(-780, 780, -420, 420); 
	glClear(GL_COLOR_BUFFER_BIT);
}

void display(){
	bres(xc,yc,r);
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Timer(int value) {
   glutPostRedisplay(); // Post a paint request to activate display()
   if(h > 350){
		delta = -10;
	}
	if(h<-350){
		delta = 10;
	}

	h += delta;
   glutTimerFunc(40, Timer, 0); // subsequent timer call at milliseconds
}


int main(int argc,char* argv[]){

	printf("Enter the centre of the circle : ");
	scanf("%f %f",&xc, &yc);

	printf("Enter the radius of the circle : ");
	scanf("%f",&r);

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1366, 768); 
    glutInitWindowPosition(0,0);

	glutCreateWindow("Bounce");
	glutDisplayFunc(display);
	glutTimerFunc(0, Timer, 0); 
	initialize();
	glutMainLoop();
	

}