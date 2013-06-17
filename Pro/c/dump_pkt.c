static inline void dump_pkt(char *packet, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		printf("%02hhx ", packet[i]);
		if ((i + 1) % 16 == 0)
			printf("\n");
		else if ((i + 1) % 8 == 0)
			printf(" ");
	}
	printf("\n");
}
