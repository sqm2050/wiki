pppoe b8:ac:6f:2f:24:4a e8:9a:8f:9b:ca:37 24

mips64-octeon-linux-gnu-gcc -O2 -MD -Wall -pipe -mips64r2 -mabi=64 -D_GNU_SOURCE -D__linux__ -Wall -DOCTEON_TARGET=linux_64 -DUSE_RUNTIME_MODEL_CHECKS=1 -I/home/sqm/tmp/JusonFlow/apps/../common -I/home/sqm/tmp/JusonFlow/apps/../include -I/home/sqm/tmp/JusonFlow/apps/../include/config -I/home/sqm/Documents/flow_md/sdk/OCTEON-SDK/target/include  -o ubpctl zxmx_c3101.c ubpctl.c crc32.c cvmx-sysinfo.c cvmx-clock.c cvmx-bootmem.c cvmx-warn.c octeon-feature.c

mips64-octeon-linux-gnu-gcc -O2 -MD -Wall -pipe -mips64r2 -mabi=64 -D_GNU_SOURCE -D__linux__ -Wall -DOCTEON_TARGET=linux_64 -DUSE_RUNTIME_MODEL_CHECKS=1 -I/home/sqm/tmp/JusonFlow/common -I/home/sqm/tmp/JusonFlow/include -I/home/sqm/tmp/JusonFlow/include/config -I/home/sqm/tmp/JusonFlow/sdk/OCTEON-SDK/target/include -march=octeon2 -mtune=octeon2 -o ubpctl zxmx_c3101.c ubpctl.c crc32.c cvmx-sysinfo.c cvmx-clock.c cvmx-bootmem.c cvmx-warn.c octeon-feature.c


mips64-octeon-linux-gcc -march=octeon2
```
{standard input}: Assembler messages:
{standard input}:21: Error: illegal operands `dmtc2 $2,0x4200'
{standard input}:30: Error: illegal operands `dmtc2 $4,0x0211'
{standard input}:46: Error: illegal operands `dmtc2 $2,0x0214'
{standard input}:81: Error: illegal operands `dmtc2 $2,0x1217'
{standard input}:108: Error: illegal operands `dmtc2 $2,0x0214'
{standard input}:116: Error: illegal operands `dmfc2 $2,0x0203'
{standard input}:1211: Error: illegal operands `dmtc2 $2,0x4200'
{standard input}:1217: Error: illegal operands `dmtc2 $3,0x0201'
{standard input}:1236: Error: illegal operands `dmtc2 $2,0x0204'
{standard input}:1244: Error: illegal operands `dmfc2 $7,0x0201'
```

123.114.48.55
41	41022-41022
249	10022-10022
248	24822-24822
247	24722-24722

i=`grep "Subject: getip" *|wc -l`
j=`grep "Subject: getip" *|wc -l`

while [ ture ]
do
	getmail --rcfile=getmailrc.sqm2050_qq >/dev/null
	i=`grep "Subject: getip" *|wc -l`

	if [ $i -ne $j ]
	then
		sendemail -s smtp.exmail.qq.com -f sunqingmeng@jusontech.com -t guodemo@jusontech.com -u sendip -m `w3m -dump http://submit.apnic.net/templates/yourip.html | grep -P -o '(\d+\.){3}\d+' ` -xu sunqingmeng@jusontech.com -xp sqm19901227 -o tls=auto
	j=$i
	fi
	sleep 10
done

 729272771
 
