#include <GLFW\glfw3.h>
#include "linmath.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	// initialization
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	GLFWwindow* window = glfwCreateWindow(550, 550, "Moving Ball", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	float D2R = 3.14159 / 180;
	float radius = 0.2;
	float x = 0.5, y = 0.0;
	int xDir = 1, yDir = 1;

	while (!glfwWindowShouldClose(window)) {
		//Setup View
		float ratio;
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float)height;
		glViewport(0, 0, width, height);
		glClearColor(0.30588f, 0.764706f, 0.30196f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		// move
		if (xDir)
			x += 0.02;
		else
			x -= 0.02;

		if (x >= 0.8)
			xDir = 0;
		else if (x <= -0.8)
			xDir = 1;

		if (yDir)
			y += 0.02;
		else
			y -= 0.02;

		if (y >= 0.8)
			yDir = 0;
		else if (y <= -0.8)
			yDir = 1;

		// drawing
		glColor3f(1.0, 0.8862745, 0.345098);
		glBegin(GL_POLYGON);
		for (int i = 0; i <= 360; i++) {
			float radDeg = i * D2R;
			glVertex2f((cos(radDeg)*radius) + x, (sin(radDeg)*radius) + y);
		}
		glEnd();

		//Swap buffer and check for events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate;
	exit(EXIT_SUCCESS);
}