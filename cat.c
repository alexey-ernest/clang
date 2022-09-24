#include <stdio.h>

/* cat: concatenate files */
int main(int argc, char const *argv[])
{
	FILE *fp;
	void filecopy(FILE *, FILE *);

	if (argc == 1) {
		filecopy(stdin, stdout);
	} else {
		while (--argc > 0) {
			if ((fp = fopen(*++argv, "r")) != NULL) {
				filecopy(fp, stdout);
				fclose(fp);
			} else {
				fprintf(stdout, "error: could not open file %s\n", *argv);
			}
		}
	}

	return 0;
}

void filecopy(FILE *ifp, FILE *ofp) {
	int c;
	while ((c = getc(ifp)) != EOF) {
		putc(c, ofp);
	}
}
