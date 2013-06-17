# Fundamentals of Computer Design
```
	And now for something completely different
					--- Monty Python's Flying Circus
```

## 1.1 Introduction
Computer technology has made incredible progress in the past half century.In 1945,there were no stored-program computers.

Today,a few thousand dollars will purchase a personal computer that has more performance,more main memory,and more disk  storage than a computer bought in 1965 for $1 million.This rapid rate of improvement has come both from advances in the technology used to build computers and from innovation in computer design.

While technological improvements have been fairly steady,progress arising from better computer architectures has been much less consistent.

> consistent:someone who is `consistent ` always behaves in the same way,has the same attitudes towards people or things,or achieves the same level of success in something.

During the first 25 year of electronic computers,both forces made a major contribution;but beginning in about 1970,computer designers became largely dependent upon intergrated circuit technology.During the 1970s,performance continued to improve at about 25% to 30% per year for the mainframes and minicomputers that dominated the industy.

> mainframe:A `mainframe` or `mainframe computer` is a large powerful computer which can be used by many people at the same time and which can do very large or complicated tasks.

The late 1970s saw the emergence of the microprocessor.The ablility of microprocessor to ride the improvements in integrated circuit technology more closely than the less integrated mainframes and minicomputers led to a higher rate of improvement---roughly 35% growth per year in performance.

This growth rate,combined with the cost advantages of a mass-produced microprocessor,let to an increasing fraction of the computer business being based on microprocessors.In addition,two significant changes in the computer marketplace made it easier than ever before to be commercially successful with a new architecture.First,the virtual elimination of assembly language programming reduced the need for object-code compatibility.Second,the creation of standardized,vendor-independent operating systems,such as UNIX,lowered the cost and risk of bringing out a new architecture.These changes made it possible to successively develop a new set of architectures,called RISC architectures,in the early 1980s.Since the RISC-based microprocessors reached the market in the mid 1980s,these machines have grown in performance at an annual rate of over 50%.

Prior to the mid 1980s,microprocessor performance grouth was largely technology driven and averaged about 35% per year.The increase in growth **since then** is attributable to more advanced architectural ideas.

The effect of this dramatic growth rate has been twofold:
* First,it has significantly enhanced the capability available to computer users.As a simple example,consider the highest-performance workstation announced in 1993,an IBM Power-2 machine.Compared with a CRAY Y-MP supercomputer introduced in 1988(probaly the fastest machine in the world at that point),the worstation offers comparable performance on many floating-point programs and better performance on integer programs for a price that is less than one-tenth of the supercomputer!
* Second,this dramatic rate of improvement has led to the dominance of microprocessor-based computers across the entire range of the computer design.Work-stations and PCs have emerged as major products in the computer industy.Minicomputers,which were traditionally made from off-the-shelf logic or form gate arrays,have been replaced by servers made using microprocessors.Mainframes are slowly being replaced with multiprocessors consisting of small numbers of off-the-shelf microprocessors.Even high-end supercomputers are being built with collections of microprocessors.

> High-end:`High-end` products,especially electronic products,are the most expensive of their kind.

Freedom from compatibility with old designs and the use of microprocessor technology led to a renaissance in computer design,which emphasized both architectural innovation and efficient use of technology improvements.This renaissance is responsible for the higher performance growth--- a rate that is unprecedented in the computer industy.

> If something is `unprecedented`,it has never happened before

This text is about the architectural ideas and accompanying compiler improvements that have made this incredible growth rate possible.

## 1.2 The task of a computer designer
The task the computer designer faces is a complex one: Determine what attributes are important for a new machine,then design a machine to maximize performance while staying within cost constraints.

In this book the term __instruction set architecture__ refers to the actual programmer-visible instruction set.The instruction set architecture serves as the boundary between the software and hardware.

Often a line of machines contains machines with identical instruction set architectures and nearly identical organizations,but they differ in the detailed hardware implementation.

In this book the world architecture is intended to cover all three aspects of computer design---instruction set architecture,organization,and harfware.
## 1.3 Technology and computer usage trends
Underestimating address-space growth is often the major reason why an instruction set architecture must be abandoned.

The development of compiler technology for parallel machines is likely to have a large impact in the future.

# 2 Instruction Set Principles and Examples
## 2.1 Introduction
We begin by exploring how instruction set architectures can be classified and analyzed.

## 2.2 Classifying instruction set architectures
The type of internal storage in the CPU is the most basic differentication,so in this section we will focus on the alternatives for this portion of the arhitecture.

Operands may be named explicitly or implicitly:The operands in a stack architecture are implicitly on the top of the stack,in an accumulator architecture one operand is implicitly the accumulator,and general-purpose register architectures have only explicit operands---either registers or memory locations.

One can access memory as part of any instruction,called __register-memory__ architecture,and one can access memory only with load and store instructions,call __load-store__ or __register-register__ architecture.A third class,not found in machines shipping today,keeps all operands in memory and is called a __memory-memory__ architecture.

