### 时钟:
* Core Clock Frequency = PLL_REF_CLK × [C_MUL] = 50 MHz × [C_MUL]
* Coprocessor Clock Frequency = PLL_REF_CLK × [PNR_MUL] = 50 MHz × [PNR_MUL]

### Coherent Multicore and I/O L2/DRAM Sharing:
	shared main memomry(implemented via the level-2 cache and the DRAM)is the primary communication media for bulk(大块) transfers in the CN63XX.

### In-line Packet-Processing Hardware Acceleration:
The CN63XX in-line packet-processing hardware units complete the follwing tasks before a core receives a packet:
* Allocate DRAM buffers to hold the packet bytes.
* Send packet data into these DRAM buffers via DMA operations in a format convenient to upper-level software.This can enable copy-free core software.		upper-level:上层
* Parse the layer-two/IP packet,checking for common exception conditions.This is done for every ingress packet.The layerfour TCP/UDP checksum checks are included,among many others.
* Perform optional mutual exclusion via a programmable 7-tuple classification.
	> mutual:共有的，共同的。classification:分类，分级
	
### When software has finished processing the packet, CN63XX in-line hardware performs the following tasks:
* DMA the packet-send command from the selected output queue(and free the available queue space)
* DMA packet data from L2/DRAM.This includes multiple modes to gather noncontiguous packet data.
* Generate the TCP/UDP checksum.(CN63XX can perform this very efficiently;	the packet data is read out of L2/DRAM memory only once to both calculate the checksum and send the packet off-chip)
	> efficiently:高效地
* Free the DRAM buffers

### Essential Quality of Service (QoS) Functions Implemented in Hardware:
> CN63XX has some essential QoS capabilities implemented directly in hardware:
* The hardware has eight separate input work queues.
* The in-line input packet processing hardware can classify packets into one of the eight input work queues using default values,DSA/VlAN priorities and IP Diffserv values,configurable on a per-port basis.					
	> diffserv:差异式服务
* The in-line input packet processing hardware may discard an input packet before buffering and presenting it to a core.The hardware implements both a random early discard (RED) algorithm and a threshold algorithm to decide when or if to discard and input packet.The RED-like algorithm can be configured 
* Each output port can be configured to have multiple queues.The queues can be configured with different priorities.The hardware implements both static priority and weighted round-robin. 							
	> priority:优先级
	> weigthed round-robin:加权循环

## Coprocessor Accelerators:
* Hyper Finite Automata(HFA)/Deterministic Finite Automata(DFA):string-matching with the attached DRAM(NOTE:in the rest of the manual,these terms will be used interchangeably).								
	> interchangeable:可交替的，可互换的。
* Compression/Decompression(ZIP):hardware-acceleration based on standard inflate/deflate algorithms supporting GZIP/PKZIP and variant protocols.			
	> inflate:使膨胀,膨胀。
	> deflate:使缩小,缩小。
* Timer(TIM):timer support is particularly useful for TCP implementations.
* RAID/De-Dup(RAD):optional hardware acceleration support for RAID 3/4/5/6
* True Random Number Generator(RNG)

### CMI:coherent memory interconnect 
	> interconnect:使互相连接.

### CPU Visible State Resident in each cnMIPS II Core:
```
	CRCIV<31:0> IV:interrupt vector
```

### CSRs:Configuration and Status Registers
> CN63XX has many CSRs to control and configure the on-chip hardware.
Each configuration register can be accessed by one or more of the following mechaisms:
* cores using MFC0/MTC0 instructions
* cores using MFC2/MTC2 instructions
* cores using ordinary load/store instructons to I/O physical addresses
* cores using indirect windowed accesses to PCIe configuration registers via the PEM*_CFG_WR and PEM*_CFG_RD CSRs.
* cores using indirect windowed accesses to SRIO maintenance registers via the SRIO*_MAINT_OP and SRIO*_MAINT_RD_DATA CSRs.
* remote EJTAG/JTAG device using the EJTAG/JTAG TAP interface.
* remote PCIe/SRIO host using direct PCIe configuration accesses/SRIO maintenance accesses.
* remote host using direct PCIe/SRIO memory space BAR0 accesses.
* remote PCIe/SRIO host using indirect windowed accesses to I/O physical addresses via the SLI_WIN_RD_ADDR,SLI_WIN_RD_DATA,SLI_WIN_WR_ADDR, SLI_WIN_WR_DATA, and SLI_WIN_WR_MASK_CSRs.

P88:instruction set summary

SEGBITS = 49, as per the MIPS specifications

KSEG3的范围0xFFFF FFFF FFFF 8000到0xFFFF FFFF FFFF BFFF称作CVMSEG段，两部分：
* CVMSEG LM = 0xFFFF FFFF FFFF 8000 到 0xFFFF FFFF FFFF 9FFF
* CVMSEG IO = 0xFFFF FFFF FFFF A000 到 0xFFFF FFFF FFFF BFFF
 
## Chapter 3	Coherent Memory Interconnect and Level-2 Cache Controller
CMI Buses:
The CMI is comprised of six buses:
* the address/command bus - ADD	
* the store data bus	- STORE
* the commit/response control bus - COMMIT
* the fill data bus	- FILL
* the I/O command/data bus - IOC
* the I/O response/data bus - IOR
 
The CMI interface is 640bits wide,the LMC DRAM interface is 256 bits wide,and the internal L2 cache data interfaces are 256 bits in each quad,a total of 1024 bits including all quads.
	
All data transfers between the L2C and the LMC move full 128-byte cache blocks.

## Chapter 26	Boot Bus
> <m:n>的正确理解：n是从0值开始的，m其实是从低位到高位数的第m+1位。

boot-bus提供一个连接到非易失的装置（像NOR、NAND）的通用总线，而且提供初始化启动地址。

大端boot bus包含：
* 八位片选信号
* 32地址/数据总线
* 可编程8/16位数据宽度
	* 8位：BOOT_AD<31:24>是数据线
	* 16位：BOOT_AD<31:24>是最高有效位，BOOT_AD<23:16>是最低有效位

### 地址
boot bus物理地址范围是0x1 0000 0000 0000 到 0x1 0000 FFFF FFFF.

> 0x1000 0000到0x1FFF FFFF的物理地址空间也转换到0x1 0000 1000 0000 - 0x1 0000 1FFF FFFF

异常向量地址：
<table>
	<tr>
		<th>Vector Address(PA)</th>
		<th>Comment</th>
	</tr>
	<tr>
		<td>0x1 0000 1FC0 0000</td>
		<td>当一个核被重置，软重置，或遇到一个不可屏蔽的中断异常的时候，这个核会指向这个地址</td>
	<tr>
	<tr>
		<td>0x1 0000 1FC0 0480</td>
		<td>如果EJTAG TAP寄存器ECR域没有被置位，一个核遇到所有的debug异常都会指向这个物理地址</td>
	<tr>
</table>

其他核心异常在一些特定的情况下也能指到boot-bus的地址区域，但是可以通过配置避免（如果需要的话---清楚CP0寄存器Status[BEV]位 ），但是上面的两个地址不能通过配置避免。

每个本地内存区可以保持32条指令在这些向量地址，如果需要更多的指令，异常捕获必须这32条指令之内跳转到L2/DRAM上。

### 地址匹配和地址区域

