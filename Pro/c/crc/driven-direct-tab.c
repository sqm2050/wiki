#include <stdio.h>
#define     BYTE_L  8
//#define     CRC32   // default CRC16, unless define CRC32

#ifdef  CRC32
    #define     CRC_WIDTH   32
    #define     CRC_POLY    0x04C11DB7
    #define     CRC_INIT    0xFFFFFFFF
#else
    #define     CRC_WIDTH   16
    #define     CRC_POLY    0x1021
    #define     CRC_INIT    0x0000
#endif

void print_regs(unsigned int, unsigned int);
int main()
{
    unsigned char   bit_cnt     ;
    unsigned short  index       ;
    unsigned int    table[256]  ;
    unsigned int    temp        ;

    unsigned char   buff[] = {0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39};
    unsigned int    len  = sizeof(buff);
    unsigned char   *pointer    ;
    unsigned int    regs        ;
    unsigned int    i           ;

// crc LUT generation
    for(index=0; index<256; index++){
        temp = 0;
        for(bit_cnt=BYTE_L; bit_cnt>0; bit_cnt--){
            if((index>>(bit_cnt-1) ^ temp>>(CRC_WIDTH-1))&0x1)  temp = (temp<<1) ^ CRC_POLY;
            else                                                temp <<= 1;
        }
#ifdef  CRC32
        table[index] = (unsigned int)temp;
#else
        table[index] = (unsigned short)temp;
#endif
    }
// crc calculation
    pointer = buff;
    regs = CRC_INIT;
    for(i=0; i<len; i++){
        print_regs(CRC_WIDTH, regs);
        regs = (regs<<BYTE_L) ^ table[(regs>>(CRC_WIDTH-BYTE_L))&0xFF ^ *pointer++];
    }
#ifdef  CRC32
    printf("result --> 0x%Xh\n", regs);
#else
    printf("result --> 0x%Xh\n", (unsigned short)regs);
#endif

    return 0;
}

void print_regs(unsigned int crc_width, unsigned int crc_regs)
{
    int i;
    for(i=crc_width; i>0; i--){
        printf("%d ", (crc_regs>>(i-1)&0x1));
    }
    printf("\n");
}
