	.file	1 "start.s"
	.section .mdebug.eabi64
	.previous
	.section .gcc_compiled_long64
	.previous
	.gnu_attribute 4, 3
	.rdata
	.align	3

	.text
	.align	2
	.globl	main
	.ent	main
main:
	.mask	0xc0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
        lui	$gp,0x1201
        daddiu	$gp,$gp,-28736
        move	$ra,$zero
        move	$s8,$sp
        daddi	$a0,$s0,0
        lui	$t9,0x1200
        daddiu	$t9,$t9,4384
	jal	write_char
	.set	macro
	.set	reorder
	.end	main
write_char:
	li	$a0, 's'
	li	$a1, 'q'
	li	$a2, 'm'
	addi	$9, $zero, 10000
	lui	$9, 0x8001
	ori	$9, 0x1800
	dsll	$9, 16
	dsll	$9, 16
	ori	$9, 0x0800
	ld	$10, 0x28($9)
	and 	$10, 0x20
	nop
	sd	$a0, 0x40($9)
	sd	$a1, 0x40($9)
	sd	$a2, 0x40($9)
