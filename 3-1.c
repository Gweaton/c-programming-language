#include <stdio.h>

int binsearch(int x, int array[], int length);

int main() {
  int my_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  printf("%d", binsearch(1, my_array, 10));
}

int binsearch(int x, int array[], int length) {
  int start, end, mid;
  start = 0;
  end = length - 1;

  while(start <= end) {
    mid = (start + end) / 2;

    if (x < array[mid]) {
      end = array[mid] - 1;
    } else {
      start = array[mid] + 1;
    }

  }
  return x == array[mid] ? mid : -1;
}
