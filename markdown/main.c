#include "markdown.h"

int main(int argc, char *argv[])
{
	int fd;
	if (argc != 3)
		return -1;

	if ((fd = open(argv[2], O_RDWR | O_CREAT)) == NULL) {
		puts("open  dst file fail");
		return -1;
	}
}
