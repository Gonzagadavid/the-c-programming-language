#include <stdio.h>

/* count blank, tabs and new line in input; */

main() {
  int chr, blk, tab, nl; 

  blk = 0;
  tab = 0;
  nl = 0;
  
  while ((chr  = getchar()) != EOF) {
    if(chr == ' ')
      ++blk;

    if(chr == '\t')
      ++tab;
      
    if(chr == '\n')
      ++nl;
  }
  printf("blank: %d\n", blk);
  printf("tabs: %d\n", tab);
  printf("new line: %d\n", nl);
}