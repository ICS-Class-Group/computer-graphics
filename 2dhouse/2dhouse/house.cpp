#include<iostream>
#include<GL/glut.h>

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	gluOrtho2D(-15, 15, -15, 15);
	glClear(GL_COLOR_BUFFER_BIT);

}

void mainhouse() {
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-11, -11);
	glVertex2f(11, -11);
	glVertex2f(11, 1);
	glVertex2f(13, 1);
	glVertex2f(13, 4);
	glVertex2f(-13, 4);
	glVertex2f(-13, 1);
	glVertex2f(-11, 1);
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("House");

	init();
	glutDisplayFunc(mainhouse);
	glutMainLoop();
}