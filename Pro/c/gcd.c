/* 嵌套的gcd前面递归求得d，最大公约数，后面利用gcd后面的表达式，两次返回的出x0,y0的值
 * 第二个打印只打两次,因为第3次时。b ==0.就返回。
 * 注意最后的返回值，如果不手动设置，返回值，那么返回值不确定 */

#include <stdio.h>

int x0;
int y0;
int d;
static long gcd(long a, long b) {
	printf("a = %ld, b = %ld, d =%d\n", a, b, d);
	static long t;
       	if (b == 0) {
       		x0 = 1;
       		y0 = 0;
       		return a;
       	}
	
       	d = gcd(b, a % b);
       	t = x0;
       	x0 = y0;
       	y0 = t - a / b * y0;
	
	printf("%d, %d, d= %d\n", x0, y0, d);
	return d;
}

main()
{
	gcd(12, 9);
}
