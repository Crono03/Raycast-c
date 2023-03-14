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
#include "engine.h"

const int map[5][5] = {
    {1, 0, 0, 0, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1}
};



extern float playerPosX;
extern float playerPosZ;


extern float playerDirX;
extern float playerDirZ;


extern float fov;


extern float angle;