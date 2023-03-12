#pragma once
#include <Windows.h>
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480 
typedef struct {
    HWND hwnd;
    HDC hdc;
} WindowData;

LRESULT CALLBACK MyWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CreateMainWindow(WindowData* pData);
void Pixelstate(HWND hwnd);
void SetScreenToBlack(HWND hwnd);
