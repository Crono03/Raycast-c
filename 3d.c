#define _USE_MATH_DEFINES
#include "createWindow.h"
#include "math.h"
#include "3d.h"
#include "createWindow.h"



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

void Raytracing(){
   
    //giocatore
    float PosX;
    float PosZ;

    //ndo cazzo guardi
    int DirX=0;
    int DirZ=-1;
    
    //camera
    double FOV=M_PI_4;
    const int ROW = 5;
    const int COL = 5;

    //mappa
    int map[COL][ROW] = {
        {0, 0, 0, 0, 0},
        {1, 1, 1, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}
    };

    //Player start
    PosX=floor(COL/2);
    PosZ=floor(ROW/2);

    for (int i = -FOV/2; i < FOV/2; i++)
    {
        
    }
    
};







