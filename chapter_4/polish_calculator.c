#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100 //max size of operand/operator
#define NUMBER '0' //signal that number was found
#define MAXVAL 100 //maximum depth of val stack
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);

void peek(void);
void swap(void);
void clear(void);
void duplicate(void);

void sine(void);
void cosine(void);
void power(void);

int main()
{
  int type, noprint;
  double op2;
  char s[MAXOP];

  noprint = 0;

  while ((type = getop(s)) != EOF)
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '*':
        push(pop() * pop());
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
      case '%':
        op2 = pop();
        if (op2 != 0.0)
          push((int) pop() %(int) op2);
        else
          printf("error: zero divisor\n");
        break;
      case 'a':

        break;
      case 'p':
        noprint = 1;
        peek();
        break;
      case 's':
        swap();
        break;
      case 'd':
        duplicate();
        break;
      case 'c':
        clear();
        break;
      case 'z':
        sine();
        break;
      case 'x':
        cosine();
        break;
      case '^':
        power();
        break;
      case '\n':
        if (noprint == 0)
          printf("\t%.8g\n", pop());
        noprint = 0;
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  return 0;
}

int sp = 0; // next free stack position
double val[MAXVAL]; // value stack

void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("pop error: stack empty\n");
    return 0.0;
  }
}

int getch(void);
void ungetch(int);

// get next operator or numeric operand
int getop(char s[])
{
  int i, c, sign;
  static char buffer[BUFSIZE];
  // skip leading whitespace
  // copy every character to s[0], regardless of whether it is used or not
  // if not white/tab character, store digit s[0]
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  //need to terminate string after 1 char
  // if there is something to be read, it will get overwritten on \0
  s[1] = '\0';
  //s[](and c) == single char that is neither space or \t

  if (!isdigit(c) && c != '.' && c != '-')
    return c; // not a number

  i = 0;

  if (isdigit(c))
    // get nums before a decimal point
    //s[0] is c, so get next numbers to build string
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')
    // get nums after a decimal point
    while (isdigit(s[++i] = c= getch()))
      ;

  if (c == '-')
    // negative numbers
    while (isdigit(s[++i] = c = getch()))
      ;
  // end string now we have all nums
  s[i] = '\0';

  if (c != EOF)
    //add all things to buffer
    buffer[i] = c;

  return NUMBER;
}


char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0; // next free position in buffer

// delivers the next input character to be considered
int getch(void) // get a (possibly pushed back) character
{
  // is there anything in the buffer?
  // if so, return it, and move bufp position one to the left.
  // if not, get a new character from the input
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) //push character back on input
{
  // more than 100 things in buffer?
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    // add something to the buffer
    buf[bufp++] = c;
}

void ungets(char s[])//push entire string back on input
{
  for (int i = 0; s[i] != '\0'; i++) {
    ungetch(s[i]);
  }
}

void peek(void) // show top element of stack without popping
{
  printf("Top element of stack: %f\n", val[sp]);
}

void swap(void) // swap top 2 elements on stack
{
  if (sp > 1) {
    double a = pop();
    double b = pop();
    push(b);
    push(a);
  } else {
    printf("error: only one element on stack\n");
  }
}

void duplicate(void)
{
  double top = pop();
  push(top);
  push(top);
}

void clear(void) //clear stack
{
  sp = 0;
}

void sine(void)
{
  push(sin(pop()));
}

void cosine(void)
{
  push(cos(pop()));
}

void power(void)
{
  double op2 = pop();
  push(pow(pop(), op2));
}
