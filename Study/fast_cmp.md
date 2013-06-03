## 小端下快速比较一个4位的字符串
```
#include <stdio.h>
int g = ' ' << 24 \
	| ('T' << 16) \
	| ('E' << 8) \
	| ('G' << 0);

main()
{ 
	char a[4] = "GET ";
	if (g == *(int *)a) {
		printf("yes\n");
	}
	printf("%#x\n", *(int *)a);
	printf("%#x\n", g);
}
```

比较慢:
```
char g[] = "GET ";

```
