all: test 
test: testclean 
	mipsel-linux-gcc -mips32 -EL -c test.S -o test.o 
	mipsel-linux-ld -mips32 -EL -T test.ld test.o -o test 
	mipsel-linux-objcopy -O binary test test.bin 
testclean: 
	-rm -f test 
	-rm -f test.bin 
testrun: 
	qemu-system-mipsel  -kernel test 
