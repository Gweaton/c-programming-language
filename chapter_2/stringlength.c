#include <stdio.h>

int stringlength(char string[]);

int main()
{
  printf("%d", stringlength("hello"));
}

int stringlength(char string[]) {
  int i = 0;
  while (string[i] != '\0') {
    i++;
  }
  return i;
}
