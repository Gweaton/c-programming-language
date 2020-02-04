#include <stdio.h>

#define MAX_INPUT_LENGTH 50

int escape(char input[], char output[]);

int main() {
  char input[MAX_INPUT_LENGTH];;
  char output[MAX_INPUT_LENGHTH];
  escape(input, output);
}

int escape(char input[], char output[]) {
  for (int i = 0; i < MAX_INPUT_LENGTH; i++) {
    switch (input[i]) {
      case '\t':
        printf("\\t");
        break;
      case '\n':
        printf("\\n");
        break;
      case '\\':
        switch(input[++i]) {
          case 't':
            printf("%c", '\t');
            break;
          case 'n':
            printf("%c", '\n');
            break;
        }
        break;
      default:
        printf("%c", input[i]);
    }
  }
  return 0;
}

int mgetline(char s[])
{
      int i,c;

          for(i=0;i<MAX_INPUT_LENGTH - 1 && (c=getchar())!=EOF;++i)
                    s[i]=c;

              s[i]='\0';
}
