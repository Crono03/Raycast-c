#include "createWindow.h"
#include "windows.h"
#include "3d.h"

    
    void Pixelstate(HWND hwnd)
{
PAINTSTRUCT ps;
HDC hdc = BeginPaint(hwnd, &ps);

// ottieni le dimensioni della finestra
RECT rect;
GetClientRect(hwnd, &rect);
int width = rect.right - rect.left;
int height = rect.bottom - rect.top;

// imposta le dimensioni di ogni cella
int cellWidth = width/(WINDOW_WIDTH/2);
int cellHeight = height/(WINDOW_HEIGHT/2);

// variabile di controllo per l'alternanza dei colori
BOOL isBlack = TRUE;

// disegna la scacchiera
for(int y=0; y<height; y+=cellHeight)
{
    for(int x=0; x<width; x+=cellWidth)
    {
        
    EndPaint(hwnd, &ps);
}
        
    
    
    