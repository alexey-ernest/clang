#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 9973

struct hentry {
	char *name;
	char *defn;
};

static struct hentry *hashtab[HASHSIZE];

unsigned hash(char *);
char *lookup(char *);
char *install(char *, char *);
char *undef(char *);

int main(int argc, char const *argv[])
{
	assert(hash("abc") > 0 && hash("def") < HASHSIZE);
	assert(install("aaa", "bbb") != NULL);
	assert(lookup("bbb") == NULL);
	assert(lookup("aaa") != NULL);
	assert(strcmp(lookup("aaa"), "bbb") == 0);
	assert(install("aaa", "ccc") != NULL);
	assert(strcmp(lookup("aaa"), "ccc") == 0);

	assert(undef("aaa") != NULL);
	assert(lookup("aaa") == NULL);
	assert(install("aaa", "ddd") != NULL);
	assert(strcmp(lookup("aaa"), "ddd") == 0);

	assert(undef("bbb") == NULL);

	return 0;
}

unsigned hash(char *s) {
	unsigned hashval;
	for (hashval = 0; *s; s++) {
		hashval = hashval * 256 + *s;
	}

	return hashval % HASHSIZE;
}

char *lookup(char *s) {
	int i;
	unsigned hashval = hash(s);

	for (i = hashval; i < HASHSIZE + hashval && hashtab[i % HASHSIZE] != NULL; ++i) {
		if (strcmp(hashtab[i % HASHSIZE]->name, s) == 0) {
			return hashtab[i % HASHSIZE]->defn;
		}
	}

	return NULL;
}

char *install(char *name, char *defn) {
	int i;
	unsigned hashval = hash(name);
	char *strd(char *);

	for (i = hashval; i < HASHSIZE + hashval && hashtab[i % HASHSIZE] != NULL; ++i) {
		if (strcmp(hashtab[i % HASHSIZE]->name, name) == 0) {
			break;
		}
	}
	
	i = i % HASHSIZE;
	if (hashtab[i] == NULL) {
		hashtab[i] = (struct hentry*)malloc(sizeof(hashtab[i]));
		if (hashtab[i] == NULL || (hashtab[i]->name = strd(name)) == NULL || (hashtab[i]->defn = strd(defn)) == NULL) {
			return NULL;
		}
	} else {
		free(hashtab[i]->defn);
		if ((hashtab[i]->defn = strd(defn)) == NULL) {
			return NULL;
		}
	}
	
	return hashtab[i]->defn;
}

char *undef(char *s) {
	int i, j;
	unsigned hashval = hash(s);
	char *dp;

	for (i = hashval; i < HASHSIZE + hashval && hashtab[i % HASHSIZE] != NULL; ++i) {
		if (strcmp(hashtab[i % HASHSIZE]->name, s) == 0) {
			dp = hashtab[i % HASHSIZE]->defn;
			for (j = i; j < HASHSIZE + i && hashtab[j % HASHSIZE] != NULL; ++j) {
				hashtab[j % HASHSIZE] = hashtab[(j + 1) % HASHSIZE];
			}

			return dp;
		}
	}

	return NULL;
}

char *strd(char *s) {
	char *p = (char *)malloc(strlen(s) + 1);
	if (p != NULL) {
		strcpy(p, s);
	}
	return p;
}
