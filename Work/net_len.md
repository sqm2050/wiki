ip:
	#define IP_HLEN(iph) ((int)(iph->ihl<<2)) 

tcp:
	#define TCP_HLEN(tcph) ((int)(tcph->doff<<2))

udp:
	#define UDP_HLEN ((int)sizeof(struct udphdr))
