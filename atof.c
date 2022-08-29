#include <stdio.h>

#define MAXLEN 32

double atof(char s[]);

int main(int argc, char const *argv[])
{
	char s[MAXLEN];
	int i, c;
	while((c = getchar()) != EOF && c != '\n') {
		s[i++] = c;
	}

	printf("%.10f\n", atof(s));

	return 0;
}

/* atof: convert a character string s to double */
double atof(char s[]) {
	double val, pow;
	int i, sign;

	// skip spaces
	for (i = 0; s[i] == ' ' || s[i] == '\t' || s[i] == '\n'; ++i)
		;

	sign = 1;
	if (s[i] == '-') {
		sign = -1;
		++i;
	}

	for (val = 0.0; s[i] >= '0' && s[i] <= '9'; ++i) {
		val = val * 10.0 + (s[i] - '0');
	}

	if (s[i] == '.') {
		++i;
	}
	
	for (pow = 1.0; s[i] >= '0' && s[i] <= '9'; ++i) {
		val = val * 10.0 + (s[i] - '0');
		pow *= 10.0;
	}

	return sign * val / pow;
}