root@juson:~# 
root@juson:~# PP1:~CONSOLE-> [id 6] [status 0] [link 0]
PP3:~CONSOLE-> [id 6] [status 0] [link 0]
PP1:~CONSOLE-> [id 5] [status 0] [link 0]
PP2:~CONSOLE-> [id 6] [status 0] [link 0]
PP4:~CONSOLE-> [id 6] [status 0] [link 0]
PP1:~CONSOLE-> [final id 5]
PP3:~CONSOLE-> [id 5] [status 0] [link 0]
PP4:~CONSOLE-> [id 5] [status 0] [link 0]
PP7:~CONSOLE-> [id 6] [status 0] [link 0]
PP2:~CONSOLE-> [id 5] [status 0] [link 0]
PP6:~CONSOLE-> [id 6] [status 0] [link 0]
PP8:~CONSOLE-> [id 6] [status 0] [link 0]
PP9:~CONSOLE-> [id 6] [status 0] [link 0]
PP7:~CONSOLE-> [id 5] [status 0] [link 0]
PP8:~CONSOLE-> [id 5] [status 0] [link 0]
PP3:~CONSOLE-> [final id 6]
PP4:~CONSOLE-> [final id 5]
PP6:~CONSOLE-> [id 5] [status 0] [link 0]
PP7:~CONSOLE-> [final id 5]
PP3:~CONSOLE-> [id 6] [status 0] [link 0]
PP1:~CONSOLE-> [id 6] [status 0] [link 0]
PP2:~CONSOLE-> [final id 5]
PP6:~CONSOLE-> [final id 6]
PP7:~CONSOLE-> [id 6] [status 0] [link 0]
PP1:~CONSOLE-> [id 5] [status 0] [link 0]
PP8:~CONSOLE-> [final id 5]
PP9:~CONSOLE-> [id 5] [status 0] [link 0]
PP2:~CONSOLE-> [id 6] [status 0] [link 0]
PP3:~CONSOLE-> [id 5] [status 0] [link 0]
PP5:~CONSOLE-> [id 6] [status 0] [link 0]
PP4:~CONSOLE-> [id 6] [status 0] [link 0]
PP7:~CONSOLE-> [id 5] [status 0] [link 0]
PP3:~CONSOLE-> [final id 6]
PP1:~CONSOLE-> [final id 6]
PP7:~CONSOLE-> [final id 5]
PP5:~CONSOLE-> [id 5] [status 0] [link 0]
PP6:~CONSOLE-> [id 6] [status 0] [link 0]
PP1:~CONSOLE-> [id 6] [status 0] [link 0]
PP7:~CONSOLE-> [id 6] [status 0] [link 0]
PP4:~CONSOLE-> [id 5] [status 0] [link 0]
PP6:~CONSOLE-> [id 5] [status 0] [link 0]
PP7:~CONSOLE-> [id 5] [status 0] [link 0]
PP4:~CONSOLE-> [final id 6]
PP5:~CONSOLE-> [final id 6]
PP2:~CONSOLE-> [id 5] [status 0] [link 0]
PP6:~CONSOLE-> [final id 5]
PP7:~CONSOLE-> [final id 5]
PP3:~CONSOLE-> [id 6] [status 0] [link 0]
PP1:~CONSOLE-> [id 5] [status 0] [link 0]
PP2:~CONSOLE-> [final id 5]
PP9:~CONSOLE-> [final id 5]
PP4:~CONSOLE-> [id 6] [status 0] [link 0]
PP1:~CONSOLE-> [final id 5]
PP3:~CONSOLE-> [id 5] [status 0] [link 0]
PP4:~CONSOLE-> [id 5] [status 0] [link 0]
PP2:~CONSOLE-> [id 6] [status 0] [link 0]
PP3:~CONSOLE-> [final id 6]
PP2:~CONSOLE-> [id 5] [status 0] [link 0]
PP4:~CONSOLE-> [final id 5]
PP2:~CONSOLE-> [final id 6]

JSH6024130510P03N049

## aclex:配置
```
juson(config-cpu0)# show ruleset test aclex     

 ruleset: [test] aclex configuration
	 aclex[1]: action=forward,do_acl=disable,slotgroup=0,outgroup=60,ud0_mode=head,ud0_offset=20,ud0_key=0xc021000000000000/0xffff000000000000
	 Flag_Enable:1	 Flag_Sync: 1
```

