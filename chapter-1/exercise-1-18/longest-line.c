#include <stdio.h>
#define MAXLINE 1000 

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* 
write a program to remove trailing blanks and tabs from each line of input,
and to delete entirel blanks lines
*/

int main() {
  int len; 
  int count;
  int i;
  char line[MAXLINE];
  char longer_lines[MAXLINE][MAXLINE];

  count = 0;
  while ((len = get_line(line, MAXLINE)) > 0) {
    if(line[0] != '\n') {
      copy(longer_lines[count], line);
      count++;
    }
  } 

  if (count > 0) { 
    for (i = 0; i < count; i++) {
      printf("%s", longer_lines[i]);
    }
  }
  return 0;
}


int get_line(char s[], int lim) {
  int c, i, n;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    if(c == '\t') {
      i--;
    } else {
      s[i] = c;
    }
  }

  while (s[i-1] == 32) {
    i--;
  }
   
  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}

void copy(char to[], char from[]) {
  int i;
  i = 0;
  while((to[i] = from[i]) != '\0') {
    ++i;
  }
}