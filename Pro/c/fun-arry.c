#include <stdio.h>
int fun_1(int i, int j)
{

	printf("fun_1\n");
	printf("para  %d\n", i);
	return i + j;
}

int fun_2(int i, int j)
{

	printf("fun_2\n");
	printf("para  %d\n", i);
	return i + j;
}

int fun_3(int i, int j)
{

	printf("fun_3\n");
	printf("para  %d\n", i);
	return i + j;
}
struct _acl_fun {
	char name[10];
	int (*fun)(int, int);
};

struct _acl_fun fun_arr[] = {
	{"fun1", fun_1},
	{"fun2", fun_2},
	{"fun2", fun_2}
};


main()
{
	int i = 0;
	for (i; i < sizeof(fun_arr)/(sizeof(struct _acl_fun)); i++) {
		printf("%s:", fun_arr[i].name);
		printf("ret %d\n\n",fun_arr[i].fun(i, i+1));
	}
}
