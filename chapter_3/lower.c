#include <stdio.h>

int lower(int c)
{
  if (c >= 'A' && c <= 'Z') {
    return c + 'a' - 'A';
  }
  else
    return 0;
}

int main() {
  printf("%c", lower('V'));
  return 0;
}
