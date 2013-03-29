全局变量：
	gcc下：
		同名全局变量在同文件 多个文件都不能都初始化。
		多个C源文件有同名全局变量，如果有一个不初始化，就算类型不一样在每个文件中也会以初始化的那一个为准，如果初始化的类型空间比未初始化的类型小,则会报警告：
		如：int para = 2; long para;
		Warning: size of symbol `para' changed from 8 in /tmp/ccG7Ghmg.o to 4 in /tmp/ccZWeGEk.o
		同一文件内类型就必须相等，而且也不能都初始化。

	cvmx_share_bss:
		同名全局变量，在同文件内同类型，以初始化的为准。
		同名全局变量，在多个文件中任何情况不可以了，就是报错：重定义。

	函数也是会调用改变本文件中的static变量，不管怎么被引用。
--------
注意处理报文中的NULL时候不能用strcpy,strcpy在遇到NULL的时候就停止copy了，要用memcpy。
--------
加点的赋值方式可以乱序；
假设：
struct s
{
  int a;
  int b;
};

可以这样赋值：
struct s s1 = 
{
  .b = 1,
  .a = 2 
};
struct s s1 = 
{
  b:1,
  a:2 
};
--------
#ifndef NULL

#if defined(_KERNEL) || !defined(__cplusplus)
#define NULL    ((void *)0)
#else
#if defined(__LP64__)
#define NULL    (0L)
#else
#define NULL    0
#endif  /* __LP64__ */
#endif  /* _KERNEL || !__cplusplus */

#endif
--------
内存对齐，往往是由编译器来做的，如果你使用的是gcc，可以在定义变量时，添加__attribute__，来决定是否使用内存对齐，或是内存对齐到几个字节，以上面的结构体为例：
1)到4字节，同样可指定对齐到8字节。
struct student
{
    char name[7];
    uint32_t id;
    char subject[5];
} __attribute__ ((aligned(4))); 

2)不对齐，结构体的长度，就是各个变量长度的和
struct student
{
    char name[7];
    uint32_t id;
    char subject[5];
} __attribute__ ((packed));
--------

