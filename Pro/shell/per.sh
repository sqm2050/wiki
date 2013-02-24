#!/bin/bash
# echo -e must be used in bash
POS=40
#for ((i=0; i<=100; i++)) 
#sh does not support
rm ./nohup.out 2>/dev/null

echo 
i=1
if [ $2 -eq 0 ]; then
	time=101
	nohup tcpreplay -i eth1 -l $2 -t  $1 &
	echo 
	echo -n "Senting Packet for 120s  ... "
	while [ $i -lt $time ]
	do 
		echo -ne "\\033[${POS}G $i % completed"
		sleep 1.2
		i=`expr $i + 1`
	done

	echo -ne "\n"
	pid=`ps -ef | grep $1 | grep tcpreplay|awk '{print $2}'`
	kill -9 $pid >/dev/null 2>&1
	sleep 2

	lines=`cat ./nohup.out |grep $1| wc -l`
	echo "共发送 $lines 个报文"
else
	tcpreplay -i eth1 -l $2 -t  $1 &
	echo -e "发送 $2 个报文\n"
fi
echo -ne "\n"
