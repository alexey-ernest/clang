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

/* atoi: convert s to integer */
int atoi(char s[]) {
	int i, n, negative;

	n = 0;
	i = 0;
	negative = 0;

	if (s[i] == '-') {
		negative = 1;
		i = 1;
	}

	for (; s[i] >= '0' && s[i] <= '9'; ++i) {
		n = 10 * n + (s[i] - '0');
	}

	return negative ? -n : n;
}