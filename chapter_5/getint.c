#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

// get a character from buffer, or input if empty
int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

// push character back on input
void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

int getint(int *pn)
{
  int c, sign;
  //skip whitespace
  while (isspace(c = getch()))
    ;

  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    // if not a number, treat as 0 and add to buffer
    ungetch(c);
    return 0;
  }

  sign = (c == '-') ? -1 : 1;

  // get next character from buffer if a + or -
  if (c == '+' || c == '-') {
    int nextch = getch();
    if (isdigit(nextch)) {
      c = nextch;
    } else {
      ungetch(nextch);
      ungetch(c);
    }
  }

  //convert each digit to int, multiply by 10
  for (*pn = 0; isdigit(c); c = getch()) {
    *pn = 10 * *pn + (c - '0');
  // make negative if necessary
  }

  *pn *= sign;

  if (c != EOF)
    ungetch(c);

  return c;
}

int getfloat(double *pn)
{
  int c, sign;
  double power;
  //skip whitespace
  while (isspace(c = getch()))
    ;

  if (!isdigit(c) && c != '.' && c != EOF && c != '+' && c != '-') {
    // if not a number, treat as 0 and add to buffer
    ungetch(c);
    return 0;
  }

  sign = (c == '-') ? -1 : 1;

  // get next character from buffer if a + or -
  if (c == '+' || c == '-') {
    int nextch = getch();
    if (isdigit(nextch)) {
      c = nextch;
    } else {
      ungetch(nextch);
      ungetch(c);
    }
  }

  //convert each digit to int, multiply by 10
  for (*pn = 0.0; isdigit(c); c = getch()) {
    *pn = 10.0 * *pn + (c - '0');
    printf("%f", *pn);
  // make negative if necessary
  }

  // skip decimal point and get next number
  if (c == '.') {
    c = getch();
  }

  for (power = 1.0; isdigit(c); c = getch()) {
    *pn = 10.0 * *pn + (c - '0');
    printf("%f", *pn);
    power = power * 10.0;
  }

  *pn *= sign * *pn / power;

  if (c != EOF)
    ungetch(c);

  return c;
}

int main() {
  int n, s;
  double array[BUFSIZE];

  for (n = 0; n < BUFSIZE && getfloat(&array[n]) != EOF; n++);

  // print out result
  for(s=0;s < n; s++)
    printf("%f",array[s]);
  return 0;
}
