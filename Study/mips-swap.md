void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

Disassembly of section .text:
00000000 <swap>:
   0:	67bdffe0 	daddiu	sp,sp,-32	# sp -= 32;
   4:	ffbe0018 	sd	s8,24(sp)		# 24(sp) = fp;
   8:	03a0f02d 	move	s8,sp		# s8 = sp;

   c:	ffc40008 	sd	a0,8(s8)	# 8(s8) = a;
  10:	ffc50010 	sd	a1,16(s8)	# 16(s8) = b;

  14:	dfc20008 	ld	v0,8(s8)	# v0 = a;
  18:	8c420000 	lw	v0,0(v0)	# v0 = *a;
  1c:	afc20000 	sw	v0,0(s8)	# 0(s8) = *a;

  20:	dfc20010 	ld	v0,16(s8)	# v0 = b;
  24:	8c430000 	lw	v1,0(v0)	# v1 = *b;
  28:	dfc20008 	ld	v0,8(s8)	# v0 = a;
  2c:	ac430000 	sw	v1,0(v0)	# *a = *b;

  30:	dfc30010 	ld	v1,16(s8)	# v1 = b;
  34:	8fc20000 	lw	v0,0(s8)	# v0 = *a;
  38:	ac620000 	sw	v0,0(v1)	# *b = *a;
  3c:	03c0e82d 	move	sp,s8	# sp = s8;
  40:	dfbe0018 	ld	s8,24(sp)	# s8 = 24(sp);
  44:	67bd0020 	daddiu	sp,sp,32# sp += 32;
  48:	03e00008 	jr	ra		# 返回
  4c:	00000000 	nop
