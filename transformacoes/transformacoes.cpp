#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif



void display(void);

GLdouble width, height;
int wd;

float dispy = -0.3;

typedef GLfloat objetos[21][2];
objetos casa;
int i;
int iter = 0; 
float scale = 45;

float fx(float x) {
	//return (width / 2) + x * scale;
	return x;
}

float fy(float y) {
	//return (height / 2) + y * scale;
	return y;
}

void init(void) {
	width  = 600;
	height = 400.0;

	// OBJETO INICIAL: CASA
	casa[0][0] = fx(-1.5); casa[0][1] = fy(3.5);
	casa[1][0] = fx(-1.25); casa[1][1] = fy(3.5);
	casa[2][0] = fx(-1.25); casa[2][1] = fy(2.57);
	casa[3][0] = fx(-1.5); casa[3][1] = fy(2.37);
	casa[4][0] = fx(-1.25); casa[4][1] = fy(0);
	casa[5][0] = fx(-1.25); casa[5][1] = fy(-2);
	casa[6][0] = fx(0); casa[6][1] = fy(-2);
	casa[7][0] = fx(0); casa[7][1] = fy(0);
	casa[8][0] = fx(0.5); casa[8][1] = fy(0.5 + dispy);
	casa[9][0] = fx(1.5); casa[9][1] = fy(0.5 + dispy);
	casa[10][0] = fx(1.0); casa[10][1] = fy(0.0 + dispy);
	casa[11][0] = fx(1.0); casa[11][1] = fy(1.0 + dispy);
	casa[12][0] = fx(0.5); casa[12][1] = fy(0.0 + dispy);
	casa[13][0] = fx(1.5); casa[13][1] = fy(0.0 + dispy);
	casa[14][0] = fx(1.5); casa[14][1] = fy(1.0 + dispy);
	casa[15][0] = fx(0.5); casa[15][1] = fy(1.0 + dispy);
	casa[16][0] = fx(-2); casa[16][1] = fy(-2);
	casa[17][0] = fx(2); casa[17][1] = fy(-2);
	casa[18][0] = fx(2); casa[18][1] = fy(2);
	casa[19][0] = fx(0); casa[19][1] = fy(3.5);
	casa[20][0] = fx(-2); casa[20][1] = fy(2);
}

float angle = 0;
float tx = 0, ty = 0;
float sx = 1, sy = 1;

void move(unsigned char key, int x, int y)
{
	switch (key) {
		case 'A': 
		case 'a':// anti-horário
			angle += 10;
			break;
		case 'H': 
		case 'h':// horário
			angle -= 10;
			break;
		case 'i':
			ty += 1;
			break; 
		case 'k':
			ty -= 1;
			break; 
		case 'j': 
			tx -= 1;
			break; 
		case 'l':  
			tx += 1;
			break;
		case 'x':  
			sx += 1;
			break;
		case 'y':  
			sy += 1;
			break;
		case 'w':  
			sx += 1;
			sy += 1;
			break;
		case 'X':  
			sx -= 1;
			break;
		case 'Y':  
			sy -= 1;
			break;
		case 'W':  
			sx -= 1;
			sy -= 1;
			break;
	}

	printf("%d\n", (int)key);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(angle, 0, 0, 1);
	glTranslatef(tx, ty, 1);
	glScalef(sx, sy, 1);
	//display();
	glutPostRedisplay();
}

void display(void) {
	int i;

	/* clear the screen to white */
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.0, 0.0);

	//INÍCIO CASA
	glBegin(GL_LINE_LOOP);
	glVertex2fv(casa[0]);
	glVertex2fv(casa[1]);
	glVertex2fv(casa[2]);
	glVertex2fv(casa[3]);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2fv(casa[4]);	
	glVertex2fv(casa[5]);
	glVertex2fv(casa[6]);
	glVertex2fv(casa[7]);
	glEnd();

	glBegin(GL_LINES);
	glVertex2fv(casa[8]);
	glVertex2fv(casa[9]);
	glVertex2fv(casa[10]);
	glVertex2fv(casa[11]);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2fv(casa[12]);
	glVertex2fv(casa[13]);
	glVertex2fv(casa[14]);
	glVertex2fv(casa[15]);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2fv(casa[16]);
	glVertex2fv(casa[17]);
	glVertex2fv(casa[18]);
	glVertex2fv(casa[19]);
	glVertex2fv(casa[20]);
	glEnd();
	//FIM CASA

	glFlush();
}

void reshape(int w, int h) {
	width = (GLdouble) w;
	height = (GLdouble) h;

	glViewport(0, 0, (GLsizei) width, (GLsizei) height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-width/40, width/40, -height/40, height/40);
}

int main(int argc, char *argv[]) {

	init();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize((int) width, (int) height);
	wd = glutCreateWindow("Experiment with line drawing");
	glutKeyboardFunc(move);
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glPointSize(5.0);
	glutMainLoop();

	return 0;
}