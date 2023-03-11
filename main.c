#include "windows.h"
#include "createWindow.h"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
    WindowData data = { 0 };
    if (!CreateMainWindow(&data)) {
        MessageBox(NULL, "Impossibile creare la finestra", "Errore", MB_OK | MB_ICONERROR);
        return 1;
    }
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    ReleaseDC(data.hwnd, data.hdc);


    return 0;
}