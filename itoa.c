#include <stdio.h>
#include <assert.h>
#include <string.h>

#define MAXLEN 100

void itoa(int n, char s[]);
void reverse(char s[]);

int main(int argc, char const *argv[])
{
	char s[MAXLEN];
	
	itoa(12647, s);
	assert(strcmp(s, "12647") == 0);

	itoa(-5768492, s);
	assert(strcmp(s, "-5768492") == 0);

	itoa(0, s);
	assert(strcmp(s, "0") == 0);

	itoa(1843273840, s);
	assert(strcmp(s, "1843273840") == 0);

	return 0;
}

/* itoa: convert an integer to characters in s */
void itoa(int n, char s[]) {
	int i, sign;
	
	i = 0;
	sign = n;
	if (n < 0) {
		n = -n;
	}

	do {
		s[i++] = n%10 + '0';
		n = n/10;
	} while (n > 0);

	if (sign < 0) {
		s[i++] = '-';
	}

	s[i] = '\0';
	reverse(s);
}

/* reverse: reverse characters in a character array */
void reverse(char s[]) {
	int i, j, n;
	char temp;
	for (n = 0; s[n] != '\0'; ++n)
		;
	for (i = 0, j = n - 1; i < j; ++i, --j) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}