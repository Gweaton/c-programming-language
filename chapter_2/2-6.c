

int main() {

}

/*getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
  //mask == 
  int mask = ~(~0 << n) << (p + 1 - n);
  // set last n bits of x to 0: x & ~(~0 << n);
  // x & ~(~0 << n) & getbits(y, p, n)
}




//9713 = 0010 0101 1111 0001
//~mas = 1111 0000 1111 1111
// resu= 0010 0000 1111 0001
