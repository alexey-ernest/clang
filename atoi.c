#include <stdio.h>

#define MAX_INPUT 20

int atoi(char s[]);

int main(int argc, char const *argv[])
{
	int c, i;
	char input[MAX_INPUT+1];
	i = 0;

	while ((c = getchar()) != EOF && i < MAX_INPUT) {
		input[i++] = c;
	}
	input[i] = '\0';

	printf("%d\n", atoi(input));

	return 0;
}

/* atoi: convert s to integer, a naive implementation */
int atoi(char s[]) {
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
		n = 10 * n + (s[i] - '0');
	}

	return n;
}