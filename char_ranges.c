#include <stdio.h>

int char_range();

int main() {
  return char_range();
}

int char_range() {
  signed char c = 0;
  signed char i = 0;

  while(c >= i) {
    printf("%d,", c);
    c++;
  }

  printf("%s %d\n", "Min computed char value: ", c);

  while(c <= i) {
    printf("%d,", c);
    c--;
  }

  printf("%s %d\n", "Max computed char value:", c);

  return 0;
}
