#define NAME_MAX 14

typedef struct {		/* portable directory entry */
	long ino;				/* inode number */
	char name[NAME_MAX+1];  /* name + \0 */
} Dirent;

typedef struct {		/* minimal DIRD: no buffering, etc */
	int fd;					/* file descriptor for directory */
	Dirent d;				/* the directory entry */
} DIRD;

DIRD *opend(char *dirname);
Dirent *readd(DIRD *dfd);
void closed(DIRD *dfd);