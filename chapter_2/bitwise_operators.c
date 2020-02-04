#include <stdio.h>

int main() {
  return 0;
}

unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  // get rightmost n bits of y from position p
  // getbits(y, p, n);
  //
  return (x )
}
