#include <stdio.h>
#include <ctype.h>
#include "calc.h"

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