#include <stdio.h>
#include <stdlib.h>

#define MAXVAL 100

static int sp = 0;			// make it hidden from global
static double val[MAXVAL];	// make it hidden from global

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