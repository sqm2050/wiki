转换字符到十六进制：
```
#include <stdio.h>
static inline int atoh(char *str, int len)
{
	int i, result = 0, tmp;
	for (i = 0; i < len; i++) {
		if(str[i] >= '0' && str[i]<='9')
			tmp = str[i] - '0';
		else if(str[i] >= 'a' && str[i]<= 'f')
			tmp = str[i] -'a' + 10;
		else if(str[i] >= 'A' && str[i] <= 'F')
			tmp = str[i] -'A' + 10;  

		result = result << 4 | tmp;
	}
	return result;
}

main()
{
	char a[] = "CD";
	int b = atoh(a, 2);
	printf("%#x\n", b);
}
```
