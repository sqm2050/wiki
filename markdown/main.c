#include "markdown.h"

int main(int argc, char *argv[])
{
	int fd_in, fd_out;
	if (argc != 3) {
		puts("the para is wrong!");
		return -1;
	}

	if ((fd_in = open_file(argv[1])) < 0) {
		puts("open  dst file fail");
		return -1;
	}

	if ((fd_out = open_file(argv[2])) < 0) {
		puts("open  dst file fail");
		return -1;
	}

	if (decode(fd_in, fd_out) == 0) {
		printf("change sucess\n");
		return 0;
	} else {
		printf("change sucess\n");
		return -1;
	}
}
