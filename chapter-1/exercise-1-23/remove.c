#include <stdio.h>

#define MAXLINE 1000 

char program[MAXLINE][MAXLINE];

/* 
Write a program to remove all comments from a C program.
Don't forget to handle quoted string and character constants properly.
 C comments not nest
*/

int remove_comments(char from[], int lim, int count);


int main() 
{
  char c, i = 0, j = 0;
  char inseted[MAXLINE][MAXLINE];
  int qty;
  int nLines = 0;
  extern char program[MAXLINE][MAXLINE];
  int chr_line = 0;
  int comment_multi_lines = 0;
  
  while ((c = getchar()) != EOF && i < MAXLINE)
  {
    inseted[i][j] = c;
    j++;
    qty = i;
    if(j > chr_line) {
      chr_line = j;
    }
    if(c == '\n') {
      inseted[i][j] = '\0';
      i++;
      j = 0;
    }
  }

  
  for(int k = 0; k <= qty; k++ ){
    if(inseted[k][0] == '/' && inseted[k][0] != '*') {
      comment_multi_lines = 1;
    }

    if(inseted[k][0] != '/' && comment_multi_lines != 1) {
      remove_comments(inseted[k], chr_line, nLines);
      nLines++;
    }

    if(comment_multi_lines == 1) {
      for(int j = 0; j <= MAXLINE && inseted[k][j] != '\0'; j++) {
        if(inseted[k][j] == '*' && inseted[k][j + 1] == '/') {
          comment_multi_lines = 0;
          break;
        }
      }
    }
  }

  for(int n = 0; n <= nLines; n++) {
    printf("%s", program[n]);
  }

  return 0;
}

int remove_comments(char from[], int lim, int count)
{
  extern char program[MAXLINE][MAXLINE];


  for(int i = 0; i <= lim; i++) {
    program[count][i] = from[i];
  }

   return 0;
  
}





