#include "apue.h"
#include <sys/stat.h>
int main(void)
{
	struct stat statbuf;

	/* turn on set-group-ID and turn off group-execute */
	if (stat("foo", &statbuf) < 0)
		printf("stat error for foo\n");

	if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
		printf("chmod error for foo\n");

	/* set absolute mode to "rw-r--r--" */
	if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
		printf("chmod error for bar\n");

	exit(0);
}
