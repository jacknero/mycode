#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int c, d;
  int n = 1;

  c = getchar();

  while (c != EOF) {
    d = getchar();

    if (c == d)
      n++;
    else {
      if (n != 1)
        putchar(n | 0x80);
      putchar(c);
      n = 1;
    }

    c = d;
  }

  return EXIT_SUCCESS;
}


