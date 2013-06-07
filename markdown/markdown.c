#include "markdown.h"
int open_file(char *name, int trunck)
{
	int fd;
	if (!trunck) {
		fd = open(name, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	} else
		fd = open(name, O_RDWR | O_CREAT |O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
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

	while (get_line(fd_in, buf) > 0) {
		if (HEAD(buf)) {
			process_head(buf, fd_out);
		} else if (PRE(buf)) {
			process_pre(buf, fd_in, fd_out);
		} else if (TIT_1(buf)) {
			process_tit(buf, fd_in, fd_out);
		} else {
			write(fd_out, "<p>", strlen("<p>"));
			write(fd_out, buf, strlen(buf));
			write(fd_out, "</p>", strlen("</p>"));
		}

	}
}

int process_head(char *buf, int fd_out)
{
	if (HEAD_1(buf)) {
		write(fd_out, "<h1>", strlen("<h1>"));
		write(fd_out, buf + 2, strlen(buf) - 1 - 2);
		write(fd_out, "</h1>\n", strlen("</h1>\n"));
	} else if (HEAD_2(buf)) {
		write(fd_out, "<h2>", strlen("<h2>"));
		write(fd_out, buf + 3, strlen(buf) - 1 - 3);
		write(fd_out, "</h2>\n", strlen("</h2>\n"));

	} else if (HEAD_3(buf)) {
		write(fd_out, "<h3>", strlen("<h3>"));
		write(fd_out, buf + 4, strlen(buf) - 1 - 4);
		write(fd_out, "</h3>\n", strlen("</h3>\n"));
	} else if (HEAD_4(buf)) {
		write(fd_out, "<h4>", strlen("<h4>"));
		write(fd_out, buf + 5, strlen(buf) - 1 - 5);
		write(fd_out, "</h4>\n", strlen("</h4>\n"));
	}
}

int process_pre(char *buf, int in, int out)
{
	write(out, "<pre><p>", strlen("<pre><p>"));
again:
	if (get_line(in, buf) > 0){
		if (!PRE(buf)) {
			write(out, buf, strlen(buf));
			goto again;
		} else {
			write(out, "</pre></p>", strlen("</pre></p>"));
			return 0;
		}
	}
}

void process_tit(char *buf, int in, int out)
{
	char tmp[LINE_MAX_LONG] = {0};
	strcpy(tmp, buf);
	int lv, lv1;
	for (lv = 0; buf[lv] == '\t'; lv++);lv++;

	write(out, "<ul>\n<li>", strlen("<ul>\n<li>"));
	write(out, buf + lv + 1, strlen(buf) - lv -1);
	write(out, "</li>\n", strlen("</li>\n"));
	while (get_line(in, buf) > 0) {
		if (TIT_1(buf) || TIT_2(buf) || TIT_3(buf)) {
			for (lv1 = 0; buf[lv1] == '\t'; lv1++);lv1++;
			if (lv1 == lv) {
				write(out, "<li>\n", strlen("<li>\n"));
				write(out, buf + lv1 + 1, strlen(buf) - lv1 -1);
				write(out, "</li>\n", strlen("</li>\n"));
				continue;
			} else {
				process_tit(buf, in, out);
				write(out, "</ul>\n", strlen("</ul>\n"));
				return;
			}
		}

		if (PRE(buf)) {
			process_pre(buf, in, out);
			write(out, "</ul>\n", strlen("</ul>\n"));
			return;
		}
		printf("--------\n");
		write(out, buf, strlen(buf));
		write(out, "</ul>\n", strlen("</ul>\n"));
		return;
	}
	return;
}
