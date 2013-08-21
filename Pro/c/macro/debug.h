#ifdef	CONFIG_MODULE_DEBUG
#define MOUDLE_ERROR(module, fmt, arg...) \
	do { \
		if (strcmp(CONFIG_MODULE_DEBUG, module) != 0) \
			break; \
		printf("ERROR: [%20s] [%10s] fmt", __FUNCTION__, __LINE__, ##arg);\
	} while(0)
#endif

#define ERROR(fmt, arg...) \
	printf("ERROR: [%20s] [%10s] fmt", __FUNCTION__, __LINE__, ##arg);
