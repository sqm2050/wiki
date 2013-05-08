#include "apue.h"
int main(int argc, char *argv[])
{
	int status;

	if (argc < 2) {
		puts("para error");
		exit(0);
	}

	if ((status = system(argv[1])) < 0)
		puts("system exec error");

	exit(0);
}
