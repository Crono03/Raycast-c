#pragma once

#include <SDL2-2.26.4\include\SDL.h>

void Raytracing(SDL_Renderer *renderer, int map[5][5], int COL, int ROW, float PosX, float PosZ, int DirX, int DirZ, double FOV);