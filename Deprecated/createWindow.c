#define _USE_MATH_DEFINES
#include <windows.h>
#include "createWindow.h"
#include "3d.h"
#include <SDL2-2.26.4\include\SDL.h>
#include "math.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    HWND hwnd;
    MSG msg;
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = "myWindowClass";
    RegisterClass(&wc);
    hwnd = CreateWindow("myWindowClass", "My Window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, NULL, NULL, hInstance, NULL);
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Inizializza la libreria SDL
    SDL_Init(SDL_INIT_VIDEO);
    // Definisci il renderer SDL
    SDL_Renderer *renderer = SDL_CreateRenderer(SDL_GetWindowFromID(hwnd), -1, SDL_RENDERER_ACCELERATED);

    // Loop principale
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        float PosX;
        float PosZ;

        // ndo cazzo guardi
        int DirX = 0;
        int DirZ = -1;

        // camera
        double FOV = M_PI_4;
        // mappa
        int map[5][5] = {
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}};

        // Player start
        PosX = floor(5 / 2);
        PosZ = floor(5 / 2);

        // Chiama la funzione di ray tracing
        Raytracing(renderer, map, 5, 5, PosX, PosZ, DirX, DirZ, FOV);

        // Aggiorna la finestra con il rendering effettuato dalla funzione di ray tracing
        SDL_RenderPresent(renderer);
    }

    // Libera le risorse utilizzate dalla libreria SDL
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}