#include <stdio.h>
#define CRC_POLY	0x00011021
#define CRC_WIDTH	16
#define CRC_INIT	0X00000000
#define DATA_POLY	0x31323334L
#define DATA_WIDTH	32

void print_regs(int);

int main()
{
	unsigned long data = DATA_POLY;
	unsigned long regs = CRC_INIT;
	int poly = CRC_POLY & 0xffff;
	int shift_bit;
	int i, j = 1; 

	data <<=  CRC_WIDTH;
	for (i = 48; i > 0; i--, j++) {
		shift_bit = regs & 0x8000;
		regs <<= 1;
		regs |= (data >> i -1 ) & 0x01;
		regs &= 0xffff;
		if (shift_bit) {
			regs ^= poly;
		}
		printf("step %d ", j);
		print_regs(regs);
	}

}

void print_regs(int regs)
{
	int i;
	
	for (i = 16; i > 0; i--) {
		printf("%d ", (regs >> (i - 1) & 0x1));
	}
	printf("\n");
}
