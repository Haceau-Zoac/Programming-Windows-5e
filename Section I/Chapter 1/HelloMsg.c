// Displays "Hello, Windows 98!" in a message box

#include <Windows.h>
// Solve LNK error
#pragma comment(lib, "User32.lib")

int WINAPI WinMain(HINSTANCE instance, HINSTANCE prevInstance,
    PSTR cmdLine, int cmdShow) {
  MessageBox(NULL, TEXT("Hello, Windows 98!"), TEXT("HelloMsg"), 0);
}