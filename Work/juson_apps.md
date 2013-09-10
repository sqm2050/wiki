## apps编译
### 添加Kbuild控制宏
在JFAU下面
```
	config SSN
		bool "Utils to operation fau memory"
		default n
```

### 把你要生成的目标文件的名字加到APPS
```
ifdef CONFIG_SSN
	APPS += Pro
endif
```

### 添加生成条件
```
	Pro: 依赖的.c *.h .o
		# 创建配置文件的软连接
		$(Q)ln -sf $(SSE_SRC)/config/cvmx-config.h $(OCTEON_ROOT)/target/include
	# 如果是基于远程pcie的工具
	ifeq ($(CONFIG_REMOTE_LIBS),y)
		$(CC) $(REMOTE_CFLAGS)  -o $@ $(filter-out %.h,$^)	# 过滤掉依赖的.h文件
	else
	# 本地工具
		$(CC) $(LOCAL_CFLAGS) $(EXTRA_CFLAGS) -o $@ $(filter-out %.h,$^)
	endif
```

### make menuconfig 选中
```
	cd JusonFlow
	make menuconfig
	选中APPS，你的配置
```
> 暂时不要选pcie test, 有编译问题

然后执行make apps.

Write For 辉祥君！
