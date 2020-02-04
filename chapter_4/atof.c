#include <ctype.h>
#include <stdio.h>

double atof(char s[])
{
  double value, power;
  int i, sign;

  // skip leading whitespace
  for (i = 0;isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  // skip sign
  if(s[i] == '+' || s[i] == '-')
    i++;

  // convert each digit to its numeric (float) value
  // multiply each by 10 for additional 10s column
  for(value = 0.0; isdigit(s[i]); i++) {
    value = 10.0 * value + (s[i] - '0');
  }
  // skip decimal point
  if (s[i] == '.')
    i++;

  for (power = 1.0; isdigit(s[i]); i++) {
    // keep going as if there's no decimal point
    value = 10.0 * value + (s[i] - '0');
    // increase number of 10s
    power *= 10.0;
  }

  //divide by power as we want to get it back to decimal
  return sign * value / power;
}

int atoi(char s[])
{
  return atof(s);
}

int main() {
  printf("%d", atoi("2.0235"));

  return 0;
}
