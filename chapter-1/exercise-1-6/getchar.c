#include <stdio.h>

main() {
  int c;

  while ((c = getchar()) != EOF) {
    putchar(c);
    printf( "\n%d\n",c != EOF);
    c = getchar();
  }
}
