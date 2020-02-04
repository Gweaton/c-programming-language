#include <stdio.h>

int main()
{
  int c;
  int ns = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (ns == 0) {
        putchar(c);
      }
      ns++;
    } else {
      putchar(c);
      ns = 0;
    }
  }
}
