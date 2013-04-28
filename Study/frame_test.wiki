reset
在OCTEON-SDK里的目录host/remote-utils/编译出工具oct-remote-reset
然后拷贝到52 
设置环境变量export OCTEON_REMOTE_PROTOCOL=pci,然后执行一下reset 
默认DEVICE_ID是0，也就是重启56A

export OCTEON_REMOTE_PROTOCOL=pci
export OCTEON_PCI_DEVICE=0
./oct-remote-reset


oct-remote-csr POW_PP_GRP_MSK0 0 关闭零核

时间设置:
1、设置网络
ifconfig eth2:0 10.10.168.188 netmask 255.255.255.0
ip route add default via 10.10.168.1 
cli 
2、设置时间
sync ntp on
sync ntp server  ntp.shu.edu.cn 
sync ntp manual
show information
3、设置流
set sregister fmt_manage stat_eif 0
set sregister fmt_manage send_stat enable
4、设置block
show ruleset zk aclmask
clear ruleset zk
add ruleset zk aclmask
sync 
5、服务器监听
tcpdump -nxxi eth4
6、寄存器
show counter 456

openwrt 编译问题
1、cp dl的目录
2、在openwrt目录下编译
3、无法找到SDK下的lib，因为lib没有做lib64的软链接。
      cd sdk/OCTEON-SDK/tools/mips64-octeon-linux-gnu/sys-root/
      ln -s lib64 lib
4、在OCTEON-SDK/tools/lib中找不到libgcc_s.so,注意这里必须是64位的。
      cp sdk/OCTEON-SDK/tools-gcc-4.3/mips64-octeon-linux-gnu/sys-root/usr/lib64/libgcc_s.so.1  sdk/OCTEON-SDK/tools/lib/    
4、找不到octeon的头文件，需要进入SDK中的linux，执行拷贝脚本，kernel dir是openwrt的目录，注意只需要指定到linux，不要asm。
     cd sdk/OCTEON-SDK/linux
     ./copy-se2kernel.sh copy ~/Documents/flow_md/linux/OpenWRT/build_dir/linux-octeon-dream/linux-2.6.32.27/                                 
cli:
	cpu0: set sregister 3gpp disable

grp:
	通过配置每个core对应的grp，实现相当于关闭了core的功能。
	比如把进入的报文设置grp为0，把一些core设置为不接收0号grp的数据，就相当与关闭了core。
make:	缺少这两个文件，touch第二个后，就会全部编译了
	/home/sqm/Documents/flow_md/scripts/config/conf
	/home/sqm/Documents/flow_md/include/config/auto.conf

================= Config ====
cpu0:
	add outgroup 0 0
	add outgroup 0 23
	set crosspass 0 forward 0 0
	set crosspass 0 forward 0 0 fmt_add=disable,reverse=disable


xfg:
	set xfg front xge_lan
	set xfg 24-25 up

acl:
	add ruleset test aclmask 0 action=forward,slotgroup=0,outgroup=0
	delete outgroup 0 0
	add ruleset test aclmask 0 pri=0,aging=0,sip=0.0.0.0/0,dip=0.0.0.0/0,sport=0-65535,dport=0-65535,protocol=any,action=forward

	
interface:	add copy ge ingress 0 2-9	#vlan add member 0 4032 2 0
						#vlan add member 0 4032 3 0
						.
						#vlan add member 0 4032 9 0
switch:
	# 1 taged	保持报文的tag,并且27口接收此tag的报文。

	vlan add member 0 0xfc6 27 1	
	vlan add member 0 0xfc7 27 1
	vlan add member 0 0xfc8 27 1
	vlan add member 0 0xfc9 27 1
	
	vlan remove member 0 0xfc6 25
	vlan remove member 0 0xfc7 25
	vlan remove member 0 0xfc8 25
	vlan remove member 0 0xfc9 25
crosspass:
	add outgroup 0 24
	delete outgroup 0 0

	set crosspass 0 forward 0 0 
	set crosspass 2 forward 0 0 
	.
	set crosspass 9 forward 0 0 

[sqm@sqm-juson:~/Documents/flow_md/cli/netgate/netgate_mdu]$ vi include/mdu.h
