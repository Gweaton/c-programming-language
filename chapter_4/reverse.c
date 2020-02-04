#include <stdio.h>
#include <string.h>

void swap(char string[], int i, int j) {
  int temp;

  temp = string[i];
  string[i] = string[j];
  string[j] = temp;
}

void reverse(char string[], int start, int end)
{
  if (start < end)
  {
    swap(string, start, end);
    printf("string: %s\n", string);
    reverse(string, ++start, --end);
  }
}


int main()
{
  char toReverse[] = "I am a string";
  reverse(toReverse, 0, strlen(toReverse) - 1);
  printf("%s", toReverse);
}