```
imsi:460001711725062f, imei:0, msisdn:13671731399f, apn:CMWAP
lac: 0, ci: 0, rat: 1
user_ip: 0a9a2fd9,sgsn_ip_c:ddb12c59, sgsn_ip_u: ddb12c59, ggsn_ip_c:ddb12d73,ggsn_ip_u:ddb12d73
sgsn_teid_c:dc009f38, sgsn_teid_u:00009f74,ggsn_teid_c:b2952438,ggsn_teid_u:f0cd2338

PP1:~CONSOLE-> GN_ANALY:[               process_gn_if][ 148]:[Begin to add user]
PP1:~CONSOLE-> ---------------------------------------------
PP1:~CONSOLE-> imsi:460018618605390f, imei:3520120473156360, msisdn:18688613635f, apn:3GNET
PP1:~CONSOLE-> lac: 42325, ci: 2811, rat: 1
PP1:~CONSOLE-> user_ip: 0a0280e7,sgsn_ip_c:dcceb841, sgsn_ip_u: dcceb845, ggsn_ip_c:dcce82e1,ggsn_ip_u:dcce82e5
PP1:~CONSOLE-> sgsn_teid_c:9c2750ad, sgsn_teid_u:3c710cb5,ggsn_teid_c:1c00f86e,ggsn_teid_u:270b48db
PP1:~CONSOLE-> ---------------------------------------------
PP1:~CONSOLE-> GN_ANALY:[                 add_user_gn][ 371]:Add ip ok!
PP1:~CONSOLE-> GN_ANALY:[                 add_user_gn][ 388]:Add imsi ok!
PP1:~CONSOLE-> GN_ANALY:[                 add_user_gn][ 405]:Add imei ok!
PP1:~CONSOLE-> GN_ANALY:[                 add_user_gn][ 422]:Add msisdn ok!
PP1:~CONSOLE-> GN_ANALY:[                 add_user_gn][ 455]:Add gsn ok!

PP1:~CONSOLE-> GN_ANALY:[               process_gn_if][ 148]:[Begin to add user]
PP1:~CONSOLE-> ---------------------------------------------
PP1:~CONSOLE-> imsi:460018618605390f, imei:3520120473156360, msisdn:18688613635f, apn:3GNET
PP1:~CONSOLE-> lac: 42325, ci: 2811, rat: 1
PP1:~CONSOLE-> user_ip: 0a0280e7,sgsn_ip_c:dcceb841, sgsn_ip_u: dcceb845, ggsn_ip_c:dcce82e1,ggsn_ip_u:dcce82e5
PP1:~CONSOLE-> sgsn_teid_c:9c2750ad, sgsn_teid_u:3c710cb5,ggsn_teid_c:1c00f86e,ggsn_teid_u:270b48db
PP1:~CONSOLE-> ---------------------------------------------
PP1:~CONSOLE-> GN_ANALY:[                 add_user_gn][ 371]:Add ip ok!
PP1:~CONSOLE-> GN_ANALY:[                 add_user_gn][ 388]:Add imsi ok!
PP1:~CONSOLE-> GN_ANALY:[                 add_user_gn][ 405]:Add imei ok!
PP1:~CONSOLE-> GN_ANALY:[                 add_user_gn][ 422]:Add msisdn ok!
PP1:~CONSOLE-> GN_ANALY:[                 add_user_gn][ 455]:Add gsn ok!

PP1:~CONSOLE-> GN_ANALY:[               process_gn_if][ 172]:[Begin to add user]
PP1:~CONSOLE-> ---------------------------------------------
PP1:~CONSOLE-> imsi:460018618605390f, imei:3520120473156360, msisdn:18688613635f, apn:3GNET
PP1:~CONSOLE-> lac: 9558, ci: 1734, rat: 2
PP1:~CONSOLE-> user_ip: 0a0280e7,sgsn_ip_c:dcceb841, sgsn_ip_u: dcceb845, ggsn_ip_c:dcce82e1,ggsn_ip_u:dcce82e5
PP1:~CONSOLE-> sgsn_teid_c:9c2750ad, sgsn_teid_u:3c710cb5,ggsn_teid_c:1c00f86e,ggsn_teid_u:270b48db
PP1:~CONSOLE-> ---------------------------------------------
PP1:~CONSOLE-> GN_ANALY:[                 add_user_gn][ 371]:Add ip ok!
PP1:~CONSOLE-> GN_ANALY:[                 add_user_gn][ 388]:Add imsi ok!
PP1:~CONSOLE-> GN_ANALY:[                 add_user_gn][ 405]:Add imei ok!
PP1:~CONSOLE-> GN_ANALY:[                 add_user_gn][ 422]:Add msisdn ok!
PP1:~CONSOLE-> GN_ANALY:[                 add_user_gn][ 455]:Add gsn ok!
```




mips64-octeon-linux-gnu-gcc -O2 -MD -Wall -pipe -mips64r2 -mabi=64 -D_GNU_SOURCE -D__linux__ -Wall -DOCTEON_TARGET=linux_64 -DUSE_RUNTIME_MODEL_CHECKS=1 -I/home/sqm/tmp/JusonFlow/common -I/home/sqm/tmp/JusonFlow/include -I/home/sqm/tmp/JusonFlow/include/config -I/home/sqm/tmp/JusonFlow/sdk/OCTEON-SDK/target/include -I/home/sqm/tmp/JusonFlow/libexec -I/home/sqm/tmp/JusonFlow/libexec/log -I/home/sqm/tmp/JusonFlow/libexec/ssn -I/home/sqm/tmp/JusonFlow/libexec/acl -I/home/sqm/tmp/JusonFlow/libexec/acl/rfc -I/home/sqm/tmp/JusonFlow/libexec/acl/ac -I/home/sqm/tmp/JusonFlow/libexec/acl/hfa -I/home/sqm/tmp/JusonFlow/libexec/eprm -I/home/sqm/tmp/JusonFlow/libexec/mact -I/home/sqm/tmp/JusonFlow/libexec/modctl -I/home/sqm/tmp/JusonFlow/libexec/dpim -I/home/sqm/tmp/JusonFlow/libexec/dpim/3gpp -I/home/sqm/tmp/JusonFlow/libexec/dpim/gn -I/home/sqm/tmp/JusonFlow/libexec/port_block -I/home/sqm/tmp/JusonFlow/libexec/url -I/home/sqm/tmp/JusonFlow/libexec/url/url_block -I/home/sqm/tmp/JusonFlow/libexec/url/host_block -I/home/sqm/tmp/JusonFlow/libexec/fmt -I/home/sqm/tmp/JusonFlow/libexec/common -I/home/sqm/tmp/JusonFlow/libexec/common/include -I/home/sqm/tmp/JusonFlow/libexec/common/hwbase -I/home/sqm/tmp/JusonFlow/libexec/ip_block -I/home/sqm/tmp/JusonFlow/libexec/scount -I/home/sqm/tmp/JusonFlow/sse/config -I/home/sqm/tmp/JusonFlow/library -march=octeon -mtune=octeon -o cvmx-sysinfo.o cvmx-sysinfo.c

