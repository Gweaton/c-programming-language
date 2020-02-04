#include <stdio.h>

#define swap(t,x,y) { t = x, x = y, y = t; };

int main() {
  int i;
  int x = 0;
  int y = 2;
  swap(i, x, y);
  printf("x is %d, y is %d", x, y);
}