<table>
	<tr>
		<th>Stack</th>
		<th>Accumulator</th>
		<th>Register(register-memory)</th>
		<th>Register(load-store)</th>
	</tr>
	<tr>
		<td>Push A</td>
		<td>Load A</td>
		<td>Load R1, A</td>
		<td>Load R1, A</td>
	</tr>
	<tr>
		<td>Push B</td>
		<td>Add B</td>
		<td>Add R1, B</td>
		<td>Load R2, B</td>
	</tr>
	<tr>
		<td>Add</td>
		<td>Store C</td>
		<td>Store C, R1</td>
		<td>Add R3, R1, R2</td>
	</tr>
	<tr>
		<td>Pop C</td>
		<td> </td>
		<td> </td>
		<td>Store C, R3</td>
	</tr>
</table>
**Figure 2.1 The code sequence for C = A + B for four instruction sets.It is assumed that A,B,and C all belong in memory and that values of A and B cannot be destroyed.**

how many registers are sufficient?The answer of course depends on how they are used by the compiler.Most compilers reserve some registers for expression evalution,use some for parameter passing,and allow the remainder to be allocated to hold variables.

An ALU instruction has two or three operands,and the number of memory operands supported by a typical ALU instruction may vary from none to three.So there are seven possible combinations: 2 - 0, 2 - 1, 2 - 2;3 - 0, 3 - 1, 3 - 2, 3 - 3.

<table>
	<tr>
		<th>Number of memory addresses</th>
		<th>Maximum number of operands allowed</th>
		<th>Examples</th>
	</tr>
	<tr>
		<td>0</td>
		<td>3</td>
		<td>SPARC,MIPS,Precision Architecture,PowerPC,ALPHA</td>
	<tr>
	<tr>
		<td>1</td>
		<td>2</td>
		<td>Intel 80x86,Motorola 68000</td>
	</tr>
	<tr>
		<td>2</td>
		<td>2</td>
		<td>VAX</td>
	</tr>
	<tr>
		<td>3</td>
		<td>3</td>
		<td>VAX</td>
	</tr>
</table>

GPR architecture:general-purpose register.

DLX

## 2.3 Memory Addressing
### Interpreting Memory Addresses
How is a memory address interpreted?That is,what object is accessed as a function of the address and the length?All the instruction sets discussed in this book are byte addressed and provide access for byte(8bits),half words(16bits),and words(32bits).Most of the machines also provide access for double words(64bits).

Why would someone design a machine with alignment restrictions?Misalignment causes hardware complications,since the memory is typically aligned on a word or double-word boundary.A misaligned memory access will,therefore,take multiple aligned memory references.Thus,even in machines that allow misaligned access,programs with aligned accesses run faster.

### 2.3.1 存储器操作数
MIPS指令中的算术运算操作只作用于寄存器，因此MIPS必须有在存储器和寄存器之间传送数据的指令，这些指令叫做数据传送指令。

把数据从存储器复制到寄存器的数据传送指令，通常叫做取指令（load）。
> 取指令的格式：操作符名称后面紧跟存放数据的寄存器，然后是用来访问存储器的常数和一个寄存器。
> 指令的常数部分和第二个寄存器中内容相加即得存储器地址。实际的MIPS取指令的名字为lw，表示取字（load word）。

常数作为操作数进行运算时，会避免使用`lw`指令，而是使用立即数指令如：立即数加
```
	addi $s3, $s3, 4	#$s3 =#s3 + 4
```

#### 对照一个c程序
c代码：
```
void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
```
mips汇编：
```
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
  48:	03e00008 	jr	ra			# 返回
  4c:	00000000 	nop
 ```
##### 进入函数：
* 栈指针偏移
* 保存帧指针到栈
* 复制栈指针到帧指针寄存器
 
然后使用帧指针寄存器，代替栈指针进行存取操作，函数进行期间帧指针是不变的，栈指针一直不会使用

##### 函数退出：
* 把帧指针再复制回栈指针
* 在栈中load帧指针到帧指针寄存器
* 把栈指针偏移回去

疑问是：为什么多余的使用帧指针寄存器，进行栈的存取操作，而不是直接使用栈指针，反正帧指针也不会改变。(可以应付大于16立即数的处理？)
<br>
由于MIPS支持负值常数，所以就没必要在MIPS中支持减立即数的指令了。

### R型指令：
> 6 * 2 + 5 * 4 = 32
```
op	rs	rt	rd	shamt	funct
6	5	5	5	5		6
```
MIPS指令有R型(寄存器)，I型(立即数).I型指令解决使用R型指令取值指令立即数小的限制。
> 如：取字指令一般需要两个寄存器一个常数，这样立即数就限制为2^5(32)大小。

### I型指令
> 6 + 5 * 2 + 16 = 32
为了保证指令长度都一样，但不同的指令采用不同的指令格式。
> 优秀的设计需要适当的折中。
```
op	rs	rt	constant or address
6	5	5	16
```
16位字段address使得取字指令可以取任何基址偏移+-2^15(32768)字节，+-2^13(8192)个字.
> 在这种格式下使用超过32个寄存器也是困难的，因为rs,rt都要加一位,导致一个字的指令是不够的。

虽然多种指令格式使硬件变得更为复杂，但是保持指令格式基本一致可以降低复杂程度。
> 如：R型和I型指令的前3个字段长度相等，并且名称一样。

指令格式由第一个字段的值来区分：每种格式的第一个字段（op）都被分配了一套不同的值。

当前的计算构造基于两个关键性的原则：
* 指令以数据形式表示
* 和数据一样，程序存储在存储器中，并且可以读写
