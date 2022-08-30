#define NUMBER	'0'

int getop(char []);
void push(double);
double pop(void);
int getch(void);	// read a character
void ungetch(int);	// put a char in a temp buffer to read it again