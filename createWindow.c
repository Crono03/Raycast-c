#include "createWindow.h"
#include "windows.h"
const char* CLASS_NAME = "My Window Class";
const char* WINDOW_TITLE = "My Window";


const COLORREF color1 = RGB(255, 255, 255); // Bianco
const COLORREF color2 = RGB(0, 0, 0);       // Nero
COLORREF currentColor = color1;

VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime) {
        
    }


LRESULT CALLBACK MyWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static int squareSize = 50;
    static int numSquaresX = 8;
    static int numSquaresY = 8;
    PAINTSTRUCT ps;
    HDC hdc ;
    RECT clientRect;
    RECT squareRect;
    int rows= 10;
    int cols= 10;
    RECT rcClient;

   switch (uMsg) {
      case WM_PAINT: {
        
            Pixelstate(hwnd);
        break;
         
      }
    

    case WM_DESTROY: {
        PostQuitMessage(0);
        break;
    }
    default:{
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
   }
    return 0;
}

BOOL CreateMainWindow(WindowData* pData) {
    WNDCLASSEX wc = { 0 };
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = MyWindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(CreateSolidBrush(RGB(255,255,255)));
    wc.lpszClassName = CLASS_NAME;
    RegisterClassEx(&wc);

    RECT rc = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

    HWND hwnd = CreateWindowEx(0, CLASS_NAME, WINDOW_TITLE,
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        rc.right - rc.left, rc.bottom - rc.top, NULL, NULL,
        GetModuleHandle(NULL), NULL);
    if (!hwnd) {
        return FALSE;
    }
    

    pData->hwnd = hwnd;
    pData->hdc = GetDC(hwnd);

    ShowWindow(hwnd, SW_SHOWDEFAULT);

    


   SetTimer(hwnd, 1, 2000, TimerProc); 
    UpdateWindow(hwnd);
    

    return TRUE;
}
