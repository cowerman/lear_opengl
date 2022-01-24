#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(int argc, char *argv[])
{

	float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	0.5f,  -0.5f, 0.0f,
	0.0f,  0.5f,  0.0f,
	};
	unsigned int vbo;
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);




	return 0;
}
