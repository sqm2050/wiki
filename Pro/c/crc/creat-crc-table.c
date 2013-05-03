/* 1110 0
 * 0000 00
 * 0011 100
 * 0001 1100
 * ----------
 * 1100 0100	---> 0xc4
 *
 * 生成0x11c的四位的驱动表,上面是1011(11d)的驱动表
 */
#include <stdio.h>
#define LUT_WIDTH	4
#define CRC_WIDTH	8
#define CRC_POLY	0x11c /* 1 0001 1100 */
fun()
{
	int table[1 << LUT_WIDTH];
	int index = 0, tmp, bit_cnt;
	for (index; index < (1 << LUT_WIDTH); index++) {
		tmp = 0;
		for (bit_cnt = LUT_WIDTH; bit_cnt > 0; bit_cnt--) {
			if ((index >> (bit_cnt - 1)) & 0x1 == 1)
				tmp ^= (CRC_POLY << (bit_cnt -1)) & 0xff;
		}
		table[index] = (unsigned char) tmp;
		printf("%d --- %x\n", index, table[index]);	/* 1011 --- 1100 0100 */

	}

}
main()
{
	fun();
}
