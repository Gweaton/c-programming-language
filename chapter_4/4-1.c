#include <stdio.h>

int strrindex(char s[], char t[]);
char remainingString(char string[], int index)[];

int main()
{
  printf("%d", strrindex("I am a string string", "ring"));
  return 0;
}

int strrindex(char string[], char substring[]) {
  int i, j, k;

  for (i = 0; string[i] != '\0'; i++) {
    for (j = i, k = 0; substring[k] != '\0' && string[j] == substring[k]; j++, k++)
      ;
    if (k > 0 && substring[k] == '\0')
      if (string[i] != '\0') {
        strrindex(remainingString(string, index), substring);
      }
      else
        return i;
  }

  return -1;
}

char remainingString(char string[], int index)[] {
  int length = 0;

  for(int i = 0; string[i] != '\0'; i++)
    length++;

  char newString[length];

  for (int i = index; string[i] != '\0'; i++)
    newString[i] = string[index];

  return newString;
}
