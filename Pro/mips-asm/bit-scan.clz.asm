main:
	la	$a0,	str_1
	li	$v0,	4
	syscall
	li 	$v0, 5	# load syscall read_int into $v0
	syscall
	move	$t2, $v0

	lui	$5, 32768	# $5 = 0x8000 0000;
	li	$t1, 1		# $t1 = 1

	clz	$s1, $t2
	li	$s2, 32
	sub	$t1, $s2, $s1
	j	finish		# 跳转
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
