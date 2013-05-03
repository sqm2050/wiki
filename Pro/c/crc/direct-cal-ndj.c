#include <stdio.h>
#define     CRC_POLY    0x00011021
#define     CRC_WIDTH   16
#define     CRC_INIT    0x00000000
#define     DATA_POLY   0x31323334L
#define     DATA_WIDTH  32

void print_regs(int, int, int);
int main()
{
    unsigned long   data = DATA_POLY;
    unsigned long   regs = CRC_INIT;
    int shift_bit;
    int i;

// append zeros to the data
    data <<= CRC_WIDTH;
// print for debug
    printf("data -->\t0x%lx\t", data);
    for(i=DATA_WIDTH+CRC_WIDTH-1; i>=0; i--){
        printf("%d ", (data>>i)&0x1);
    }
    printf("\n");
// processing
    for(i = 1, shift_bit=DATA_WIDTH+CRC_WIDTH; shift_bit>0; shift_bit--, i++){
    // shift of 1 cycle
        regs = (regs<<1) | ((data>>(shift_bit-1))&0x1);
    // xor of 1 cycle
        if(regs>>CRC_WIDTH)     regs = regs ^ CRC_POLY;
    // result
     print_regs(DATA_WIDTH+CRC_WIDTH-shift_bit+1, CRC_WIDTH, regs);
    }

    return 0;
}

void print_regs(int crc_step, int crc_width, int crc_regs)
{
    int i;
    printf("Step %d\t\t", crc_step);
    for(i=crc_width; i>0; i--){
        printf("%d ", (crc_regs>>(i-1)&0x1));
    }
    printf("\n");
}
