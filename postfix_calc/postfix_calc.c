#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 	100
#define NUMBER	'0'

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator (postfix notation) */
int main(int argc, char const *argv[])
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
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
				if (op2 != 0.0) {
					push(pop() / op2);
				} else {
				 	printf("error: zero devisor\n");
				 	exit(1);
				}
				break;
			case '\n':
				printf("\t%.8g\n", pop()); // print result
				break;
			default:
				printf("error: unknown command %d\n", (int)type);
				break;
		}
	}

	return 0;
}


#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
	if (sp >= MAXVAL) {
		printf("push: error, stack is full, can't push %g\n", f);
		exit(1);
	}

	val[sp++] = f;
}

double pop(void) {
	if (sp == 0) {
		printf("pop: error, stack is empty\n");
		exit(1);
	}

	return val[--sp];
}

int getch(void);	// read a character
void ungetch(int);	// put a char in a temp buffer to read it again

int getop(char s[]) {
	int i, c;

	// skip spaces
	while ((c = getch()) == ' ' || c == '\t')
		;

	// read a float number
	for (i = 0; isdigit(c) || c == '.'; ++i, c = getch()) {
		s[i] = c;
	}

	if (i > 0) {
		if (c != EOF) {
			// unread the last symbol
			ungetch(c);
		}

		s[i] = '\0';
		return NUMBER;
	}

	s[0] = c;
	s[1] = '\0';
	return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if (bufp >= BUFSIZE) {
		printf("ungetch: stack overflow\n");
		exit(1);
	}

	buf[bufp++] = c;
}
