#!/bin/bash
# echo -e must be used in bash
POS=40
#for ((i=0; i<=100; i++)) 
#sh does not support

i=1
time=101
while [ $i -lt $time ]
do 
	echo -n "\\033[${POS}G $i % completed"
	sleep 1.2
	i=`expr $i + 1`
done
