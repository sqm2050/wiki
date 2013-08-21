## printf的实现
int printf(const char *fmt, ...)
{
	int i;
	char buf[255];
	
	va_list arg = (va_list)((char *)(&fmt) + 4);
	i = vsprintf(buf, fmt, arg);
	write(buf, i);
	
	return i;
}

### va_list
```
	va_list arg = (va_list)((char *)(&fmt) + 4);
```

va_list 的定义-字符指针:
```
	typedef char *va_list;
```
