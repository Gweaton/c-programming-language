#include <stdio.h>

// print fahrenheit to celsius table between 0 and 300
int main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  printf("%s\t%6s\n", "Fahrenheit", "Celsius");
  while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr - 32);

    printf("%10.0f\t%7.1f\n", fahr, celsius);
    fahr += step;
  }
}
