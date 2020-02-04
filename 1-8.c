#include <stdio.h>

int main()
{
  int c, nl, ns, nt;

  nl = nt = ns = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n')
      ++nl;
    if (c == ' ')
      ++ns;
    if (c == '\t')
      ++nt;
  }
  printf("Lines: %d\nSpaces: %d\nTabs: %d\n", nl, ns, nt);
}
