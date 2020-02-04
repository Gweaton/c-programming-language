#include <stdio.h>
// convert a string to an integer
int atoi(char s[])
{
  int i, n;

  n = 0;

  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
    n = 10 * n + (s[i] - '0');
    printf("%d\n", n);
  }
  return n;
}

int main() {
  printf("%d", atoi("234"));
  return 0;
}
