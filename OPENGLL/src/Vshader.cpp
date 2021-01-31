#define GLEW_STATIC
#include <GL/glew.h>
#include<GLFW/glfw3.h>
#include<iostream>
#version 330 core
layout(location = 0) in vec3 position;

int main()
{
	
    layout(location = 0) in vec3 position; //GLSL has a vector
		//datatype that contains 1 to 4 floats based on its postfix digit.Since //each vertex has a 3D coordinate we create a vec3 input //variable with the name position

	GLuint Vshader;
	Vshader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(Vshader, 1, &vertexshadersource, NULL); //we attach the shader source code to the shader object and compile the shader
	glCompileShader(Vshader);
	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(VShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(VShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" <<
			infoLog << std::endl;
	}


	out vec4 color; //We can declare output values with the out keyword

	color = vec4(1.0f, 0.5f, 0.2f, 1.0f);

	GLuint Fshader;
	Fshader = glCreateShader(GL_FRAGMENT_SHADER);
	Glshadersource(Fshader, 1, &FragmentShadersource, NULL);
	glCompileShader(Fshader);

	Gluint shaderProgram;
	shaderProgram = glCreateProgram();










	
}