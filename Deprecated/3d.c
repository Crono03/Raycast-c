#define _USE_MATH_DEFINES
#include "createWindow.h"
#include "math.h"
#include "3d.h"
#include "createWindow.h"
#include <SDL2-2.26.4\include\SDL.h>

void SetScreenToBlack(HWND hwnd)
{
    HDC hdc = GetDC(hwnd);
    RECT rect;
    GetClientRect(hwnd, &rect);
    HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
    FillRect(hdc, &rect, brush);
    ReleaseDC(hwnd, hdc);
    DeleteObject(brush);
}

void Raytracing(SDL_Renderer *renderer, int map[5][5], int COL, int ROW, float PosX, float PosZ, int DirX, int DirZ, double FOV)
{

    for (int i = -FOV / 2; i < FOV / 2; i++)
    {
        int RayX = PosX;
        int RayZ = PosZ;
        while (map[RayZ][RayX] != 1)
        {
            RayX += DirX;
            RayZ += DirZ;
        }
        double dist = sqrt(pow(RayX - PosX, 2) + pow(RayZ - PosZ, 2));
        int wallHeight = 100;
        int wallTop = (ROW - wallHeight) / 2;
        int wallColor = 0x00FF00FF; // purple

        // calculate the x coordinate on screen based on FOV and current ray angle
        int screenX = (i + FOV / 2) * WINDOW_WIDTH / FOV;
        // calculate the height of the wall based on its distance from the player and the screen height
        int wallScreenHeight = wallHeight * WINDOW_HEIGHT / (int)dist;
        // calculate the y coordinate on screen based on the wall height and position
        int screenY = wallTop + (WINDOW_HEIGHT - wallScreenHeight) / 2;
        // draw the wall
        SDL_SetRenderDrawColor(renderer, (wallColor >> 24) & 0xFF, (wallColor >> 16) & 0xFF, (wallColor >> 8) & 0xFF, wallColor & 0xFF);
        SDL_RenderDrawLine(renderer, screenX, screenY, screenX, screenY + wallScreenHeight);
    }
}
