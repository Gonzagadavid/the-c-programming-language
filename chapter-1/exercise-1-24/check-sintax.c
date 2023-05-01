#include <stdio.h>

/* 
Write a program to check a C program for rudimentary syntax errors like unbalanced parentheses,
brackets and braces. Don't forget about quotes, both single and double, escape sequences and 
comments. (this program is hard if you it in full generality)
*/

#define MAXLINE 1000 
char program[MAXLINE][MAXLINE];
int comment_multi_lines = 0;
int parentheses_open = 0;
int parentheses_close = 0;
int brackets_open = 0;
int brackets_close = 0;
int braces_open = 0;
int braces_close = 0;
int single_quotes = 0;
int double_quotes = 0;
int open_comments = 0;
int close_comments = 0;


int count_char(char c, int i, int j);
int quote_message(char quote);
int char_message(int open_char, int close_char, char char_open_used, char char_close_used);
int check_sintax();

int main() 
{
  char c, i = 0, j = 0;
  int qty;
  extern char program[MAXLINE][MAXLINE];

  while ((c = getchar()) != EOF && i < MAXLINE)
  {
    program[i][j] = c;
    j++;
    qty = i;

    count_char(c, i, j);

    if(c == '\n') {
      program[i][j] = '\0';
      i++;
      j = 0;
    }

  }

  check_sintax();

  return 0;
}

int count_char(char c, int i, int j) {
  extern char program[MAXLINE][MAXLINE];
  extern int comment_multi_lines;
  extern int parentheses_open;
  extern int parentheses_close;
  extern int brackets_open;
  extern int brackets_close;
  extern int braces_open;
  extern int braces_close;
  extern int single_quotes;
  extern int double_quotes;
  extern int open_comments;
  extern int close_comments;

  if(c == '(') parentheses_open++;
  if(c == ')') parentheses_close++;
  if(c == '[') brackets_open++;
  if(c == ']') brackets_close++;
  if(c == '{') braces_open++;
  if(c == '}') braces_close++;
  if(c == 39) single_quotes++;
  if(c == 34) double_quotes++;
  if(c == '/' && program[i][j - 1] == '*') open_comments++;
  if(c == '*' && program[i][j - 1] == '/') close_comments++;


  return 0;
}


int check_sintax() {

  extern int comment_multi_lines;   
  extern int parentheses_open;
  extern int parentheses_close;
  extern int brackets_open;
  extern int brackets_close;
  extern int braces_open;
  extern int braces_close;
  extern int open_comments;
  extern int close_comments;
  extern int single_quotes;
  extern int double_quotes;

 if(parentheses_open != parentheses_close) 
    char_message(parentheses_open, parentheses_close, '(', ')');
  if(brackets_open != brackets_close) 
    char_message(brackets_open, brackets_close, '[', ']');
  if(braces_open != braces_close) 
    char_message(braces_open, braces_close, '{', '}');
  if(open_comments != close_comments) 
    printf("Sintax Error: comments");
  if(single_quotes % 2 != 0 ) quote_message(39);
  if(double_quotes % 2 != 0 ) quote_message(34);

  return 0;
}


int char_message(int open_char, int close_char, char char_open_used, char char_close_used) {

  if(open_char > close_char) {
    printf("Sintax Error: missing %c\n", char_close_used);
  } else {
    printf("Sintax Error: missing %c\n", char_open_used);
  }

  return 0;
}

int quote_message(char quote) {
    printf("Sintax Error: missing %c\n", quote);
}

