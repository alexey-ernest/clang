#include <stdio.h>

#define BUF_LEN 100
#define IN 		1
#define OUT 	0

/* remove comments from C code; single line and
   multiline */
int main(int argc, char const *argv[])
{
	int i, c, pc;
	char buf[BUF_LEN+1];
	int comment = OUT;
	int multicomment = OUT;

	i = 0;
	buf[BUF_LEN] = '\0';

	while ((c = getchar()) != EOF) {
		if (c == '/' && pc == '/') {
			// comment started
			comment = IN;
			--i;
		} else if (c == '\n' && comment == IN) {
			// comment ended
			comment = OUT;
		} else if (c == '*' && pc == '/') {
			// multi line comment started
			multicomment = IN;
			--i;
		} else if (c == '/' && pc == '*' && multicomment == IN) {
			multicomment = OUT;
			continue;
		}

		if (i >= BUF_LEN) { // flush the buf
			printf("%s", buf);
			i = 0;
		}

		if (comment == OUT && multicomment == OUT) {
			buf[i] = c;
			++i;
		}
		pc = c;
	}

	// flush the buf
	buf[i] = '\0';
	if (i > 0) {
		printf("%s\n", buf);	
	}

	return 0;
}