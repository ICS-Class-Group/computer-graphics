#include<iostream>
#include<GL/glut.h>
#include<math.h>

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	gluOrtho2D(-20, 20, -20, 20);

}


void doorknob() {

		glColor3f(0.0, 0.0, 1.0);
		glPointSize(6.0);
		glBegin(GL_POINTS);
		glVertex2f(1.4, -7);
		glEnd();
		glFlush();

}

void DrawCircle(float cx, float cy, float r, int num_segments) {
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < num_segments/2; i++) {
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
		float x = r * cosf(theta); 
		float y = r * sinf(theta);
		glVertex2f(x + cx, y + cy);
	}
	glEnd();
	glFlush();

}
void Circle(float cx, float cy, float r, int num_segments) {
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < num_segments; i++) {
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
		float x = r * cosf(theta);
		float y = r * sinf(theta);
		glVertex2f(x + cx, y + cy);
	}
	glEnd();
	glFlush();

}

void door() {
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-2, -12);
	glVertex2f(2, -12);
	glVertex2f(2, 0);
	glVertex2f(-2, 0);
	glEnd();
	glFlush();
}

void window() {
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-10, -6);
	glVertex2f(-4, -6);
	glVertex2f(-4, 0);
	glVertex2f(-10, 0);
	glEnd();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(-10,-3);
	glVertex2f(-4,-3);
	glEnd();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(-7,0);
	glVertex2f(-7,-6);
	glEnd();
	glFlush();
}
void windowright() {
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(10, -6);
	glVertex2f(4, -6);
	glVertex2f(4, 0);
	glVertex2f(10, 0);
	glEnd();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(10,-3);
	glVertex2f(4,-3);
	glEnd();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(7,0);
	glVertex2f(7,-6);
	glEnd();
	glFlush();
}

void mainhouse() {
	glClear(GL_COLOR_BUFFER_BIT);
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
	window();
	windowright();
  	DrawCircle(0.0,6.0,6.0,1000);
  	Circle(1.4, -7.0, 0.2, 300);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("House");

	init();
	glutDisplayFunc(house);
	glutMainLoop();
}