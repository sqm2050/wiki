static inline int atoh(char *str, int len)
{
	int i, result = 0, tmp = 0;
	for (i = 0; i < len; i++) {
		if(str[i] >= '0' && str[i]<='9')
			tmp = str[i] - '0';
		else if(str[i] >= 'a' && str[i]<= 'f')
			tmp = str[i] -'a' + 10;
		else if(str[i] >= 'A' && str[i] <= 'F')
			tmp = str[i] -'A' + 10;  
		else
			return -1;

		result = result << 4 | tmp;
	}
	return result;
}
