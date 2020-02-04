#include <stdio.h>

int main() 
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;


  printf("%s\t%s\n", "Celsius", "Fahrenheit");

  for (celsius = upper; celsius >= 0; celsius -= step) {
    fahr = celsius * 9.0 / 5.0 + 32;

    printf("%.0f\t%.0f\n", celsius, fahr);
  }
}
