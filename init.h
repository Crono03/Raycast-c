#pragma once
#define GLFW_INCLUDE_NONE
#define _USE_MATH_DEFINES
#include "windows.h"
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <math.h>
#include <iostream>
#include <cstdlib>
#include "GL/glut.h"

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
GLFWwindow* preRender();
void Render();