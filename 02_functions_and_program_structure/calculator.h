#if !defined(NUMBER)
#define NUMBER '0'	// signal that a number was found
#endif

int calculator();
int getch();
void ungetch(int c);
int getop(char s[]);
void push(double f);
double pop(void);
