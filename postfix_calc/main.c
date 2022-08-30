#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 	100

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
