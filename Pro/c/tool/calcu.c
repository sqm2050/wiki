#include <stdio.h>
#include <string.h>
static inline int atoh(char *str, int len)
{
	int i, result = 0, tmp = 0;
	for (i = 0; i < len; i++) {
		if(str[i] >= '0' && str[i]<='9')
			tmp = str[i] - '0';
		else if(str[i] >= 'a' && str[i]<= 'f')
			tmp = str[i] -'a' + 10;
		else if(str[i] >= 'A' && str[i] <= 'F')
			tmp = str[i] -'A' + 10;  
		else
			return -1;

		result = result << 4 | tmp;
	}
	return result;
}

static inline void prt_bit(long a)
{
	int i;
	for (i = 0; i < 64; i++) {
		printf("%ld", a >> (64 - 1 -i) & 0x01);

		if ((i + 1) % 4 == 0)
			printf(" ");
	}
	printf("\n");
}

static inline long btoi(char *str, int len)
{
	int i;
	long tmp = 0;
	for (i = 0; i < len; i++) {
		if (str[i] == '1')
			tmp |= 1 << len - 1 -i;
	}
	return tmp;
}

static inline void dump(long d)
{
	printf("B: "); prt_bit(d);
	printf("D: %ld\n", d);
	printf("H: %#lx\n", d);
}
int main(int argc, char *argv[])
{
	long tmp = 0;
	if (argc != 2)
		return 0;
	if (argv[1][0] == '0' && argv[1][1] == 'x') {
		tmp = atoh(&argv[1][2], strlen(argv[1]) - 2);
		dump(tmp);
		return 0;
	};
	if (argv[1][0] == '0' && argv[1][1] != 'x') {
		tmp = btoi(&argv[1][1], strlen(argv[1]) - 1);
		dump(tmp);
		return 0;
	};
	tmp = atoi(argv[1]);
	dump(tmp);
	return 0;
}
