#include <GL/GLUT.h>

void render(void);
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(1200, 800);
	glutCreateWindow("Simple GLUT Application");

	glutDisplayFunc(render);

	glutMainLoop();
}
void render(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_POLYGON);

	// pentagon
	glVertex2f(-0.98, 0.75);
	glVertex2f(-0.78, 0.9);
	glVertex2f(-0.58, 0.75);
	glVertex2f(-0.63, 0.4);
	glVertex2f(-0.93, 0.4);

	glEnd();

	// hexagon
	glBegin(GL_POLYGON);

	glVertex2f(-0.4, 0.65);
	glVertex2f(-0.3, 0.9);
	glVertex2f(-0.1, 0.9);
	glVertex2f(0.0, 0.65);
	glVertex2f(-0.1, 0.4);
	glVertex2f(-0.3, 0.4);

	glEnd();

	// heptagon
	glBegin(GL_POLYGON);

	glVertex2f(0.2, 0.55);
	glVertex2f(0.25, 0.75);
	glVertex2f(0.45, 0.9);
	glVertex2f(0.65, 0.75);
	glVertex2f(0.7, 0.55);
	glVertex2f(0.6, 0.3);
	glVertex2f(0.3, 0.3);
	glEnd();


	// octagon
	glBegin(GL_POLYGON);

	glVertex2f(-0.98, -0.5);
	glVertex2f(-0.98, -0.2);
	glVertex2f(-0.88, 0.0);
	glVertex2f(-0.68, 0.0);
	glVertex2f(-0.58, -0.2);
	glVertex2f(-0.58, -0.5);
	glVertex2f(-0.68, -0.7);
	glVertex2f(-0.88, -0.7);
	glEnd();

	// nonagon
	glBegin(GL_POLYGON);

	glVertex2f(-0.4, -0.5);
	glVertex2f(-0.42, -0.3);
	glVertex2f(-0.38, -0.1);
	glVertex2f(-0.2, 0.0);
	glVertex2f(-0.02, -0.1);
	glVertex2f(0.02, -0.3);
	glVertex2f(0.0, -0.5);
	glVertex2f(-0.08, -0.7);
	glVertex2f(-0.32, -0.7);
	

	glEnd();

	// decagon
	glBegin(GL_POLYGON);

	glVertex2f(0.2, -0.5);
	glVertex2f(0.18, -0.3);
	glVertex2f(0.22, -0.1);
	glVertex2f(0.3, 0.0);
	glVertex2f(0.5, 0.0);
	glVertex2f(0.58, -0.1);
	glVertex2f(0.62, -0.3);
	glVertex2f(0.6, -0.5);
	glVertex2f(0.5, -0.6);
	glVertex2f(0.3, -0.6);

	glEnd();


	glutSwapBuffers();
}