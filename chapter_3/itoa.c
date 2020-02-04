#include <string.h>
#include <stdio.h>
// convert a number to character string

void reverse(char s[])
{
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j++) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itoa(int n, char s[])
{
  int i, sign;

  if ((sign = n) < 0) /* save sign */
    n = -n; /* make n positive if less than 0*/
  i = 0;
  do {
    /* generate digits in reverse order */
    s[i++] = n % 10 + '0'; // get next digit
  } while ((n /= 10) > 0); // delete it
  
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

int main()
{
  char s[] = "1234";
  itoa(5, s);
  printf("%s", s);
  return 0;
}
