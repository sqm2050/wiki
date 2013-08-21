#include <stdio.h>
#include <stdint.h>
main()
{
	uint64_t dat_64 = 0x0881040000000000;
	uint32_t *pdat_32 = &dat_64;
	printf("%x\n", dat_64);
	printf("%x\n", *pdat_32);
}

/**
 * 小端：
 * 	0
 * 	0
 *
 * 大端：
 * 	0
 * 	8810400
 */
