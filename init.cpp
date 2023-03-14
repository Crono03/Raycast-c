#define GLFW_INCLUDE_NONE
#define _USE_MATH_DEFINES
#include "windows.h"
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <math.h>
#include <iostream>
#include <cstdlib>
#include "GL/glut.h"
#include "init.h"

// Dimensioni della finestra
 const int WINDOW_WIDTH = 1080;
 const int WINDOW_HEIGHT = 720;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

