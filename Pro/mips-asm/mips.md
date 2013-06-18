## bit-scan
![结果图](https://raw.github.com/sqm2050/wiki/master/Pro/mips-asm/bit-scan.png)
```
main:
	la	$a0,	str_1
	li	$v0,	4
	syscall
	li 	$v0, 5	# load syscall read_int into $v0
	syscall
	move	$t2, $v0

	lui	$5, 32768	# $5 = 0x8000 0000;
	li	$t1, 1		# $t1 = 1

C:	and	$6, $t2, $5	# $6 = $t2 | 0x8000 0000;
	bne	$5, $6, L1	# if (0x8000 0000 != $6) goto L1
	j	finish		# 跳转
L1:	addi	$t1, $t1, 1	# $t1++;
	sll	$t2, $t2, 1	# $t2 << 1;
	bne	$t1, 33, C
finish:
	la	$a0,	str_2
	li	$v0,	4
	syscall
	move 	$a0, $t1
	li	$v0, 1
	syscall
	la	$a0,	str_3
	li	$v0,	4
	syscall
	li	$v0, 10
	syscall
	.data
str_1:
	.asciiz "输入要扫描的数："
str_2:
	.asciiz "扫描到第一个被置位的位置："
str_3:
	.asciiz "\n"
```
