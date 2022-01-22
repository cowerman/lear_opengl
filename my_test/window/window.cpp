#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <unistd.h>
#include <iostream>

#define WIDTH     (800UL)
#define HEIGTH    (600UL)

static void framebuffer_size_callback(GLFWwindow *window, int width, int height);
static void processInput(GLFWwindow *window);

int main(int argc, char *argv[])
{
	/* init glfw */
	glfwInit();

	/* set both glfw window hint major/minfor version to 3 */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	/* use the opengl core profile function */
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* create window */
	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGTH, "LearOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	/* set the hint options to window context */
	glfwMakeContextCurrent(window);

	/* init openGL function pointer with GLAD */
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
	    std::cout << "Failed to initialize GLAD" << std::endl;
	    return -1;
	}

	/* register call back for the framebuffer size call back */
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	while (!glfwWindowShouldClose(window)) {
		processInput(window);

		/* rendering instructions, here is set color of clear screen */
		glClearColor(0.2f, 0.3f, 0.3f, 0.1f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	/* terminate the opengl rendering */
	glfwTerminate();

	return 0;
}

static void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{

	/* tell opengl the window w*h and start position to set viewport */
	glViewport(0, 0, width, height);

}

static void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}