mips64-octeon-linux-gnu-gcc -O2 -MD -Wall -pipe -mips64r2 -mabi=64 -D_GNU_SOURCE -D__linux__ -Wall -DOCTEON_TARGET=linux_64 -DUSE_RUNTIME_MODEL_CHECKS=1 -I/home/sqm/flow_md/common -I/home/sqm/flow_md/include -I/home/sqm/flow_md/include/config -I/home/sqm/flow_md/sdk/OCTEON-SDK/target/include -c -o cvmx-sysinfo.o /home/sqm/flow_md/sdk/OCTEON-SDK/executive/cvmx-sysinfo.c


mips64-octeon-linux-gnu-gcc -O2 -MD -Wall -pipe -mips64r2 -mabi=64 -D_GNU_SOURCE -D__linux__ -Wall -DOCTEON_TARGET=linux_64 -DUSE_RUNTIME_MODEL_CHECKS=1 -I/home/sqm/tmp/JusonFlow/common -I/home/sqm/tmp/JusonFlow/include -I/home/sqm/tmp/JusonFlow/include/config -I/home/sqm/tmp/JusonFlow/sdk/OCTEON-SDK/target/include -I/home/sqm/tmp/JusonFlow/libexec -I/home/sqm/tmp/JusonFlow/libexec/log -I/home/sqm/tmp/JusonFlow/libexec/ssn -I/home/sqm/tmp/JusonFlow/libexec/acl -I/home/sqm/tmp/JusonFlow/libexec/acl/rfc -I/home/sqm/tmp/JusonFlow/libexec/acl/ac -I/home/sqm/tmp/JusonFlow/libexec/acl/hfa -I/home/sqm/tmp/JusonFlow/libexec/eprm -I/home/sqm/tmp/JusonFlow/libexec/mact -I/home/sqm/tmp/JusonFlow/libexec/modctl -I/home/sqm/tmp/JusonFlow/libexec/dpim -I/home/sqm/tmp/JusonFlow/libexec/dpim/3gpp -I/home/sqm/tmp/JusonFlow/libexec/dpim/gn -I/home/sqm/tmp/JusonFlow/libexec/port_block -I/home/sqm/tmp/JusonFlow/libexec/url -I/home/sqm/tmp/JusonFlow/libexec/url/url_block -I/home/sqm/tmp/JusonFlow/libexec/url/host_block -I/home/sqm/tmp/JusonFlow/libexec/fmt -I/home/sqm/tmp/JusonFlow/libexec/common -I/home/sqm/tmp/JusonFlow/libexec/common/include -I/home/sqm/tmp/JusonFlow/libexec/common/hwbase -I/home/sqm/tmp/JusonFlow/libexec/ip_block -I/home/sqm/tmp/JusonFlow/libexec/scount -I/home/sqm/tmp/JusonFlow/sse/config -I/home/sqm/tmp/JusonFlow/library -march=octeon2 -mtune=octeon2 -o pppoe cvmx-sysinfo.o pppoe_dir/cvmx-bootmem.o pppoe_dir/cvmx-clock.o pppoe_dir/cvmx-sysinfo.o pppoe_dir/cvmx-warn.o pppoe_dir/octeon-feature.o pppoe_dir/pppoe.o

[原文]

太上，不知有之；其次，亲而誉之；其次，畏之；其次，侮之。信不足焉，有不信焉。悠兮，其贵言。功成事遂，百姓皆谓“我自然”。

[译文]

最好的统治者，人民并不知道他的存在；其次的统治者，人民亲近他并且称赞他；再次的统治者，人民畏惧他；更次的统治者，人民轻蔑他。统治者的诚信不足，人民才不相信他，最好的统治者是多么悠闲。他很少发号施令，事情办成功了，老百姓说“我们本来就是这样的。

