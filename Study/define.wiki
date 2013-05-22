# 宏定义先后无关
```
    #include <stdio.h>
    #define AAA BBB
    #define BBB "aaa"
    
    main()
    {
    	printf("%s\n", AAA);
    }
```
照样可以打印除aaa。
