#define GLEW_STATIC
#include <GL/glew.h>
#include<GLFW/glfw3.h>
#include<iostream>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
int main()
{
	glfwInit();  //instantiate the GLFW window or GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //WindowHint to configure GLFW - (First Argument -which option to configure prefixed with GLFW_,second argument-it's value)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	//we’d like to tell GLFW that 3.3 is
	//the OpenGL version we want to use.This way GLFW can make the proper arrangements when
		//creating the OpenGL context.This ensures that when a user ////does not have the proper OpenGL
	//	version GLFW fails to run.We set the major and minor version both to 3. We also tell GLFW
		//we want to explicitly use the core - profile and that the //window should not be resizable by a user
	

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL",nullptr,nullptr);  //This window object holds all the windowing data and is used quite frequently by GLFW’s other
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);  //This window object holds all the windowing data and is used quite frequently by GLFW’s other functions.Context of our window the main context on the current thread.
	
	glewExperimental = GL_TRUE; //GLEW manages function pointers for OpenGL

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}
	//Setting glewExperimental to true ensures GLEW uses more modern techniques for managing
		//OpenGL functionality.Leaving it to its default value of GL_FALSE might give issues when using
		//the core profile of OpenGL



	glViewport(0, 0, 800, 600);// Viewport is the place where rendered  objects are displayed//The first two parameters set the location of the lower left corner of the window.The third
	//	and fourth parameter set the width and height of the rendering window, which is the same as the
	//	GLFW window

	glfwSetKeyCallback(window, key_callback);
	
	while (!glfwWindowShouldClose(window))  //GAME LOOP
	{
		glfwPollEvents();//eventprocessing funcs.  //used to direct 
		//callback funcs. or call callback funcs. 
		//rendering commands
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);//Whenever we call glclear the entire buffer will be filledn with colour set by glclearcolour
		glClear(GL_COLOR_BUFFER_BIT); //other buffer bits include DEPTH BUFFER BIT AND STENCIL
		//glClearColor function is a statesettingfunction and glClear is a state - using function in that it uses the current state
	//to retrieve the clearing color from.
		//
		//
		
		
		glfwSwapBuffers(window);//will swap the colour buffer//that has been used to draw in during this iteration and show it
		//as output to the screen
	}
//A callback function is basically a function pointer that you can set that
		//GLFW can call at an appropriate time.
	glfwTerminate();

	
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	std::cout << key << std::endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}


