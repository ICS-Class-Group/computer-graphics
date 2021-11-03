#include<iostream>
#include<GL/glut.h>
#include<math.h>

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	gluOrtho2D(-20, 20, -20, 20);

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

void drawRightHalfCircle()  // the empty one
{
	float radius = 4.0;
	float twoPI = 2 * 3.1415926f;
	glColor3f(0.0, 0.0, 1.0);

	glBegin(GL_POINTS);

	for (float i = 0.0; i <= twoPI / 2; i += 0.001)
		glVertex2f((sin(i) * radius), (cos(i) * radius));

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
  DrawCircle(0.0,6.0,6.0,1000);

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