/*
write a program to print a histogram of the word lengths in your input. 
It's easy to draw the histogram with the horizontal bars; 
a vertical orientation is more challenging
*/

#include <stdio.h>

/* print histogram of the lengths of words */

main() {
  int c, count, wordqty, i;
  int lengthofwords[wordqty];

  count = wordqty = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      lengthofwords[wordqty] = count ;
      ++wordqty;
      count = 0;
    } else {
      ++count;
    }
  }

  printf("length of word:\n");
  for (i = 0; i < wordqty; ++i)
    printf(" %d\n", lengthofwords[i]);
}