#include <stdio.h>

// replace tab by \t, each backspace by \b,  and each blackslash by \\.

void main() {
  int c;

  while ((c = getchar()) != EOF) {
    if(c == '\t') {
      putchar('\\');
      putchar('t');
      continue;
    }
    if(c == '\b') {
      putchar('\\');
      putchar('b');
      continue;
    }
    if(c == '\\') {
      putchar('\\');
      putchar('\\');
      continue;
    }
    putchar(c); 
  }
}
