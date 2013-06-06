#include "markdown.h"
int open_file(char *name)
{
	int fd;
	fd = open(name, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	return fd;
}

int get_line(int fd, char *buf)
{
	int i = 0, ret;
	memset(buf, 0x00, LINE_MAX_LONG);
	do {
		ret  = read(fd, buf + i, 1);
		if (ret == 0 || ret < -1)
			return -1;
	} while (buf[i++] != '\n');
	return ret;
}

int decode(int fd_in, int fd_out)
{
	char buf[LINE_MAX_LONG] = {0};

	do {
		if (get_line(fd_in, buf) < 0)
			break;

		if (HEAD(buf)) {
			process_head(buf, fd_out);
			continue;
		} else if (PRE(buf))
			continue;
	} while (1);
}

int process_head(char *buf, int fd_out)
{
	if (HEAD_1(buf)) {
		write(fd_out, "<h1>", strlen("<h1>"));
		write(fd_out, buf + 2, strlen(buf) - 1 - 2);
		write(fd_out, "</h1>\n", strlen("</h1>\n"));
	}

}
