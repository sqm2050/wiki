#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/* # --- #### */
#define HEAD(r) (r[0] =='#')
#define HEAD_1(r) (r[0] =='#' && r[1] == ' ')
#define HEAD_2(r) (r[0] =='#' && r[2] == ' ')
#define HEAD_3(r) (r[0] =='#' && r[2] == ' ')
#define HEAD_4(r) (r[3] =='#' && r[1] == ' ')

/* ``` */
#define PRE(r) (r[0] == '`' && r[1] == '`' && r[2] == '`')

/* normal p */
#define PPP(r) (r[0] != '`' && r[0] != '#' && r[0] != '>' && r[0] != '-')

#define LINE_MAX_LONG	1024

int open_file(char *);
int get_line(int fd, char *);
int decode(int, int);
int process_head(char *buf, int fd_out);
