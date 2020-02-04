#include <stdio.h>

void badSwap(int x, int y);
void swap(int *x, int *y);

int main() {
  int x = 1;
  int y = 2;
  badSwap(x, y);
  printf("x is: %d\n", x);
  printf("y is: %d\n", y);

// pass in address of x, y
  swap(&x, &y);
  printf("x is: %d\n", x);
  printf("y is: %d\n", y);
}

void badSwap(int x, int y)
{
  int temp;
  printf("badSwap: \n");

  temp = x;
  x = y;
  y = temp;
}

// overwrite whatever is at the address x and y
void swap(int *x, int *y)
{
  int temp;

  printf("good swap: \n");
  temp = *x;
  *x = *y;
  *y = temp;
}
