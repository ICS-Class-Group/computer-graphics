#include<iostream>
#include<GL/glut.h>
#include<math.h>

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	gluOrtho2D(-20, 20, -20, 20);
	glClear(GL_COLOR_BUFFER_BIT);
}

void DrawCircle(float cx, float cy, float r, int num_segments) {
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < num_segments; ii++) {
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 
		glVertex2f(x + cx, y + cy);//output vertex 
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