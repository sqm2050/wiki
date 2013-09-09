#include <stdio.h>
#include <stdint.h>
struct a1{
	uint64_t d1;
	uint64_t d2;
	uint32_t d3;
};

struct b1{
//	struct a1 da;
	struct{
		uint64_t d1;
		uint64_t d2;
		uint32_t d3;
	}__attribute__((packed))stu;
	uint32_t d4;
//}__attribute__((aligned(8)));
}__attribute__((packed));

struct c1{
	uint64_t d1;
	uint64_t d2;
	uint32_t d3;
	uint32_t d4;
};
main()
{
	struct b1 stu;
	printf("%lu\n", sizeof (struct a1));
	printf("%lu\n", sizeof (struct b1));
	printf("%lu\n", sizeof (stu.stu));
	printf("%lu\n", sizeof (struct c1));

	printf("%p %d\n", &stu, (int)&stu % 8);

}
