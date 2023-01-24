#include <stdio.h>

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    putchar(c);
    printf( "\n%d\n",c != EOF);
    c = getchar();
  }

  return 0;
}
