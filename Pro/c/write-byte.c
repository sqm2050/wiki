#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define	name1 "in"
#define	name2 "out"

char data[] = {
	0x78,0x9c,0xff,0x66,0x34
};
main()
{
	int fd;
	fd = open(name2, O_RDWR | O_CREAT |O_TRUNC, S_IRUSR |
			S_IWUSR | S_IRGRP | S_IROTH);

	write(fd, data, sizeof(data));
}
