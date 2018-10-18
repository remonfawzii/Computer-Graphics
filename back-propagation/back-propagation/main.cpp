#include<iostream>
#include<GL/GLUT.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define PI acos(-1)

int press = 0;
// layer 1 options
float layer1x[4] = { 130.0, 130.0, 130.0, 130.0 };
float layer1y[4] = { 160.0, 160.0, 160.0, 160.0 };
float layer1defaultColor[3] = { 0.1568, 0.4823, 0.717 };
float layer1changeColor[3] = { 0.1568, 0.4823, 0.717 };
int iterator1 = 1;

// layer 2 options
float layer2x[5] = { 350.0, 350.0, 350.0, 350.0, 350.0 };
float layer2y[5] = { 115.0, 115.0, 115.0, 115.0, 115.0 };
float layer2defaultColor[3] = { 0.749, 0.243137, 0.243137 };
float layer2changeColor[3] = { 0.749, 0.243137, 0.243137 };
int iterator2 = 1;

// layer 3 options
float layer3x[5] = { 570.0, 570.0 };
float layer3y[5] = { 240.0, 240.0 };
float layer3defaultColor[3] = { 0.3176, 0.19215, 0.69411 };
float layer3changeColor[3] = { 0.3176, 0.19215, 0.69411 };
int iterator3 = 1;


// handle key press
void handleKey(unsigned char key, int x, int y) {
	switch (key) {
	case 115: // s key
		press++;
	}
}

// drawing circle
void circle(float radius, int vNum, float x, float y) {

	glVertex2f(0.0f + x, 0.0f + y);

	for (int i = 0; i <= vNum; i++) {
		glVertex2f((radius * cosf(i*2*PI / vNum)) + x, (radius * sin(i*2*PI / vNum)) + y);
	}

	glEnd();

}

// drawing line
void line(float x1, float y1, float x2, float y2) {
	glVertex3f(x1, y1, 0.0);
	glVertex3f(x2, y2, 0.0);
	glEnd();
}

// initialization function
void init(void)
{
	glLoadIdentity();
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 1200, 0, 600);
}


// display function
void render() {
	glLineWidth(1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);

	// draw first layer neurals
	for (int i = 0; i < 4; i++) {
		glBegin(GL_TRIANGLE_FAN);
		if (i == 1)
			glColor3f(layer1defaultColor[0], layer1defaultColor[1], layer1defaultColor[2]);
		else
			glColor3f(layer1changeColor[0], layer1changeColor[1], layer1changeColor[2]);
		circle(30, 300, layer1x[i], layer1y[i]);
	}

	// draw second layer neurals
	for (int i = 0; i < 5; i++) {
		glBegin(GL_TRIANGLE_FAN);
		if (i == 1 || i == 3)
			glColor3f(layer2changeColor[0], layer2changeColor[1], layer2changeColor[2]);
		else
			glColor3f(layer2defaultColor[0], layer2defaultColor[1], layer2defaultColor[2]);
			
		circle(30, 300, layer2x[i], layer2y[i]);
	}

	// draw third layer neurals
	for (int i = 0; i < 2; i++) {
		glBegin(GL_TRIANGLE_FAN);
		if (i == 1)
			glColor3f(layer3defaultColor[0], layer3defaultColor[1], layer3defaultColor[2]);
		else
			glColor3f(layer3changeColor[0], layer3changeColor[1], layer3changeColor[2]);
		circle(30, 300, layer3x[i], layer3y[i]);
	}

	// draw first group of lines	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			glBegin(GL_LINES);
			glColor3f(0.266667, 0.266667, 0.266667);
			line(layer1x[i], layer1y[i], layer2x[j], layer2y[j]);
		}
	}

	// draw second group of lines	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 2; j++) {
			glBegin(GL_LINES);
			glColor3f(0.266667, 0.266667, 0.266667);
			line(layer2x[i], layer2y[i], layer3x[j], layer3y[j]);
		}
	}

	// animations
	// first press
	if (press == 1 && iterator1 < 4) {
		if (layer1y[iterator1] < (iterator1 * 80 + 160)) {
			layer1y[iterator1]++;
		} else {
			iterator1++;
		}
	}

	// second press
	else if (press == 2 && iterator2 < 5) {
		if (layer2y[iterator2] < (iterator2 * 80 + 115))
			layer2y[iterator2]++;
		else
			iterator2++;
	}
	// third press
	else if (press == 3 && iterator3 < 2) {
		if (layer3y[iterator3] < (iterator3 * 80 + 240))
			layer3y[iterator3]++;
		else
			iterator3++;
	}
	// fourth press
	else if (press == 4) {
		layer1changeColor[0] = 0.317647;
		layer1changeColor[1] = 0.9568627;
		layer1changeColor[2] = 0.2196078;
	}
	// fifth press
	else if (press == 5) {
		layer1changeColor[0] = 0.1568;
		layer1changeColor[1] = 0.4823;
		layer1changeColor[2] = 0.717;

		layer2changeColor[0] = 0.317647;
		layer2changeColor[1] = 0.9568627;
		layer2changeColor[2] = 0.2196078;
	}
	// sixth press
	else if (press == 6) {
		layer2changeColor[0] = 0.749;
		layer2changeColor[1] = 0.243137;
		layer2changeColor[2] = 0.243137;

		layer3changeColor[0] = 0.317647;
		layer3changeColor[1] = 0.9568627;
		layer3changeColor[2] = 0.2196078;
	}
	glFlush();
}

// disable resize
void handleResize(int width, int height) {
	glutReshapeWindow(1200, 600);
}

void main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1200, 600);
	glutCreateWindow("Animation Example");
	init();

	glutReshapeFunc(handleResize);
	glutDisplayFunc(render);
	glutKeyboardFunc(handleKey);
	glutIdleFunc(render);
	glutMainLoop();

}
