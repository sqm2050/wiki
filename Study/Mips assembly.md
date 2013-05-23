MIPS R2000 Instruction Formats
_____________________________________________________________
		6 bits	5	5	5	5	6
Register	op	reg1	reg2	des	shfit	funct
Immediate	op	reg1	reg2	16-bit constant
Jump		op	26-bit 		constant
-------------------------------------------------------------
If the op field is 0, then the instruction is a register instruction,
which generally perform an arithmetic or logical operations. The funct
field specifies the operation to perform, while the reg1 and reg2 
represent the registers to use as operands, and the des field represents
the register in which to store the result. For example, the 32-bit 
hexadecimal number 0x02918020 represents, in the MIPS instruction set,
the operation of adding the contents of registers 20 and 17 and placing 
the result in register 16.
Field  op 	reg1 	reg2 	des 	shift 	funct
Width 	6 bits 	5 bits 	5 bits 	5 bits 	5 bits 	6 bits
Values 0  	20  	17  	16  	0  	add
Binary 000000 	10100 	10001 	10000 	00000 	100000
     0x0   2      9      1      8   0      2      0
If the op field is not 0, then the instruction may be either an immediate 
or jump instruction, depending on the value of the op field.

li (load immediate value) get constant into register.
#begin of add.asm
main:
	li 	$t1, 1		#load 1 into register t1
	add 	$t0, st1,2 	# register t0 = register t1 + 2

	li	$v0, 10		#syscall code 10 is for exit
	syscall			#make the syscall
#end of add.asm
program execution begins at the location with the label main. A label is a
symbolic name for an address in memroy.Labels must be thefirst item on a
line followed by a colon.
