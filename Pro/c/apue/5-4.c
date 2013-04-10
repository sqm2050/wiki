#include "apue.h"
int main(void)
{
	char name[L_tmpnam], line[MAXLINE];
	FILE *fp;

/*
	printf("%s\n", tmpnam(NULL));

	tmpnam(name);
	printf("%s\n", name);
*/

	if ((fp = tmpfile()) == NULL)
		printf("tmpfile error\n");

	fputs("one line of output\n", fp);

	rewind(fp);

	if (fgets(line, sizeof(line), fp) == NULL)
		printf("fgets error\n");

	fputs(line, stdout);
	exit(0);
}