../lib/libnetgate.a(jas_common.o): In function `jas_if_get_frmer_mode':
/home/sqm/tmp/JusonFlow/linux/OpenWRT/build_dir/linux-octeon2-dream/netgate/lib/jas/jas_common.c:1294: undefined reference to `jas_sw_api_intf_mode_get'
../lib/libnetgate.a(jas_common.o): In function `jas_if_set_mode':
/home/sqm/tmp/JusonFlow/linux/OpenWRT/build_dir/linux-octeon2-dream/netgate/lib/jas/jas_common.c:951: undefined reference to `jas_sw_api_intf_lan_mode_set'
/home/sqm/tmp/JusonFlow/linux/OpenWRT/build_dir/linux-octeon2-dream/netgate/lib/jas/jas_common.c:952: undefined reference to `jas_sw_api_intf_lan_mode_set'
/home/sqm/tmp/JusonFlow/linux/OpenWRT/build_dir/linux-octeon2-dream/netgate/lib/jas/jas_common.c:954: undefined reference to `jas_sw_api_intf_wan_mode_set'
/home/sqm/tmp/JusonFlow/linux/OpenWRT/build_dir/linux-octeon2-dream/netgate/lib/jas/jas_common.c:955: undefined reference to `jas_sw_api_intf_wan_mode_set'

root@(none):~# [   62.912245] OCTEON[0]: Received active indication from core
[   62.917837] OCTEON[0] is running BASE application (core clock: 750000000 Hz)
[   64.683073] OCTEON[0] Poll Function (Module Starter arg: 0x0) completed (status: Finished)
[   68.823874] OCTEON[1]: Received active indication from core
[   68.829465] OCTEON[1] is running BASE application (core clock: 750000000 Hz)
[   70.273074] OCTEON[1] Poll Function (Module Starter arg: 0x0) completed (status: Finished)

gtp 10.186.122.194 221.177.196.96 06002317

pppoe e8:9a:8f:9b:ca:37 b8:ac:6f:2f:24:4a 24


ip_idx:858	imsi_idx:601	imei_idx:33536	msisdn_idx:295448
imsi:460021271119815f	imei:8604117003250278	msisdn:15127194983f	apn:CMWAP
lac: 12552	ci: 51360	rat: 2
user_ip: 0aba7ac2	sgsn_ip_c:ddb1c410	sgsn_ip_u: ddb1c412	 ggsn_ip_c:ddb1c460	ggsn_ip_u:ddb1c460
sgsn_teid_c:8d0000c4	sgsn_teid_u:363b9e85	ggsn_teid_c:03290e32	ggsn_teid_u:06002317

root@juson:~# gn --msisdn 15127194983   
---------------------------------------------
ip_idx:858	imsi_idx:601	imei_idx:33536	msisdn_idx:295448
imsi:460021271119815f	imei:8604117003250278	msisdn:15127194983f	apn:CMWAP
lac: 12552	ci: 51360	rat: 2
user_ip: 0aba7ac2	sgsn_ip_c:ddb1c410	sgsn_ip_u: ddb1c412	 ggsn_ip_c:ddb1c460	ggsn_ip_u:ddb1c460
sgsn_teid_c:8d0000c4	sgsn_teid_u:363b9e85	ggsn_teid_c:03290e32	ggsn_teid_u:06002317
---------------------------------------------


U-Boot 2011.03-00025-gb546673-dirty (Development build, svnversion: u-boot:exported, exec:exported) (Build time: Mar 12 2012 - 14:28:10)

[   34.072554] rtc-pcf8563 1-0051: low voltage detected, date/time is not reliable.
[   34.080010] rtc-pcf8563 1-0051: setting system clock to 1980-01-23 00:36:34 UTC (317435794)
[   34.090273] Freeing unused kernel memory: 5248k freed
[   34.097792] Kernel panic - not syncing: Attempted to kill init!

*** NMI Watchdog interrupt on Core 0x01 ***
        $0      0x0000000000000000      at      0xffffffff81200008
        v0      0xffffffff80100b60      v1      0x0000000000000001
        a0      0xfffffffffffffffd      a1      0x0000000000000000
        a2      0xffffffff80cae6b8      a3      0x0000000000000001
        a4      0x0000000400000000      a5      0xa80000003bd8c998
        a6      0xa80000003ef66c98      a7      0xffffffff80cae6b0
        t0      0x0000000000000000      t1      0x000000001000001f
        t2      0xa80000003ef6c000      t3      0x0000000000000000
        s0      0xffffffff81200000      s1      0xa8000000037e14e8
        s2      0x0000000000200200      s3      0x0000000000100100
        s4      0xffffffff80c2cb38      s5      0x0000000000000002
        s6      0xffffffffffffffff      s7      0x0000000000000079
        t8      0x0000000000000000      t9      0xffffffff80119cc0
        k0      0x000000009c004370      k1      0xa80000003ef7fe60
        gp      0xa80000003ef7c000      sp      0xa80000003ef7fbe0
        s8      0xffffffff80c2d378      ra      0xffffffff8039c198
        err_epc 0xffffffff80100b80      epc     0xffffffff80100b80
        status  0x0000000010588ce4      cause   0x0000000040808800
        sum0    0x0000000000000000      en0     0x0000000000000000
*** Chip soft reset soon ***

### 驱动报错---发送pcie消息
root@juson:~# gtp 0 num
[  467.317884] Octeon device (0) is in state (0x8)
[  467.322429]
[  467.322432]  Did you follow the driver load sequence in components/driver/README.txt?
ERROR: sent gtp request fail! 

print_octeon_state_errormsg

### pcie-req库编译
mips64-octeon-linux-gnu-gcc
-O2 -W -Wall -MD -fPIC -shared
-D_GNU_SOURCE
-DUSE_RUNTIME_MODEL_CHECKS=1
-DCVMX_BUILD_FOR_LINUX_HOST=1
-DMAX_PCIE_CPU=2
-DLOGDEBUG=1

-I/home/sqm/tmp/JusonFlow/libexec/common/include
-I/home/sqm/tmp/JusonFlow/sdk/OCTEON-SDK/components/driver/host/include
-I/home/sqm/tmp/JusonFlow/sdk/OCTEON-SDK/components/driver/common

-o libpcie_req.so libpcie_req.c

mips64-octeon-linux-gnu-gcc -O2 -W -Wall -MD -fPIC -shared -D_GNU_SOURCE -DUSE_RUNTIME_MODEL_CHECKS=1 -DCVMX_BUILD_FOR_LINUX_HOST=1 -DMAX_PCIE_CPU=2 -DLOGDEBUG=1 -I/home/sqm/tmp/JusonFlow/libexec/common/include -I/home/sqm/tmp/JusonFlow/sdk/OCTEON-SDK/components/driver/host/include -I/home/sqm/tmp/JusonFlow/sdk/OCTEON-SDK/components/driver/common -o libpcie_req.so libpcie_req.c 

## 5224-HW2 错误
### 1
ERROR: Incompatible bootmem descriptor version: 0.0 at addr: 0x881040000000000
ERROR: Incompatible bootmem descriptor version: 0.0 at addr: 0x881040000000000

### 2
root@juson:~# gtp 0  num
[  235.106892] octeon_ioctl: cmd:-1043283711  
[  235.110918] Octeon device (0) is in state (0x8)
[  235.115458] 
[  235.115460]  Did you follow the driver load sequence in components/driver/README.txt?
ERROR: sent gtp request fail!

> octeon_ioctl: cmd:	< ./linux/OpenWRT/dl/build_dir/linux-octeon2-dream/octeon_pci_drv/.ko（cmd正确)

### err-1
$ERROR: Incompatible bootmem descriptor version: 0.0 at addr: 0x881040000000000$

> 换过linux，cn56hw2.bin问题依旧存在，而且mducmd，cli都会报错：应该是mduapi了。

代码关系：
```
cvmx-bootmem.c:
	__cvmx_bootmem_check_version -> cvmx_bootmem_phy_named_block_find -> cvmx_bootmem_find_named_block
	
