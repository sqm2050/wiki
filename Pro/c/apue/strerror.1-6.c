#include "apue.h"
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
	fprintf(stderr, "EACCES: %s\n", strerror(2));

	errno = ENOENT;

	perror(argv[0]);
	exit(0);
}
