#include <stdio.h>
#include <string.h>
#include <wchar.h>

int main() {
  wchar_t a[] = L"Hello!";
  printf("%zu\n", sizeof(a)); // 14

  wchar_t* pw = L"Hello!";
//size_t length = strlen(pw); // 1
  size_t length = wcslen(pw); // 6
  printf("%zu\n", length);
}