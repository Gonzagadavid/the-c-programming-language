

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int tabs_numbers = 8;

int get_line(char line[], int maxline);
void copy(char to[], char from[]);
int entab(char line[], int index);
/* 
Write a program entab that replaces strings of blanks by the minimum bymber of tabs and blanks 
to achieve the same spacing. Use the same tab stopsas for detab. when either a tab or a single 
blank would suffice to reach a tab stop, which should be given preference?
*/

int main() {
  int len;  /* current line length*/
  int count;
  int i;
  char line[MAXLINE]; /* current input line */
  char longer_lines[MAXLINE][MAXLINE];

  count = 0;
  while ((len = get_line(line, MAXLINE)) > 0) {
      copy(longer_lines[count], line);
      count++;
  } 

  if (count > 0) { /* there was a line */
    for (i = 0; i < count; i++) {
      printf("%s", longer_lines[i]);
    }
  }
  return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    if(c == ' ') {
      i = entab(s, i);
    } else {
      s[i] = c;
    }
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

/* copy: copy 'from* into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
  int i;
  i = 0;
  while((to[i] = from[i]) != '\0') {
    ++i;
  }
}


int entab(char line[], int index) {
  int i;
  extern int tabs_numbers;

  for (i = index; i <= (index + tabs_numbers); ++i) {
    line[i] = ' ';
  }

  return i; 
}