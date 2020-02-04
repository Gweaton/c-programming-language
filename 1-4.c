#include <stdio.h>

int main() 
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  celsius = lower;

  printf("%s\t%s\n", "Celsius", "Fahrenheit");

  while (celsius <= upper) {
    fahr = celsius * 9.0 / 5.0 + 32;

    printf("%.0f\t%.0f\n", celsius, fahr);

    celsius += step;
  }
}
