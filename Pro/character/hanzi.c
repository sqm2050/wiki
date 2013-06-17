#include <stdio.h>
main()
{
	char d[3] = {0};
	scanf("%s", d);
	printf("\nThe input is:%s\n", d);
	int i;
	for (i = 0; i < 3; i++) {
		printf("%#02hhx  ", d[i]);
	}
	puts("");
}
