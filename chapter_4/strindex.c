#include <stdio.h>
#define MAXLINELENGTH 1000

int getLine(char line[], int maxLength);
int strindex(char string[], char substring[]);
int strrindex(char string[], char substring[]);

char pattern[] = "ould";

int main()
{
  char line[MAXLINELENGTH];
  int found = 0;

  while (getLine(line, MAXLINELENGTH) > 0)
    if (strrindex(line, pattern) >= 0) {
      printf("%s", line);
      found++;
    }
  printf("Found %d matches", found);
  return found;
}

int getLine(char string[], int limit)
{
  int character, i;

  i = 0;

  while (--limit > 0 && (character=getchar()) != EOF && character != '\n')
    string[i++] = character;
  if (character == '\n')
    string[i++] = character;
  string[i] = '\0';
  return i;
}

int strindex(char string[], char substring[])
{
  int i, j, k;

  // loop over string[]
  for (i = 0; string[i] != '\0'; i++) {
    for (j = i, k = 0; substring[k] != '\0' && string[j] == substring[k]; j++, k++)
      ;
    if (k > 0 && substring[k] == '\0')
      return i;
  }
  return -1;
}

int strrindex(char string[], char substring[])
{
  int i, j, k;

  int rightIndex = -1;

  // loop over string[]
  for (i = 0; string[i] != '\0'; i++) {
    for (j = i, k = 0; substring[k] != '\0' && string[j] == substring[k]; j++, k++)
      ;
    if (k > 0 && substring[k] == '\0')
      rightIndex = i;
  }
  printf("%d", rightIndex);
  return rightIndex;
}




// ideas
// 1. loop over string backwards and look for substring
//    - To loop over string backwards, need to get final index of string as starting index for loop
//    - need to loop over substring backwards too e.g. should == dluohs, will need to essentially search for dlou
//2. reverse both strings
//
