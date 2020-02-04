#include <stdio.h>

int main() {
  int c;
  int charsPerWord[10];
  int maxHeight = 0;

  for (int i = 0; i < 10; i++) {
    charsPerWord[i] = 0;
  }

  int wordIndex = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      wordIndex++;
    } else {
      charsPerWord[wordIndex]++;
    }
  }

  for (int i = 0; i < 10; i++) {
    if (maxHeight <= charsPerWord[i]) {
      maxHeight = charsPerWord[i];
    }
  }

  for (int i = maxHeight; i >= 0; i--) {
    for (int j = 0; j < 10; j++) {
      if (charsPerWord[j] > i) {
        putchar('*');
      } else {
        putchar(' ');
      }
    }
    putchar('\n');
  }
}
