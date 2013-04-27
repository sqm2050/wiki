#include <stdio.h>
#include <unistd.h>

int main()
{
int i=0;
for(i=0;i<100;i++)
{
	printf("sdfasdper: %d \r",i);
	fflush(stdout);
	sleep(1);
}
}
