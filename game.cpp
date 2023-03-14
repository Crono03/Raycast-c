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
#include "game.h"



// Posizione del giocatore
float playerPosX = 2.0f;
float playerPosZ = 2.0f;

// Direzione in cui guarda il giocatore
float playerDirX = -1.0f;
float playerDirZ = 0.0f;

// Angolo di apertura della camera
float fov = M_PI / 4.5f;

// Aggiungiamo una variabile per tenere traccia dell'angolo di rotazione
float angle = 12.00f;





