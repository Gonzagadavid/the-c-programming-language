#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[], int size);

/* 
write a function reverse(s) that reverses the character string s. Use it to write a
program that reverses its input a line at a time
*/

int main() {
  int len;
  int count;
  int i;
  char line[MAXLINE];
  char longer_lines[MAXLINE][MAXLINE];

  count = 0;
  while ((len = get_line(line, MAXLINE)) > 0) {
      copy(longer_lines[count], line, len);
      printf("%s", longer_lines[i]);
    }

  return 0;
}

int get_line(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[], int size) {
  int i, j = 0;
 
  for (i = size - 2; i >= 0; --i) {
    to[j] = from[i];
    j++;
  }
  
  to[j] = '\n';
  to[j + 1] = '\0';
  
}