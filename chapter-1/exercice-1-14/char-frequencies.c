/*
write a program to print a histogram of the frequencies of 
diferent characters in its input
*/

#include <stdio.h>
# define ASCII_START 33
# define ASCII_END 126

/* print histogram of the frequencies of characters */


main() {
  int c, i;
  int characters[ASCII_END - ASCII_START];

  for (i = 0; i < ASCII_END - ASCII_START; ++i) {
    characters[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    ++characters[c - ASCII_START];
  }

  for (i = 0; i < ASCII_END - ASCII_START; ++i) {
    if (characters[i] > 0) {
      printf("%c: ", ASCII_START + i);
      printf("%d\n",characters[i]);
    }
  }
}