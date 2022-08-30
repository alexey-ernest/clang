#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100

static char buf[BUFSIZE];	// make it hidden from global
static int bufp = 0;		// make it hidden from global

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