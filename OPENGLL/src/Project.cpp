#define GLEW_STATIC
#include <GL/glew.h>
#include<GLFW/glfw3.h>
#include<iostream>

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
}