/*!
 * \file pointer_plus.c
 *
 * \brief 测试指针增加的大小
 * \env gcc:4.6.3 kernel:3.0.0-29-generic x86_64
 */
#include <stdio.h>
void pointer_plus(int **p)
{
	(*p)++;
}
main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9 };

	/* int型指针加一 */
	int *ptr = arr;
	ptr++;
	printf("%p\n%p\n%p\n", arr ,ptr, &arr);
	printf("%d\n", ptr[2]);	/**< 4 */
	printf("-----------------------\n");

	/* 利用二级指针索引到一级指针，再加一 */
	int **pptr = &ptr;
	printf("%p\n", *pptr);
	(*pptr)++;
	printf("%p\n",(*pptr));
	pointer_plus(pptr);
	printf("%p\n",(*pptr));

	/* 二级指针加一 */
	printf("-----------------------\n");
	printf("%p\n", pptr);
	pptr++;
	printf("%p\n", pptr);
}
