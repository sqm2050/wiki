c99中新增加了一个类型定义，就是restrict。
restrict的定义是It can be applied only to pointers, and it indicates that a pointer is the sole initial means of accessing a data object.
我不知道确切应该怎么翻译，大意是restrict只对指针有用，它声明一个指针是唯一初始化访问一个数据对象。
比如，按照书上的例子，
int ar[10];

int * restrict restar = (int *) malloc(10 * sizeof(int));

int * par = ar;

for (n = 0; n < 10; n++)

{

      par[n] += 5;

      restar[n] += 5;

      ar[n] *= 2;

      par[n] += 3;

      restar[n] += 3;

}

restar指针是restrict类型，par指针就不是，因为par即没有初始化也不是唯一访问ar数组的变量。
那么，上面的程序，因为restar是唯一反问数据块的指针，所以编译器可以对它优化为一条语句，
restar[n] += 8;     /* ok replacement */
而par就不可以，
par[n] += 8;      / * gives wrong answer */
One of the new features in the recently approved C standard C99, is the restrict pointer qualifier. This qualifier can be applied to a data pointer to indicate that, during the scope of that pointer declaration, all data accessed through it will be accessed only through that pointer but not through any other pointer. The 'restrict' keyword thus enables the compiler to perform certain optimizations based on the premise that a given object cannot be changed through another pointer. Now you're probably asking yourself, "doesn't const already guarantee that?" No, it doesn't. The qualifier const ensures that a variable cannot be changed through a particular pointer. However, it's still possible to change the variable through a different pointer. For example:
 

    void f (const int* pci, int *pi;); // is *pci immutable?
    {
      (*pi)+=1; // not necessarily: n is incremented by 1
       *pi = (*pci) + 2; // n is incremented by 2
    }
    int n;
    f( &n, &n);
 
In this example, both pci and pi point to the same variable, n. You can't change n's value through pci but you can change it using pi. Therefore, the compiler isn't allowed to optimize memory access for *pci by preloading n's value. In this example, the compiler indeed shouldn't preload n because its value changes three times during the execution of f(). However, there are situations in which a variable is accessed only through a single pointer. For example:

 

    FILE *fopen(const char * filename, const char * mode);
The name of the file and its open mode are accessed through unique pointers in fopen(). Therefore, it's possible to preload the values to which the pointers are bound. Indeed, the C99 standard revised the prototype of the function fopen() to the following:

 
    /* new declaration of fopen() in <stdio.h> */
    FILE *fopen(const char * restrict filename, 
                          const char * restrict mode);
Similar changes were applied to the entire standard C library: printf(), strcpy() and many other functions now take restrict pointers:

 
    int printf(const char * restrict format, ...);
    char *strcpy(char * restrict s1, const char * restrict s2);
C++ doesn't support restrict yet. However, since many C++ compilers are also C compilers, it's likely that this feature will be added to most C++ compilers too.


  
  
  
所以，在没有restrict的时候，编译器需要考虑上面的出错情况，而无法优化程序。

restrict也可以用在函数的指针参数前面，它表示在函数里没有其他标识符会修改指针所指的数据块，编译器可以优化函数。
在C99中新增了类型修饰符（qualifier） restrict 在网上找来找去，看到介绍它的不多，就把看到的一些介绍做个总结。
传说中下面是是书中的原话，到底是什么书却没人说：
========================8<====================================
restrict这种修饰符只适用于指针.
由restrict修饰的指针是最初唯一对指针所指向的对象进行存取的办法,
仅当第二个指针基于第一个时,才能对对象进行存取.
因此,对对象的存取都限定于基于有restrict修饰的指针表达式中.
由restrict修饰的指, const char * mode);
<!--[if !supportLineBreakNewLine]-->
<!--[endif]-->

The name of the file and its open mode are accessed through unique pointers in fopen(). Therefore, it's possible to preload the values to which the pointers are bound. Indeed, the C99 standard revised the prototype of the function fopen() to the following: 

/* new declaration of fopen() in <stdio.h>; */
    FILE *fopen(const char * restrict filename, 
                          const char * restrict mode);
Similar changes were applied to the entire standard C library: printf(), strcpy() and many other functions now take restrict pointers: 

int printf(const char * restrict format, ...);
    char *strcpy(char * restrict s1, const char * restrict s2);

C++ doesn't support restrict yet. However, since many C++ compilers are also C compilers, it's likely that this feature will be added to most C++ compilers too.

=====================8<================================
上面的例子简单来说就是被const修饰的指针指向的内容真的是不变的吗？在某些情况下显然不是，如第一段代码
void f (const int* pci, int *pi ) // is *pci immutable?
    {
      (*pi)+=1; // not necessarily: n is incremented by 1
       *pi = (*pci) + 2; // n is incremented by 2
    }
    int n;
    f( &n, &n);

pci和pi指向的都是n，虽然pci被const修饰，但pci指向的内容却在函数中被改变了，当用restrict修饰符之后 void f ( const int * restrict pci , int * restrict pi )，问题解决了：一旦我们再有如：f ( &n , &n ) 的调用，编译器将给出错误提示，这是由于一个地址可以通过两个指针来访问。

restrict同样可以用于数组的声明：
If you specify type qualifiers such as void foo(int * restrict a);, the C compiler expresses it with array syntax void foo(int a[restrict]); which is essentially the same as declaring a restricted pointer.

写了这么多，总结一下，其实restrict同const或valiate一样是一个修饰符而已，告诉编译器被restrict修饰的指针所指 向的对象，只能通过这个指针或基于这个指针的其他指针进行操作，即限制访问用restrict限制的指针指向的对象只能通过这个指针访问，这对编译器的优 化很有好处。
但要注意：restrict是C99中新增的关键字，在C89和C++中都不支持，在gcc中可以通过—std=c99来得到对它的支持。
