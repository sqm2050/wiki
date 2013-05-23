=boyer moore字符串匹配算法=
向后偏移，而且自后向前比较，移动的大小根据两个规则而定。两个启发策略。

==坏字符规则==
* "坏字符" 对应在搜索词的第m位，在搜索词中的上一次出现位未n，所以后移位m - n位。
* 如果没有在搜索词中出现那么它的位置是-1，则整个搜索词后移。

==好后缀规则==
* 好后缀的位置以好后缀的最后一个字符为准。
* 如果好后缀在搜索词中没有重复出现，则它的上一次出现位置为-1。

==Boyer-Moore算法的基本思想==
* 每次后移这两个规则之中的较大值。
* 可以预先计算生成《坏字符规则表》和《好后缀规则表》。使用时进行查表。

查找4位长度的host:
```code 
    #include <stdio.h>
    #include <stdint.h>
    int bad(int i, char a)
    {
    	switch (a) {
    	case 'h':
    		if (i > 0) 		/* 比较，是因为要减去向上一次出现的位置 */
    			return i - 0;
    	case 'o':
    		if (i > 1)
    			return i - 1;
    	case 's':
    		if (i > 2)
    			return i - 2;
    	case 't':
    		if (i > 3)
    			return i - 3;	/* 不要break，因为如果正好，i == n（后面的值）那么应该去default，否则返回值不确定 */
    	default:
    		return i - (-1);
    	}
    
    }
    int good(i)
    {
    	switch (i) {
    	case 3:	/* 没有好后缀 */
    		return 1;
    	default:
    		return 4;
    	}
    }
    	
    char *bm_find_host(const char *text, int len)
    {
    	int i, shift = 0, bs, gs;
    	const char pattern[] = "host";
    	while (shift < len - 3 ) {
    		for (i = 3; i > -1; i--) {
    			if (text[shift + i] != pattern[i])
    				goto next;
    		}
    		return (uint8_t *)text + shift;
    next:
    		bs = shift + bad(i, text[shift + i]);
    		gs = shift + good(i);
    		shift = bs > gs ? bs : gs;
    	}
    	return NULL;
    
    }
    
    main()
    {
    	char buf[1024] = "12345678 host : www.baid.com dddadfhaifhaifal;ghaghaohga;hg";
    	char *p = bm_find_host(buf, 1024);
    	if (p)
    		printf("%s\n", p);
    
    
    }
```
