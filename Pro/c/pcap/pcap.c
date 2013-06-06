#include <stdio.h>
#include <pcap/pcap.h>
#include <stdint.h>
#define PRINT_1 0
#define PRINT_2 1
uint8_t buffer[100000];
int main(int argc, char *argv[])
{
	if (argc != 2) {
		puts("error para");
		return 0;
	}

	int linefeed, i = 0;
	pcap_dumper_t *outdumper;
	struct pcap_pkthdr header;
	const uint8_t *packet;
	uint8_t errbuf[1000000];

	/* open input file */
	pcap_t *handle = pcap_open_offline(argv[1], errbuf);
	if (!handle) {
		printf("open file fail !\n");
		return -1;
	}

	pcap_is_swapped(handle);
	pcap_datalink(handle);

	/* open outhandle */
	pcap_t *outhandle = pcap_open_dead(DLT_EN10MB, 65535);
	if (!outhandle) {
		printf("outhandle is NULL\n");
		return -1;
	}

	/* open out file to outdumper */
	outdumper = pcap_dump_open(outhandle, "gtp_u_normal.pcap");

	while (1) {
		/* input file -> handle -> 1. packet ptr 2, header info */
		packet = pcap_next(handle, &header);
		if (!packet) break;
#if PRINT_1
		for (i = 0; i < header.len; i++) {
			printf("%02x ", packet[i]);
			if ((i + 1) % 16 == 0)
				printf("\n");
			else if ((i + 1) % 8 == 0)
				printf(" ");
		}
		printf("\n");
#endif
#if 0
		/* notice the endian */
		if (packet[12] == 0x91 && packet[13] == 0x00) {
			header.len -= 0x0b;
			for (i = 0; i < header.len; i++) {
				if (i < 12)
					buffer[i] = packet[i];
				else
					buffer[i] = packet[i + 0x0b ];
			}
		} else {
			for (i = 0; i < header.len; i++) {
				buffer[i] = packet[i];
			}
		}
#endif
#if PRINT_2
		for (i = 0; i < header.len; i++) {
			printf("%02x ", buffer[i]);
			if ((i + 1) % 16 == 0)
				printf("\n");
			else if ((i + 1) % 8 == 0)
				printf(" ");
		}
		printf("\n");
#endif
		pcap_dump((u_char*)outdumper, &header, buffer);
	}
	pcap_close(handle);
	return 0;
}
