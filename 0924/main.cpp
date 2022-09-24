#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "setting.h"

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";


//unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);


int main()
{

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);	//glfwWindowHint: Tell what option we want to configure GLFW using, 3 indicate we are using the 3.3 of OPENGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	vertices;
	//glfwWindowHint(GLFW ? GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //For initialization code on MAC OS X

	//------------------------------------------------------
	//Creation of the window object: Windowing Data
	//------------------------------------------------------

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL); //Create Window
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))		//If GLAD doesn't load properly
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	while (!glfwWindowShouldClose(window))							//While Open Window
	{
		processInput(window);

		glfwSwapBuffers(window);
		glfwPollEvents();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	//------------------------
	//Vertices Coordinations
	//------------------------
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);		//Draw STATIC vertices


	//----------
	//Shader
	//----------
	
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); //Attach the shader source corde to the shader object and compile the shader
	glCompileShader(vertexShader);

	int success;												//Shader Compilation Check Status
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success)					//if the Shader doesn't load properly
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}


	glfwTerminate();
	return 0;
}