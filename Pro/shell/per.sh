#!/bin/bash
# echo -e must be used in bash
POS=40
#for ((i=0; i<=100; i++)) 
#sh does not support
rm ./nohup.out 2>/dev/null
nohup tcpreplay -i eth1 -l 0 -t  $1 &

echo 
echo -n "Senting Packet for 120s  ... "
i=1
while [ $i -lt 120 ]
do 
	echo -ne "\\033[${POS}G $i % completed"
	sleep 1.2
	i=`expr $i + 1`
done
echo -ne "\n"

pid=`ps -ef | grep $1 | grep tcpreplay|awk '{print $2}'`
kill -9 $pid
sleep 2
echo Kill ok

lines=`cat ./nohup.out |grep $1| wc -l`
echo "共发送 $lines 个报文"
