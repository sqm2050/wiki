## 首先编译了一次:sse sseapi 成功
### 生成conf,用于生成auto.conf文件
```
	cd scripts/config;make conf
```
### 编译
```
	make t5000hw1_meiya_radius_config
	make
```

### 再次编译,报错,已经存在了
> /home/sqm/flow_md/linux/OpenWRT/package/cpss-dx -> /home/sqm/flow_md/driver/swf/switch/cpss-dx
```
	rm /home/sqm/flow_md/linux/OpenWRT/package/cpss-dx
	ln -s ~/Documents/sw_framer/trunk  driver/swf/ 
```

### make sw
```
libpci/genDrvPciDrv.c:36:33: error: asm/octeon/cvmx-asm.h: No such file or directory
libpci/genDrvPciDrv.c: In function 'pcie_read':
libpci/genDrvPciDrv.c:513: warning: implicit declaration of function 'pci_read_config_space'
libpci/genDrvPciDrv.c: In function 'gen_read':
libpci/genDrvPciDrv.c:576: error: 'CVMX_SYNCS' undeclared (first use in this function)
libpci/genDrvPciDrv.c:576: error: (Each undeclared identifier is reported only once
libpci/genDrvPciDrv.c:576: error: for each function it appears in.)
make[4]: *** [libpci/genDrvPciDrv.o] Error 1
make[4]: Leaving directory `/home/sqm/flow_md/linux/OpenWRT/build_dir/linux-octeon-dream/juson_cmd'
make[3]: *** [/home/sqm/flow_md/linux/OpenWRT/build_dir/linux-octeon-dream/juson_cmd/.built] Error 2
make[3]: Leaving directory `/home/sqm/Documents/sw_framer/trunk/juson_cmd'
make[2]: *** [package/juson_cmd/compile] Error 2
make[2]: Leaving directory `/home/sqm/flow_md/linux/OpenWRT'
make[1]: *** [package/juson_cmd/compile] Error 2
make[1]: Leaving directory `/home/sqm/flow_md/linux/OpenWRT'
make: *** [sw] Error 2
```
> 这里需要进行copy：
```
	./copy-se2kernel.sh copy ~/Documents/flow_md/linux/OpenWRT/build_dir/linux-octeon-dream/linux-2.6.32.27/
```
> 先编译内核，因为linux-octeon-dream/linux-2.6.32.27都没有建立

### make linux
*  编译前先cp dl目录
```
	make linux
```
### 测试编译出来的内核压缩文件
```
	cp openwrt-octeon-dream-vmlinux.elf.lzma ~tftp/vm
	tftp 0 vm
	bootoctlinux 0 vm
```
可以正常启动.

### 再次全部编译,并没有进行copy
```
	make >log2 2>&1
```
### all install
```
	make install
```

### 测试新内核
```
	cp bin/vmlinux52 ~tftp/vm52
```
正常启动

### 测试整个包
```
	make install
	在我机器重新clone一份代码，编译的linux没有问题了，但是cli启动是会报错：
		root@juson:/mnt# cli /etc/xmlcli/admin.xml
		ERROR: Incompatible bootmem descriptor version: 0.0 at addr: 0x881040000000000
		ERROR: Incompatible bootmem descriptor version: 0.0 at addr: 0x881040000000000
	最终会起来，但是说会说se没有初始化：
		MD haven't initialized, please initialize it first before use.
	手动启动重启se后，问题依旧。
```

### 解决
#### 回退sdk
```
git reset 247cbd29c2e10cd33beea602039a04c49fe240a9  --hard
git clean -df
```
#### 删除linux中旧的驱动
```
	[sqm@sqm-juson:~/flow_md/linux/OpenWRT/build_dir/linux-octeon-dream]$ rm -rf octeon_pci_drv
```
#### 重新编译linux
```
	make linux
```
