# include <stdio.h>

# define IN 1 /* inside a word*/
# define OUT 0 /* outside a word*/

// /* print one word per line */

void main() {
  int c;


  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      putchar('\n');
   } else {
      putchar(c);
   } 
  }
}
