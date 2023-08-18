#include <windows.h>
#include "helper.h"

void OnDestroy(HWND);
int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR arg, int nCmdShow)
{
    MSG m;
    InitInstance(hInstance, nCmdShow, "title");
    while (GetMessage(&m, 0, 0, 0))
        DispatchMessage(&m);
    return 0;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM IParam)
{
    switch (message)
    {
    case WM_DESTROY:
        OnDestroy(hWnd);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, IParam);
    }
    return 0;
}
void OnDestroy(HWND hWnd)
{
    PostQuitMessage(0);
}
