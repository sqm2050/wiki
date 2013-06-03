#include <stdio.h>
#include <stdint.h>
#include <pcap.h>
pcap_t *init_dev(char *dev)
{
	pcap_t *fp;
	char errbuf[1024];

	if (((fp = pcap_open_live(dev, 1500, (1 | 8 | 16), 1000, errbuf))
				== NULL)) {
		printf("Init dev:%s fail: %s\n", dev, errbuf);
		return NULL;
	} else {
		printf("Init dev:%s success:%p\n", dev,  fp);
	}
	return fp;
}
main()
{
	init_dev("wlan0");
}
