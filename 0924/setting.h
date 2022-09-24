#pragma once

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) //Window's size
{
	glViewport(0, 0, width, height);
}

float vertices[] = //Triangle's vertex
{
	-0.5f,-0.5f,0.0f,
	0.5f, -0.5f, 0.0f,
	0.0f, 0.5f, 0.0f
};

void processInput(GLFWwindow* window) //
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)

		glfwSetWindowShouldClose(window, true);
}

unsigned int VBO;