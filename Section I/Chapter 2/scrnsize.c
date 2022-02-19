// Displays screen size in a message box

#include <Windows.h>
#include <stdarg.h>
#include <tchar.h>
#include <stdio.h>
#pragma comment(lib, "User32.lib")

int CDECL MessageBoxPrintf(TCHAR* caption, TCHAR* format, ...) {
  va_list argList;

  // The va_start macro (defined in stdarg.h) is usually equivalent to:
  // argList = (char*)&format + sizeof(format)
  va_start(argList, format);

  TCHAR buffer[1024];
  // The last argument to wvsprintf points to the arguments
  _vsntprintf(buffer, sizeof(buffer) / sizeof(buffer[0]),
      format, argList);

  // The va_end macro just zeros out argList for no good reason
  va_end(argList);

  return MessageBox(NULL, buffer, caption, MB_OK);
}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE prevInstance,
    PSTR cmdLine, int cmdShow) {
  struct {
    int x;
    int y;
  } screen;
  screen.x = GetSystemMetrics(SM_CXSCREEN);
  screen.y = GetSystemMetrics(SM_CYSCREEN);
  MessageBoxPrintf(TEXT("ScrnSize"),
      TEXT("The screen is %i pixels wide by %i pixels high."),
      screen.x, screen.y);
}