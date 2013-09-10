pvid set 	0		0			4032		1		1
		(switch device) (interface number) 	(PVID number) 	(force PVID) 	(nest PVID)
0:0-------0:5 ===> 0:27 ===> 56A
pvid set 0 0 4032 1 1
vlan add 0 4032
vlan add member 0 4032 0 0
vlan add member 0 4032 27 1
...
pvid set 0 5 4037 1 1
vlan add 0 4037
vlan add member 0 4037 5 0
vlan add member 0 4037 27 1

0:6------0:11 ===> 0:25 ===> 1:16 ===> 1:10 ===> 56A
pvid set 0 6 4038 1 1
vlan add 0 4038
vlan add member 0 4038 6 0
vlan add member 0 4038 25 1
vlan add 1 4038
vlan add member 1 4038 16 1	# 让报文在16出来回device 0的时候带着4038的tag
vlan add member 1 4038 10 1	# 报文从10口出来去56的时候带着4038的tag
....
pvid set 0 11 4043 1 1
vlan add 0 4043
vlan add member 0 4043 11 0
vlan add member 0 4043 25 1
vlan add 1 4043
vlan add member 1 4043 16 1
vlan add member 1 4043 10 1

0:12------0:17===> 0:26 ===> 1:12 ===> 1:22 ===> 56B
pvid set 0 12 4044 1 1
vlan add 0 4044
vlan add member 0 4044 12 0
vlan add member 0 4044 26 0
vlan add 1 4044
vlan add member 1 4044 12 1
vlan add member 1 4044 22 1
...
pvid set 0 17 4049 1 1
vlan add 0 4049
vlan add member 0 4049 17 0
vlan add member 0 4049 26 1
vlan add 1 4049
vlan add member 1 4049 12 1
vlan add member 1 4049 22 1

0:18------0:23===> 0:24 ===>56B
pvid set 0 18 4050 1 1
vlan add member 0 4050 18 0
vlan add member 0 4050 24 1
...
pvid set 0 23 4055 1 1
vlan add member 0 4055 23 0
vlan add member 0 4055 24 1

万兆光口：
pvid set 1 4 4056 1 1	#前面板24口
vlan add 1 4056
vlan add member 1 4056 4 0	#回流
vlan add member 1 4056 10 1	#保持tag

pvid set 1 0 4057 1 1	#前面板25口
vlan add 1 4057
vlan add member 1 4057 0 0
vlan add member 1 4057 22 1
