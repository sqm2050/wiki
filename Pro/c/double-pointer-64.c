#include <stdio.h>
char a[] = {
	1,2,3,4,5,6,7,8,9
};

main()
{
	char **ptr = a;
	printf("%x\n", ptr[0]);
}