mduapi_init.c:
	mduapi_get_sdata <- cvmx_bootmem_find_named_block
	
mduapi.error.slog:
	[mduapi_init.c#mduapi_get_sdata():210]Sreg haven't been initialized, please initialize it before use.
```

首先验证是libmduapi.so的问题：

> 最先开始的那个flow_md也存在这样的问题---而且linux会panic，这次在juson_flow里面也出现了git clean -xdf后解决

在上次新克隆的flow_md的目录中编译新的mduapi，copy(/home/sqm/flow_md/linux/OpenWRT/build_dir/linux-octeon-dream/mduapi/libmduapi.so)到52:/usr/lib

启动cli，正常了。

### err-2
err-1解决之后，err-2也没有出现了

### err-1详解
```
    cvmx_dprintf("ERROR: Incompatible bootmem descriptor version: %d.%d at addr: 0x%llx\n",
		    major_version,
			(int)CVMX_BOOTMEM_DESC_GET_FIELD(minor_version),
		    (ULL)cvmx_bootmem_desc_addr);
```
Juson_Flow 出错打印
root@juson:~# cli /etc/xmlcli/admin.xml 
ERROR: Incompatible bootmem descriptor version: 0.0 at addr: 0x881040000000000
ERROR: Incompatible bootmem descriptor version: 0.0 at addr: 0x881040000000000

Flow_md 手动打印
root@juson:~# cli /etc/xmlcli/admin.xml 
ERROR: Incompatible bootmem descriptor version: 3.0 at addr: 0x48108
ERROR: Incompatible bootmem descriptor version: 3.0 at addr: 0x48108

root@juson:~# cli /etc/xmlcli/admin.xml 
octeon_read_core_direct:0x881040000000000
cvmx_bootmem_desc_addr = cvmx_read64_uint64: 0881040000000000
	pci_remote_read_mem64

### dump
root@(none):~# cli /etc/xmlcli/admin.xml 
ERROR: Incompatible bootmem descriptor version: 0.0 at addr: 0x881040000000000
ERROR: Incompatible bootmem descriptor version: 0.0 at addr: 0x881040000000000
ERROR: Incompatible bootmem descriptor version: 0.0 at addr: 0x881040000000000
ERROR: Incompatible bootmem descriptor version: 0.0 at addr: 0x881040000000000
ERROR: Incompatible bootmem descriptor version: 0.0 at addr: 0x881040000000000
.
root@(none):~# cp /mnt/libmduapi.so /usr/lib
root@(none):~# cli /etc/xmlcli/admin.xml 
[   87.607553] OCTEON[0]: Received active indication from core
[   87.613153] OCTEON[0] is running BASE application (core clock: 750000000 Hz)
[   89.272522] OCTEON[0] Poll Function (Module Starter arg: 0x0) completed (status: Finished)
[   91.884348] OCTEON[1]: Received active indication from core
[   91.889938] OCTEON[1] is running BASE application (core clock: 750000000 Hz)
[   93.312529] OCTEON[1] Poll Function (Module Starter arg: 0x0) completed (status: Finished)
mv: cannot rename '/var/log/mvc.error.log': No such file or directory
welcome to juson!

juson>



########### 56hw1 ###########
root@juson:~# pppoe 0  e8:9a:8f:9b:ca:37 b8:ac:6f:2f:24:4a 24
smac: 0xe89a8f9bca37    dmac: 0xb8ac6f2f244a    sid: 0x24
user_len: 5             user_name: user1

root@juson:~# pppoe 0 num
------
root@juson:~# cdma 0 172.28.120.5 172.28.0.11 2
s_ip: 0xac1c7805         d_ip: 0xac1c000b
key: 2                   user_ip: 0x0a71c2e8
msid: 1460036060066514
root@juson:~# cdma 0 10.113.194.232
s_ip: 0x00000000         d_ip: 0x00000000
key: 0                   user_ip: 0x0a71c2e8
msid: 1460036060066514

root@juson:~# /tmp/cdma 0 num
pdsn_nodes: 1    ip_nodes: 1


------
root@juson:~# gtp 0 10.186.122.194 221.177.196.96 06002317
User Ip: 0x0aba7ac2
GGSN Ip_u: 0xddb1c460
GGSN teid_u: 0x06002317

User Imsi: 0x460021271119815f

root@juson:~# gtp 0 num
sgsn_nodes: 0   ggsn_nodes: 7751        ip_nodes: 7751
------
root@juson:~# /tmp/gn 0 --imei 8604117003250278
ip_idx:858      imsi_idx:601    imei_idx:33536  msisdn_idx:295448
imsi:460021271119815f   imei:8604117003250278   msisdn:15127194983f     apn:CMWAP
lac: 12552      ci: 51360       rat: 2
user_ip: 0aba7ac2       sgsn_ip_c:ddb1c410      sgsn_ip_u: ddb1c412      ggsn_ip_c:ddb1c460     ggsn_ip_u:ddb1c460
sgsn_teid_c:8d0000c4    sgsn_teid_u:363b9e85    ggsn_teid_c:03290e32    ggsn_teid_u:06002317

```
root@juson:~# /tmp/gn  0 --msisdn 15127194983
---------------------------------------------
ip_idx:858      imsi_idx:601    imei_idx:33536  msisdn_idx:295448
imsi:460021271119815f   imei:8604117003250278   msisdn:15127194983f     apn:CMWAP
lac: 12552      ci: 51360       rat: 2
user_ip: 0aba7ac2       sgsn_ip_c:ddb1c410      sgsn_ip_u: ddb1c412      ggsn_ip_c:ddb1c460     ggsn_ip_u:ddb1c460
sgsn_teid_c:8d0000c4    sgsn_teid_u:363b9e85    ggsn_teid_c:03290e32    ggsn_teid_u:06002317
---------------------------------------------
root@juson:~# /tmp/gn 0 num                  
[  565.470366] copy_user_buffer: No copy done, status: 3 (0x3)
ERROR: sent gn request fail!
```

ip_idx: 0        psdn_idx: 947676
s_ip: 0xac1c7805         d_ip: 0xac1c000b
key: 2                   user_ip: 0x00000000
msid: 14 60 03 60 60 06 65 14
bsid: 37AD000D0D92

3 + 8 + 12

0x0000:  0018 821d 0c53 001b 21a7 65f5 9100 1733  .....S..!.e....3
0x0010:  3741 4430 3030 4430 4439 3214 6003 6060  7AD000D0D92.`.``
0x0020:  0665 1408 0045 0000 2e00 0040 0040 2f6a  .e...E.....@.@/j
0x0030:  58ac 1c00 0bac 1c78 0520 0088 8100 0000  X......x........
0x0040:  027e ff03 8021 02                        .~...!.

22:07:47.737282 08:19:a6:3e:6d:81 > 00:25:9e:03:9b:b6, ethertype VMAN (0x9100), length 117: 
	0x0000:  0025 9e03 9bb6 0819 a63e 6d81 9100 0f87  .%.......>m.....
	0x0010:  54ba 5f46 0009 4211 8104 9f08 0045 0000  T._F..B......E..
	0x0020:  5819 4800 003f 11a5 1edd b180 e8dd b180  X.H..?..........
	0x0030:  e308 6808 6800 4400 0030 ff00 343e 191c  ..h.h.D..0..4>..
	0x0040:  2f45 0000 3441 f140 003b 0697 f20a 0000  /E..4A.@.;......
	0x0050:  ac0a 8f50 a600 50e5 97b6 7993 816c 13dc  ...P..P...y..l..
	0x0060:  0480 1102 bb6d 3d00 0001 0108 0a22 8f8c  .....m=......"..
	0x0070:  f500 b378 b0
	
	3 + 4 + 8
root@juson:~# gn --imsi 460009421181049
---------------------------------------------
ip_idx:295692   gsn_idx: 262543 imsi_idx:267014
imei_idx:88     msisdn_idx:266587
imsi:460009421181049f   imei:8635220100185278   msisdn:13618802411f     apn:CMWAP
lac: 34644      ci: 47711       rat: 2
user_ip: 0a8f50a6       sgsn_ip_c:ddb180e3      sgsn_ip_u: ddb180e3      ggsn_ip_c:ddb180e8     ggsn_ip_u:ddb180e8
sgsn_teid_c:86ac5820    sgsn_teid_u:3e191c2f    ggsn_teid_c:0adf6377    ggsn_teid_u:030078c2

	0x0000:  0025 9e03 9bb6 0819 a63e 6d81 9100 0f87  .%.......>m.....
	0x0010:  54ba 5f46 0009 4211 8104 9f
										08 0045 0000  T._F..B......E..
	0x0020:  5819 4800 003f 11a5 1edd b180 e8dd b180  X.H..?..........
	0x0030:  e308 6808 6800 4400 0030 ff00 343e 191c  ..h.h.D..0..4>..
	0x0040:  2f45 0000 3441 f140 003b 0697 f20a 0000  /E..4A.@.;......
	0x0050:  ac0a 8f50 a600 50e5 97b6 7993 816c 13dc  ...P..P...y..l..
	0x0060:  0480 1102 bb6d 3d00 0001 0108 0a22 8f8c  .....m=......"..
	0x0070:  f500 b378 b0                             ...x.
kkkkkk^[^[

2001:da8:3:10d::3

typedef struct _pkthdr_fivetuples_info{
#ifdef CONFIG_ENABLE_IPV6
	union{
		struct {
			union{
				uint8_t sip6_8[16];
				uint16_t sip6_16[8];
				uint32_t sip6_32[4];
				uint64_t sip6_64[2];
			};
			union {
				uint8_t dip6_u8[16];
				uint16_t dip6_u16[8];
				uint32_t dip6_u32[4];
				uint64_t dip6[2];
			};
		};
		struct {
			uint8_t __pad0[24];
			uint32_t sip;
			uint32_t dip;
		};
		struct {
			uint64_t __pad[3];
			uint64_t ip;
		};
		uint64_t ip6[4];
	};
#else
	union{
		struct{
			uint32_t sip;
			uint32_t dip;
		};
		uint64_t ip;
	};
#endif
	union{
		struct{
			uint64_t sp:16,
				 dp:16,
				 proto:8,
				 acl_grp_id: 8,
				 flag_ipv:1,
				 rsv0:15;
		};
		uint64_t port;
	};
}pkthdr_info_struct;


#ifdef CONFIG_ENABLE_IPV6
				pkthdr_info_struct pkthdr_tmp[2];
				pkthdr_tmp[0].sip6_64[0] = dpp->pkthdr.sip6_64[0];
				pkthdr_tmp[0].sip6_64[1] = dpp->pkthdr.sip6_64[1];
				pkthdr_tmp[0].dip6_64[0] = dpp->pkthdr.dip6_64[0];
				pkthdr_tmp[0].dip6_64[1] = dpp->pkthdr.dip6_64[1];
				pkthdr_tmp[0].port = (((uint64_t)dpp->pkthdr.sp)<<48)|\
						     (((uint64_t)dpp->pkthdr.dp)<<32)|\
						     ((uint64_t)dpp->pkthdr.proto)<<24;

				pkthdr_tmp[0].sip6_64[0] = dpp->pkthdr.dip6_64[0];
				pkthdr_tmp[0].sip6_64[1] = dpp->pkthdr.dip6_64[1];
				pkthdr_tmp[0].dip6_64[0] = dpp->pkthdr.sip6_64[0];
				pkthdr_tmp[0].dip6_64[1] = dpp->pkthdr.sip6_64[1];
				pkthdr_tmp[0].port = (((uint64_t)dpp->pkthdr.dp)<<48)|\
						     (((uint64_t)dpp->pkthdr.sp)<<32)|\
						     ((uint64_t)dpp->pkthdr.proto)<<24;
				dpp->idx_load_balance = hw_crc_hash
					((uint64_t *)&pkthdr_tmp[0], 5)
					+ hw_crc_hash((uint64_t *)&pkthdr_tmp[1], 5);
#endif
