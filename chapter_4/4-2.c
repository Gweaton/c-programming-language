#include <ctype.h>
#include <stdio.h>

double atof(char s[])
{
  double value, power, exponent, total, total_exp;
  int i, sign, exp_sign;

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

  total = sign * value / power;

  if (s[i] == '\0')
    return total;

  // skip e notation
  if (s[i] == 'e' || s[i] == 'E')
    i++;
  exp_sign = (s[i] == '-') ? -1 : 1;
  // skip sign
  if(s[i] == '+' || s[i] == '-')
    i++;

  for (exponent = 0.0; isdigit(s[i]); i++) {
    exponent = 10.0 * exponent + (s[i] - '0');
  }

  total_exp = 1.0;
  for (int j = 0; j < exponent; j++) {
    if (exp_sign == -1)
      total_exp /= 10.0;
    else
      total_exp *= 10.0;
  }

  total = total * total_exp;


  //divide by power as we want to get it back to decimal
  return total;
}

int main() {
  printf("%f", atof("123.45e3"));

  return 0;
}
