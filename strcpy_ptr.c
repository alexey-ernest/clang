#include <assert.h>

void strcpy_ptr(char *s, char *t);

int main(int argc, char const *argv[])
{
	char s1[] = "abcd";
	char s2[] = "defghi";

	strcpy_ptr(s1, s2);
	assert(s2[0] == 'a');
	assert(s2[1] == 'b');
	assert(s2[2] == 'c');
	assert(s2[3] == 'd');
	assert(s2[4] == '\0');

	return 0;
}

void strcpy_ptr(char *s, char *t) {
	while ((*t++ = *s++))
		;
}