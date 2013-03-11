.file 1
 "nonleaf.c"
.section .mdebug .abi32
.previous
.text
.align 2
.globl nonleaf
.set nomips16
.ent nonleaf
nonleaf:
.frame $sp,32,$31 # vars= 0, regs= 1/0, args= 24, gp= 0
.mask 0x80000000, -8
.fmask 0x00000000, 0
.set noreorder
.set nomacro
addiu
sw
move
addiu
sw
move
jal
move
$sp, $sp, -32
$31, 24($sp)
$2, $4
$3, $sp, 48
$3, 16($sp)
$4, $7
nested
$7, $2
lw
j
addiu
$31, 24($sp)
$31
$sp, $sp, 32
.set
 macro
.set
 reorder
.end
 noleaf
.ident
 "GCC:
 (GNU) 3.4.4 mipssde-6.03.01-20051114"

