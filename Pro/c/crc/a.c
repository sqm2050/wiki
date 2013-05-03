#include <stdio.h>
#include <stdint.h>

uint64_t poly = 0x1;            /* POLY == 1001 */
int crc_num = 3;

uint64_t data = 0xf;            /* data:1111 */
int data_num = 4;
uint32_t regi = 0x00;           /* 3  bits */

main()
{
        uint32_t cur_bit, tmp;
        data <<= crc_num;       /* data: 111 1000 */
int i;

        for (i =1 ,cur_bit = 100; cur_bit > 0; cur_bit--, i++ ) {
                tmp = regi & 0x4;
                regi <<= 1;
                regi |= (data >> (cur_bit - 1)) & 0x0001;      /* 初始的几次移位，只是把原始数据移到register */
                regi &= 0x7;    /* 111 (3 bits) */
                if (tmp) {
                        regi ^= poly;
                }
        printf("%d crc --- %x\n",i, regi);
        }
}

