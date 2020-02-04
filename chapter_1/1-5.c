#include <stdio.h>

main() {
  float fahrenheit, celsius;
  int min, max, step;

  min = 0;
  max = 300;
  step = 20;

  fahrenheit = max;
  printf("%s %s\n", "Fahrenheit", "Celsius");
  while (fahrenheit >= min) {
    celsius = (5.0/9.0) * (fahrenheit - 32.0);
    printf("%10.0f %7.1f\n", fahrenheit, celsius);
    fahrenheit -= step;
  }
}
