// Displays "Hello, Windows 98!" in client area

#include <Windows.h>
#pragma comment(lib, "User32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "winmm.lib")

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE instance, HINSTANCE prevInstance,
    PSTR cmdLine, int cmdShow) {
  static TCHAR appName[] = TEXT("HelloWin");

  WNDCLASS wndclass;
  wndclass.style = CS_HREDRAW | CS_VREDRAW;
  wndclass.lpfnWndProc = WindowProcedure;
  wndclass.cbClsExtra = 0;
  wndclass.cbWndExtra = 0;
  wndclass.hInstance = instance;
  wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
  wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
  wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
  wndclass.lpszMenuName = NULL;
  wndclass.lpszClassName = appName;

  if (!RegisterClass(&wndclass)) {
    MessageBox(NULL, TEXT("This program requires Windows NT!"),
        appName, MB_ICONERROR);
    return 0;
  }

  HWND window = CreateWindow(appName, // window class name
      TEXT("The Hello Program"),      // window caption
      WS_OVERLAPPEDWINDOW,            // window style
      CW_USEDEFAULT,                  // initial x position
      CW_USEDEFAULT,                  // initial y position
      CW_USEDEFAULT,                  // initial x size
      CW_USEDEFAULT,                  // initial y size
      NULL,                           // parent window handle
      NULL,                           // window menu handle
      instance,                       // program instance handle
      NULL);                          // creation parameters

  ShowWindow(window, cmdShow);
  UpdateWindow(window);

  MSG message;
  while (GetMessage(&message, NULL, 0, 0)) {
    TranslateMessage(&message);
    DispatchMessage(&message);
  }
  return message.wParam;
}

LRESULT CALLBACK WindowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam) {
  switch (message) {
  case WM_CREATE:
    PlaySound(TEXT("hellowin.wav"), NULL, SND_FILENAME | SND_ASYNC);
    return 0;
  case WM_PAINT: {
    PAINTSTRUCT ps;
    HDC dc = BeginPaint(window, &ps);

    RECT rect;
    GetClientRect(window, &rect);

    DrawText(dc, TEXT("Hello, Windows 98!"), -1, &rect,
        DT_SINGLELINE | DT_CENTER | DT_VCENTER);
    
    EndPaint(window, &ps);
    return 0;
  }
  case WM_DESTROY:
    PostQuitMessage(0);
    return 0;
  default:
    return DefWindowProc(window, message, wParam, lParam);
  }
}