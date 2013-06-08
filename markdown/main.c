#include "markdown.h"
#include "css.h"
char *tip = "<p align=right>Edit By<a href=\"mailto:sqm2050@gmail.com\"> sqm</a></p>";

int main(int argc, char *argv[])
{
	int fd_in, fd_out;
	if (argc != 3) {
		puts("the para is wrong!");
		return -1;
	}

	if ((fd_in = open_file(argv[1], 0)) < 0) {
		puts("open  dst file fail");
		return -1;
	}

	if ((fd_out = open_file(argv[2], 1)) < 0) {
		puts("open  dst file fail");
		return -1;
	}
	/* write css to the file */
	write(fd_out, "<html>", strlen("<html>"));
	write(fd_out, css, strlen(css));
	decode(fd_in, fd_out);
	write(fd_out, tip, strlen(tip));
	write(fd_out, "</html>", strlen("</html>"));
	close(fd_in);
	close(fd_out);
}
