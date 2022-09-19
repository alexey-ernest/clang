#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct key {
	char *word;
	int count;
};

struct key keytab[] = {
	"auto", 0,
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"default", 0,

	"double", 0,

	"else", 0,

	"float", 0,

	"if", 0,

	"int", 0,

	"long", 0,

	"return", 0,

	"struct", 0,

	"switch", 0,

	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0
};

#define NKEYS (sizeof keytab / sizeof keytab[0]) // keytab length

int getword(char *, int);
int binsearch(char *, struct key[], int);

int main(int argc, char const *argv[])
{
	int n;

	char word[MAXWORD];
	while (getword(word, MAXWORD) != EOF) {
		if (isalpha(word[0])) {
			if ((n = binsearch(word, keytab, NKEYS)) >= 0) {
				keytab[n].count++;
			}
		}
	}

	for (n = 0; n < NKEYS; ++n) {
		if (keytab[n].count > 0) {
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
		}
	}

	return 0;
}

int getword(char *s, int max) {
	int c;
	char *p;
	while ((c = getchar()) != EOF && isspace(c))
		;

	for (p = s; c != EOF && !isspace(c) && c != '\n' && (p - s) < max - 1; c = getchar()) {
		*p++ = c;
	}
	*p = '\0';

	return c;
}

int binsearch(char *word, struct key tab[], int n) {
	int l = 0, r = n - 1;
	int mid;

	while (l < r) {
		mid = (l + r) / 2;
		if (strcmp(word, tab[mid].word) > 0) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}

	if (strcmp(word, tab[l].word) != 0) {
		return -1;
	}

	return l;
}

