## MIPS 通用寄存器
MIPS有32个通用寄存器（$0-31):
> 数量分布:1 1 2 4 8 8 2 1 1 1 1
<table>
	<tr>
		<td>Register</td>
		<td>Name</td>
		<td>Usage</td>
	</tr>
	<tr>
		<td>$0</td>
		<td>$zero</td>
		<td>常量0 (constant value 0)</td>
	</tr>
	<tr>
		<td>$1</td>
		<td>$at</td>
		<td>保留给汇编器(Reserved for assembler)</td>
	</tr>
	<tr>
		<td>$2 - 3</td>
		<td>$v0 - v1</td>
		<td>函数调用返回值(values for results and expression evaluation)</td>
	</tr>
	<tr>
		<td>$4 - 7</td>
		<td>$a0 - a3 </td>
		<td>函数调用参数(arguments)</td>
	</tr>
	<tr>
		<td>$8 - 15</td>
		<td>$t0 - t7</td>
		<td>暂时的(或随便使用的)</td>
	</tr>
	<tr>
		<td>$16 - 23</td>
		<td>$s0 - s7</td>
		<td>保存的(如果用，需要SAVE/RESTORE的)</td>
	</tr>
	<tr>
		<td>$24 - 25</td>
		<td>$t8 - t9</td>
		<td>暂时的（或随便使用的）</td>
	</tr>
	<tr>
		<td>$28</td>
		<td>$gp</td>
		<td>全局指针(Global Pointer)</td>
	</tr>
	<tr>
		<td>$29</td>
		<td>$sp</td>
		<td>堆栈指针(Stack Pointer)</td>
	</tr>
	<tr>
		<td>$30</td>
		<td>$fp</td>
		<td>帧指针(Frame Pointer)</td>
	</tr>
	<tr>
		<td>$31</td>
		<td>$ra</td>
		<td>返回地址(Return Address)</td>
	</tr>
</table>

上面没有寄存器26,27(k0, k1)为操作系统/异常处理，至少要保留一个。

异常（或中断）是一种不需要在程序中显示调用的过程。MIPS有个叫异常程序计数器(exception program counter,EPC)的寄存器，属于CP0寄存器，用于保存造成异常的那条指令的地址。

查看控制寄存器的唯一方法是把复制到通用寄存器里，指令mfc0(move from system control)可以将EPC中的地址复制到某个寄存器中。

通过跳转语句(jr)，程序可以返回到造成异常的那条指令处继续执行。MIPS程序员必须保留两个寄存器k0和k1，供操作系统使用。
