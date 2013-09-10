### zxmd_main.c
1. zxmx_main_process():
line 150:这里有一个判断，可以把`sso_grp_procs`处理函数数组的默认值设置一个函数指针，此函数实现else结构内的功能。

> 分支和跳转的性能。

### zxmx_dpim.h:
2. switch (eth->vproto):
下面的case 操作注册成函数，或者一个大宏。

问题：协议号映射到响应的函数。
