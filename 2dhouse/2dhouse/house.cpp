#include<iostream>
#include<GL/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include<math.h>

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	gluOrtho2D(-20, 20, -20, 20);
	glClear(GL_COLOR_BUFFER_BIT);
}
void door() {
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-2, -12);
	glVertex2f(2, -12);
	glVertex2f(2, -2);
	glVertex2f(-2, -2);
	glEnd();
	glFlush();
}

void doorknob() {

		glColor3f(0.0, 0.0, 1.0);
		glPointSize(6.0);
		glBegin(GL_POINTS);
		glVertex2f(1.4, -7);
		glEnd();
		glFlush();
}


void mainhouse() {
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-12, -12);
	glVertex2f(12, -12);
	glVertex2f(12, 2);
	glVertex2f(14, 2);
	glVertex2f(14, 6);
	glVertex2f(-14, 6);
	glVertex2f(-14, 2);
	glVertex2f(-12, 2);
	glEnd();
	glFlush();
}

void house() {
	mainhouse();
	door();
	doorknob();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("House");

	init();
	glutDisplayFunc(house);
	glutMainLoop();
}