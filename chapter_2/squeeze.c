#include <stdio.h>

void squeeze_two(char string1[], char string2[]);

int main() {
  char string_to_change[] = "helloxf thereo";
  squeeze_two(string_to_change, "xfo");
  printf("%s", string_to_change);
}

void squeeze(char character, char string[]) {
  int i, j;

  for (i = j = 0; string[i] != '\0'; i++) {
    if (string[i] != character) {
      string[j++] = string[i];
    }
  }
  string[j] = '\0';
}

void squeeze_two(char string1[], char string2[]) {
  int i, j, k;
  int isPresent;

  for (i = j = 0; string1[i] != '\0'; i++) {
    isPresent = 0;
    for(k = 0; string2[k] != '\0'; k++) {
      if (string1[i] == string2[k]) {
        isPresent = 1;
      }
    }
    if (!isPresent) {
      string1[j++] = string1[i];
    }
  }
  string1[j] = '\0';
}





/*
 // loop until the end of string1 
  for (i = j = 0; string1[i] != '\0'; i++) {
    // for each character in string1, loop over string2 until the end
    for (k = 0; string2[k] != '\0'; k++) {
      if (string1[i] != string2[k]) {
        string1[j++] = string1[i]; 
      }
    }
    string1[j] = '\0';
  }
}
*/
