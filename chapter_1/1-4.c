#include <stdio.h>

main()
{
  float fahrenheit, celsius;
  int min, max, step;

  min = 0;
  max = 300;
  step = 20;

  celsius = min;
  printf("Celsius Fahrenheit\n");
  while (celsius <= max) {
    fahrenheit = celsius * (9.0 / 5.0) + 32;
    printf("%7.0f %10.1f\n", celsius, fahrenheit);
    celsius += step;
  }
}
