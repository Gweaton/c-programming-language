#include <stdio.h>

int main()
{
  int num = 5;
  printf("Value: %d\n", num);

  int* pointer = &num;
  printf("Address: %u\n", pointer);

  int actualNum = *pointer;
  printf("Value at address: %d\n", actualNum);

  return 0;
}
