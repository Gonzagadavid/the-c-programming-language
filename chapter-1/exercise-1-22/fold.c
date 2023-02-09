#include <stdio.h>

#define MAXLINE 1000 

char text[MAXLINE][MAXLINE];
int chr_line = 10;

/* 
Write a program to fold long input lines into two or more shorter lines after the last non-blank
character that occurs before the n-th column of input. Make sure your program does something
intellingent with very long lines, and if there are no blanks or tabs before the specified column
*/

int fold(char from[], int lim, int qty);


int main() {
  char c, i = 0;
  char inseted[MAXLINE];
  int qty;
  int nLines;
  extern char text[MAXLINE][MAXLINE];
  extern int chr_line;
  
  while ((c = getchar()) != EOF && i < MAXLINE)
  {
    inseted[i] = c;
    i++;
    qty = i;
  }

  nLines = fold(inseted, chr_line, qty);

  for(int j = 0; j < nLines; j++) {
    printf("%s\n", text[j]);
  }

  return 0;
}

int fold(char from[], int lim, int qty)
{
  int passed = 0;
  int n = 0;
  int nLines;
  extern char text[MAXLINE][MAXLINE];

  for(int i = 0; passed < qty; i++) {
    for(int j = 0; from[passed] != '\n' && n == 0; j++, passed++) {
       text[i][j] = from[passed];
      if(j >= lim) {
        n = 1;
      }
    }
    passed++;
    text[i][lim + 1] = '\0';
    nLines = i;
    n = 0;
  }


  return nLines;
}





