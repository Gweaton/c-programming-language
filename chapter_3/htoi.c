#include <stdio.h>

int htoi(char string[])
{
  int n = 0;
  int starting_index = 0;
  if (string[0] == 0 && (string[1] == 'x' || string[1] == 'X'))
    starting_index += 2;

  for(int i =  starting_index; string[i] != '\0'; i++) {
    int c = string[i];
    if (c >= 'A' && c <= 'F')
      // * 16 to move across a digit
      // c + 10 - 'A': 'A' is 10 in decimal, so this offsets its value to a hex
      n = n * 16 + c + 10 - 'A';
    if (c >= 'a' && c <= 'f')
      n = n * 16 + c + 10 - 'a';
    if (c >= '0' && c <= '9')
      n = n * 16 + c - '0';
  }
    return n;
}

int main() {
  printf("%d", htoi("B"));
}
