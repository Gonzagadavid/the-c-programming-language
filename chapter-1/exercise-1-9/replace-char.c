#include <stdio.h>

// replace each string of one or more blanks by a single blank.

int main() {
  int c, lastC;

  while ((c = getchar()) != EOF) {
    if(lastC == ' ' && c == ' ') {
      continue;
    }
    lastC = c;
    putchar(c); 
  }

  return 0;
}
