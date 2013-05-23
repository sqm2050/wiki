	OCTEON-Programmer's_Guide-The_Fundamentals
	OCTEON 程序员指南——基本原理
About This Book
This volume contains the following chapters:
	1.Introduction
	2.Packet flow
	3.Software Overview
	4.SDK Tutorial
	5.Software Debugging Tutorial [tju:'to:rial]指导手册
	6.OCTEON Application Performance Tuning Whitepaper
	7.Glossary
本卷包含以下章节：
	1.简介
	2.包流
	3.软件概览
	4.SDK指导手册
	5.软件调试手册
	6.OCTEON程序性能调整白皮书
	7.专业词典
The appendices relevant to a chapter are not collected at the end of the book,but instead are included with the corresponding chapter.
与章节有关的附属部分没有在书最后进行汇总，而是被包含在相应的章节。

The chapters should be read in order,except for the appendices.Each chapter buids on information provided in the previous chapter.
章节应该顺序阅读，除了附录。每个章节建立在前一个章节提供的信息。

If you have any suggestions for improvements(提高) or amendments(修正),or believe you have found errors in this publication,please notify(通知)us at oct-prog-guide@caviumnetworks.com

第一章 简介
Chapter 1: Introduction
This chapter provides an overview of Cavium Network's OCTEON processor family,and introduces key features provides by its members.
本章概述了OCTEON处理器家族，而且介绍了成员的关键特点。
本章也提供了一个对OCTEON部分处理器的优点简短的讨论。
1.集合了硬件加速
2.单核心（per-core）安全协处理器
3.集成的接口（相互交互）
4.专门的特殊指令
5.高级缓存-分层结构（Cache hierarchy）

第二章：包流
这一章对包处理单元卸下和协作多核去加速包流通过处理器做了详细介绍。还包括(Scheduling/Synchronization/and Order(SSO) Unit)安排、同步、命令单元具体的off loads the cores。
本章被分成以下一个部分：
包流概述：讨论一个典型的包流(包接收、处理、传送)，展示不同的功能模块怎样协同工作组成可信、快速的包处理流程。
加速包处理的特殊硬件特点：关键的包处理硬件加速特点将会被讨论。
1.包处理单元的分级结构和优先级
2.缓冲处理单元
3.包链接锁
4.包整理（packet order)单元
SSO,SSO提供不同与处理器的必须的能力，SSO是OCTEON的核心。因为SSO的重要性，本章剩下的部分介绍他的硬件加速特点，描述软件怎样利用他们。

第三章 软件概述
这一章提供OCTEON处理器软件相关话题的概述，包括软件体系结构，多核问题，scaling（比例变换）和内存管理。
本章介绍以下话题：
	cnMIPS核心
	simple executive API（HAL）---Hardware Abstraction Layer,硬件抽象层
	不同的运行时环境选择
	软件体系构架问题
	应用二进制接口支持
	工具集：交叉编译（cross-development）和原生工具链（Native Toolchains）
	物理地址映射和OCTEON处理器的缓存
	虚拟内存
	bootmem gloable memory
		--Bootmem
		1.usage
			Memory allocation before mem—allocator steup
			用于内分配在内存分配器装备之前
		2.bootmem disadvantage(bootmem 的缺点) 
			bootmem设计目标：于mem-buddy建立之前，提供简单的内存分配，因此，他的算法实现相对简单，并不追求性能。在mem-buddy建立时，会将所有未分配的memory释放，但由于已分配的内存在bootmem中以类似线性分配的方式分配，因此在回收未使用的bootmem时，就很有可能会产生memory fragment。
	共享内存
	bootloader
	software Development Kit code conventions SDK	不同的运行时环境选择
	Software Development Kit(SDK) code conventions SDK代码规范。
阅读SDK有关的章节，能帮住阅读这发现更多详细的信息。

The Simple Executive API is used to access the hardware units.
Simple Executive API also includes functions and macros for:
	• System memory allocation (bootmem)
	• Synchronization between cores
	• Spinlocks
	• Reader-writer locks
	• Atomic set, add, compare and store operations
	• Barrier functions
第四章 SDK指导手册
本章介绍SDK，通过上手透视，介绍安装SDK，还包含对嵌入式软件开发新手或者说linux新手有用的信息。
这章的上手部分有：
	系统管理任务
	连接开发目标系统
	查看目标板控制台输出
	搜集关键硬件信息
	安装SDK
	熟悉安装的SDK
	编译、运行一个SE-S程序（hello）
	运行hello在多核上
	编译和运行linux
	运行一个SE—UM例子（named—block）
	运行linux-filter，按照SE—S程序的形式（Hybrid system---混合系统）
	运行linux-filter，作为linux SE-UM程序
	运行linux-filter，作为多核上的SE—UM程序
	建立一个自定义程序

第五章 程序调试指导手册
本章提供信息和上手步骤帮助用户使用利用GDB调试嵌入式程序，包括：
	硬件配置
	单机调试，PCI开发目标调试
	多核调试
这个手册的上手部分：
	调试一个SE-S应用程序：hello
	调试linux内核
	调试SU-UM应用：name-block
	调试一个SE-S在OCTEON模拟器上
	在OCTEON模拟器上调试linux内核
	编译vmlinux，运行在模拟器上
	在模拟器上运行用户模式程序

关于OCTEON应用程序性能调整白皮书
	白皮书：介绍怎样利用OCTEON处理器独一无二的特点，优化程序的性能。
FAU:Fetch and Add Unit
FPA:Free Pool Allocator

Packet-Management Accelerators
报文处理加速自动的处理大量的报文，释放占用资源的任务，让核空闲。这些硬件单元负责报文接收，缓冲，缓冲管理，流分类，服务质量，还有传送过程。所有的这些功能是高度可配置的，而且可以自定义，通过使用软件访问配置寄存器。
报文管理加速器处理以下功能，不用通过核的协助：
	管理空报文数据列表和其他的缓冲
	报接受、传送通过网络或者PCI接口
	自动数据报文缓冲分配和释放，还有缓冲管理
	2-4曾报文头解析，除了检查还有校验和计算	
	7级报文分级，通过VLAN栈支持
	基于复合优先级RED算法的阻塞避免操作
		RED---Randon Early Dropping
	报文整理和安排是硬件自动管理的，不需要请求软件详细的软件锁
	严格优先权的通信量管理或者循环法对于跑传送
	8 levels of hardware-managed QoS for the input ports
	Up to 16 levels of hardware-managed QoS for each output port


/**
 *	07-Packet_Flow_Chapter
 *	第二章	包流
 */
	In this document,the word processor refers to the entire chip,with all of the differet functional hardware blocks including all of the cores on thip.
SSO The Schedule/Synchronization/Order(SSO) Unit:
	the SSO unit provides the following key functions:
	1)Schedule:Schedules packets to be processed based on Quality of Serivce(QoS) priority.根据QoS的优先权，分配报去处理。
	2)Synchronization:通过提供报文链接锁提供硬件支持的同步。这些锁可以用来保护危险的区域，或者连载报文传送在入口序列。
	3）Order:在所有的报文处理阶段维护入口序列。整理好的报文可能被成对的处理，但是SSO维护他们的传入序列。当他们转换到一个不同的处理阶段，或者请求一个报文链接锁，转换过程就根据传入序列进行.
2.Packet FLow Overview
The Simplified Packet Intreface pseudo block:
	RX---receive
	TX---transmit
	PKI---Packet Input
The Packet Input pseudo block: 
	IPD---Input Packet Data
	PIP---Packet Input Processor

	WQE---work queue entry
	RED---Random Early Dropping
	FPA---Free Pool Allocator
	PKO---Packet Output
	IPD-PIP-WQE(RED)-FPA
	A packet interface can be any of:XAUI,PCIe,SPI-4.2,PCI/PCI-X,SGMII,
	RGMII,GMII,or MII,etc.All of these interfaces can send packets to 
	the Packet Input Block. 这些接口组成RX TX口，然后交给PIP，IPD进行预
	处理.

  	Packet Flow
/**************************************************************************
    IOBI 1     PIP compute 2 			FPA	allocate 3
RX  --->Input Packet Data(IPD) Unit --- WQE Buffer & Packet Data Buffer --- 
     			
	L2/DRAM(DMA via IPDB) 4			SSO 5
IPD writes WQE & Packet Data Buffer --- IPD add the WQE Pointer to the app-
ropriate QoS queue
      
get WQE pointer from SSO 6 	process,R/W L2/DRAM 7	sent PDBb pointer 8
core --- 			core ---		PKO	---

free WQE buffer 9	PKO DMA PDBb 10		sent PDB via POB 11
core	---		L2/DRAM	---		PKO	---

frees the packet data buffer back to FPA 12
PKO
**************************************************************************/

Hardware Features to Accelerate Packet Processing
=================================================
硬件管理单元:
	1. 包分类和优先级
	2. 缓冲池
	3. 包联系锁
	4. 包排序
1. 包分类、优先级
	1. Packets entering the processor are classified and given a QoS pr-
	   iority by the $PKI-PIP$,and then are put into the specified QoS Input 
	   Queue in the SSO.The priority of the QoS Input Queues is highly
	   configurable.
	2. The core requests a packet from the SSO. The SSO returns the hig-
	   hest priority schedulable packet available.When the core receives
	   the packet,it is ready to be processed.The core does not have to
	   inspect packet priority.It also never receives a packet which is
	   blocked waiting for a lock.
	3. After packet processing is complete,the core puts the packet on a
	   PKO Output Queue for transmission.The PKO Output Queues are mappe
	   -d to specific output ports on the Packet Interfaces.The priority
	   of  PKO Output Queues is highly configurable.

The Schedule/Synchronization/Order(SSO) Unit
============================================
SSO is called "POW(Packet/Order/Work)" in the Hardware Reference Manual
Packet processing is divided into several different phases:
	1. Packet Input
	2. SSO schedules new work to the core:cores work on packets in parallel
	3. Lock critical region:one-at-a-time access
	4. Unlock critical region and resume parallel processing
	5. Packet Output
POW:
 CPU内部硬件组件。嵌入式CPU么，总得佩些额外的武器在手不然对不起“嵌入”二字。
Cavium当代产品在这方面做得相当老到，该有的不该有的反正都有了。Tilera当代产品
呢？几乎是空白，于是它恍然意识到这些东东“可以有”，所以在下一代产品上要痛下苦
功喽！后面我一一细分对比（这可真是力气活啊）：1. 硬件收包处理单元。Cavium上
这东西叫做POW。做过Cavium项目的同事耳朵都要起老茧了不过毕竟还有新人，我争取
用一句话说明白：把从网口收上来的物理层报文先缓存起来然后公平保序地调度给各个
核去处理同时也可用于各个核之间传递报文（耶我做到了~~~）

一个报文要经过三个地方：
	1. Packet Input
	2. SSO and Core Processing
	3. Packet Output
当internal buffers接近满的时候，会利用RED(random early dropping)随机丢弃一
些报文.

这里还要注意物理地址转换的问题，会用到的请求wqe函数：
	cvmx_pow_work_request_sync()
	
	3.1 Hardware Management of Packet Classification and Priority
Hardware classification and prioritization includes:
	报文进入处理器时被PKI分类而且给予来QoS优先权，然后被放入指定的QoS输入队列
	在SSO中。QoS输入队列的优先权是高度可配置的。
	3.3 Hardware Management of Packet-Linked Locks
	These locks are not generic locks:they are directly connected to packet
	processing,so are referred to as packet-linked locks.
	这些锁不是普通的锁：他们是直接链接到报文处理的，所以被称为报文直连锁。
	报文处理过程中，像读/改TCP/IP控制块的代码，必须用锁保护起来。每个流后面有
	一个TCP/IP控制块。访问这个锁必须在报文进入序列，不是随机队列或first-come
	-first-serve。

Phase 1:
=======
Flow:
	Flow is a common networking term which refers to a uni-directional coll-
	ection of packets which share the same 5-tuple.
Tuple Hash Value:
	The tuple hash value is commonly used in packet processing.A Cyclic Red-
	undancy Check(CRC) algorithm is used to reduce the 13-byte 5-tuple to 16
	bits.The resultant 16-bit value is referred to as the tuple hash values.
	The tuple hash value is used to identify the flow.The PIP is reponsible
	for reading the packet header and computing the tuple hash value.
Tag Value,First Tag Value:
	The tag value is a 32-bit number.The first tag value is set by the IPD/-
	IPD when the packet is received.There are three distinct part of the fi-
	rst tag value:
	1. Bits 31-24 are always 0x0
	2. Bits 23-16 are either the number of the port which received the pack-
	   et,or all ls(ones)
	3. Bits 15-0 are the tuple hash value computed by the PIP.
	Bits 15 to 0 are set to the tuple hash value.The goal is for the first
	tag values to uniquely identify a flow.If the first tag value is unique
	for each flow,the OCTEON processor can process the different flows in p-
	arallel(one flow does not interface with the other).All 3 bits of the t-
	ag value can be changed by the core to move the packet through different
	phases of processing,or to specify the desired Output Queue.
Tag Type(TT),First Tag type: $报文乱序$
	The tag type is one of:ORDERED,ATOMIC,or NULL.The first tag type is set
	by the PIP/IPD when the packet is received.In our example,the first tag
	type is set to ORDERED,but the first tag type may be set to any tag type
	The ORDERED,ATOMIC,and NULL types are discussed after the concept of a
	tag tuple in introduced.
Tag Tuple:
	The tag tuple is the combination of the tag type and the tag value.
	It is very important to know that when software runing on the core rece-
	ives the packet to process,it can then change the tag tuple to different
	values to move the packet through processing.
	$谢希仁.P123:因为IP是无连接服务，数据包不存在按序接收的问题。$
	$但是tcp 有,udp呢？$
ORDERED Tag Type:Parallel Processing $order又为什么会并行？$
	Multiple packets from the same flow with an ORDERED tag type may be proc-
	essed in parallel by multiple core.
ATOMIC Tag Type:Serialized Processing:Accessing Critical Regions
	The ATOMIC tag type is used for locking.Only one packet with the same tag
	tuple can have the ATOMIC lock.
	An example of packets where ATOMIC processing is needed is TCP/IP packets
	especially where this server is the destination.
	The core can change the tag type of a packet.If the first tag type is OR-
	DERED(for instance,UDP packets where orderding is required),the core can 
	request a change in the tag type from ORDERED to ATOMIC.The SSO will gra-
	nt the new ATOMIC tag type to requesters one-at-a-time.
Quality of Serice (QoS) Value:	$how to do$
	The Quality of service(QoS) value is a number(0-7) which represents the
	priority of the packet.When packets are received,the PIP/IPD computes the
	QoS number for the packet,and saves the value in the WQE.There is no requ-
	irement for 0 or 7 to be the highest priority,and there is no requirement 
	for the priority to be linear.(In general,priority is configurable.There
	is only one exception to this rule:when using the static priority feature
	for PKO Output Queues,the lower the queue index,the higher the priority.
	There is no requirement that static priority feature be used.)
WQE:$tag type,tag value,QoS value,group,and a pointer to the Packet Data Buffer$
Group:
	See the Software Overview chapter

Phase 2:SSO Schedules New Work to the Core
==========================================
	The priorities of QoS queue are configured at system initializtion.

Cached Input Queues and Overflow Input Queues:
	The SSO caches the head of each QoS queue in internal memory,one Work D-
	escriptor per WQE.If there is not enough room in the Cached Input Queues
	WQEs are stored in the Overflow Input Queues,located in DRAM.
WD:
	Work Descriptor
Core State Descriptor:
	Inside the SSO,there is one Core State Descriptor data structure for ea-
	ch core.When the core performs a successful get_work operation,a Work D-
	escriptor is removed from the Cached Input Queue and assigned to the co-
	re.A pointer to the assigned Work Descriptor is stored in the Core State
	Descriptor.The Work Descriptor contain a pointer to the WQE.The get_work
	operation returns the WQE pointer to the core.
In-Flight:

In-Flight Queues:
	Packets from the same flow are given the same first tag type and first
	tag value.As they become scheduled to cores,they are put onto the same
	In-Flight Queue.
Phase 2 summary:
	P62:figure 19
	The SSO receives the WQE pointer from the IPD,and adds it to the approp-
	riate QoS queue.The priorities of the QoS queues are configured at syst-
	em initialization.
	The SSO has internal memory which is used to create Work Descriptors and
	Core State Descriptors.The head of each Input Queue is cached in interna
	-l memory.
	The Cached Input Queue is a linked list of Work Descriptors.If there are
	not enough Work Descriptors to containn the entire Input Queue in inter-
	al memory,the queue will continue in DRAM as a linked list of WQEs:  the
	Overflow Input Queue.
	When a core performs a successful get_work opertion,the SSO scheduling f-
	unction takes the highest priority schedulable Work Descriptor off of the
	highest priority Cached Input Queue and schedules it to the core.A point-
	er to the scheduled Work Descriptor is stored in the Core State Descript-
	or.The Work Descriptor is put on the appropriate In-Flight Queue.The core
	receives a pointer to the WQE.
	Work Descriptors which have an ORDERED tag type may be processed in para-
	llel by multiple cores.Work Descriptors which have an ATOMIC tag type are
	processed one packet at a time ingress order.

Phase 3:Lock Critical Region:One-at-a-time Access
=================================================
switch_tag:
	A core may perform a switch_tag operation to change the Work Descriptor's
	tag type,tag value,or both.Both may be changed with the same operation.T-
	his operation is referred to as a tag switch.
	$对于ATOMIC的报文，修改WD的tag type，以加上一个锁互斥$
	$那么对于共享的bootmem也是吗？$
	The core will perform a switch_tag operation from ORDERED to ATOMIC to r-
	quest a lock(for instance to lock a critical region).To unlock, the core
	will perform a switch_tag operation to a different tag tuple.
Phase 3 summary:
	In order to protect a critical region,the core performs a switch_tag ope-
	ration from ORDERED to ATOMIC.The Work Descriptor moves from the inital
	In-Flight Queue to the target In-Flight Queue.

Phase 4:Unlock Critical Region and Resume Parallel Processing
=============================================================
	To resume parallel processing,the core will perform a switch_tag operato-
	in from ATOMIC back to ORDERED.The tag value must be different than the
	original ORDERED tag value.Remember that all packets in the flow must fo-
	llow the same tag switch sequence or they may not stay in the correct or-
	der.

Phase 5:Packet Output
=====================
	The core uses the SSO's synchronization and ordering features to select
	the PKO Output Queue,lock it,and to guarantee packet transmission command
	are sent to the PKO Output Queues in ingress order.(Note:sending Packets
	to PKO Output Queues in order is an option,not a requirement.
	The PKO will remove the commands from the tail of the PKO Output Queue,r-
	ead the packet data from L2/DRAM,and DMA the data to the selected output
	port.The PKO can optionally notify the core when the packet is transmitt-
	ed.
PKO Output Ports:
	The PKO supports up to 40 PKO Output Ports,depending on the OCTEON model.
	Different ports correspond to the differe hardware interfaces.
PKO Output Queues:
	The PKO has up to 256 PKO Output Queues,depending on the OCTEON model.The
	Output Queues are mapped to the Output Ports.The Output Queues can have
	different priorities,which are configured at system initialization time.
	To insure that all packets from the same flow are transmitted in ingress
	order,send them all to the same Output Queue.
PKO Output Queue to Port Mapping:
	Since there are more Output Queues than Output Ports,More than one Output
	Queue may be mapped to the same Output Port.
	The queue-to-port mapping is configured at system initializtion time.
Selecting the PKO Output Queue:$tag value被重写用来标识选择的输出队列$
	Each Output Queue is identified by a unique tag tuple.The tag value which
	had identified the flow is now overwritten by a tag value which identifi-
	es the selected Output Queue.
Transmitting Packets in Ingress Order:
Packet Order is preserved through the packet processing if:
	$条件怎么理解?ORDEERED 怎么保证，按照进入的次序$
	1. only ORDERED or ATOMIC tag type are used during processing(not null)
	2. all packets in the same flow follow the same tag switch sequence
	3. ATOMIC locking is used to guarantee that packets from the same flow
	   are sent to the Output Queues one-at-a-time
	4. all packets from the same flow are sent to the same PKO Output Queue
Phase 5 summary:
	$After processing the packet data,the core switches the tag type and tag$
	$value.The tag type is set to ATOMIC;$the target tag value corresponds to
	the selected Output Queue.This operation will lock the selected Output
	Queue.When the core has the lock,it sends the packet to the selected P-
	KO Output Queue.When the core has the lock,it sends the packet to the
	selected PKO Output Queue,and then releases the lock.The core frees the
	WQE and Work Descriptor.The PKO may optionally free the Packet Data Bu-
	ffer after it reads the Packet data into its internal memory.
Summary:
=======
	The SSO uses tag values and tag types to manage multiple data flows wh-
	ile maintaing packet ingress order.
	Each scheduled WQE hash a correponding Work Descriptor on the SSO's In-
	Flight Queue corresponding to the tag tuple.when the core performs a s-
	witch_tag operation,the Work Descriptor moves in ingress order from the
	inital In-Flight Queue to the target In-Flight Queue.
	By using the OREDERED type,packets may be processed in parallel for hig-
	h throughput.By using the ATOMIC type,critical regions are protected by
	packet-linked locks.



















# 2012/10/31 16：45 page 50 #

/**	name:	software overview 
 *	名字	第三章 软件概述
 *	time	11/12/2012 10:00
 *	page	93/562
 */
	确定有限自动机:
	DFA(deterministic finite automaton[diˌtə:miˈnistik ˈfainait ɔ:ˈtɔmətən])

	LLM (Low Latency[ˈletn:si] Memory – used to support DFA functions).

The Simple Executive API is used to access the hardware units:
	1. Basic units:FPA,IPD,PIP,SSO,and PKO
	2. Intermediate units:FAU and TIM
	3. Advandced units:LLM,ZIP,RNG,DFA,KEY,CIU,etc

	When running Simple Executive on multiple cores,the same ELF file is us-
	ually run on all of the cores.These core are all started from one load
	command.The cores share the .text and read-only data(.rodata) sections.
	they also share cvmx_shared variables,and memory allocated with bootmem_
	alloc.
	Shared memory may be shared between the Linux and SE applications if the
	named block bootmem_alloc functions are used.

	When running SE applications as Linux user-mode apps,although the OCTEON
	hardware has been configured to allow access to both hardware and memory
	without performance penalties,your application may still have noticeably
	slower performance than if it was run in standalone mode.Cache misses,T-
	LB misses,and bus contention are more likely when running as a Linux us-
	er mode application due to the large amounts of code and data needed for
	Linux.
Linux:embedded_rootfs File System
	Whem running Linux with the embedded root file system(embedded_rootfs),
	the root file system is a RAM disk (in memory only).In this case,the ELF
	file is either stored in on-board flash,or downloaded from a host.


























SE-S, SE-UM Shared:
	When running Simple Executive on multiple cores, the same ELF file is usually run on all of the cores. These cores are all started from one load command. The cores share the .text and read-only data (.rodata) sections. They also share cvmx_shared variables, and memoryallocated with bootmem_alloc.
	When running Linux on multiple cores (SMP), there is one kernel running, not one kernel per core. Linux applications are scheduled to run on different cores.
embedded rootfs file system --- busybox
Allocating and Using  Bootmem Global Memroy:
Note that some of the allocation functions allow processes to allocate memory, but not free it. To be able to free the memory, named blocks must be used.
The C-library functions malloc() and free() only manage core-local memory. This memory can not be used for FPA buffers.
ELF File--->in-memory images(contain system memory allocated for the stack and heap),mapping or no mapping
Per-Core Grp Mask:

12 Accessing Bootmem Global Memory (Buffers)
64: NO 1:1 Mapping
	在kernel-mode下使用xkphys进行.
	cached与否由地址中CCA域进行判断.
64: 1:1 Mapping
	系统内存映射到进程地址空间(xuseg)通过cvmx_user_app_inint(),即低段地址.
32: NO 1:1 Mapping
	在kernel下使用kseg0段
32: 1:1 Mapping
	这里使用useg段，有2GB的范围.

	The reason the in-memory image size is limited to 256 MBytes is becaus 
	the Simple Executive application will be loaded into the virtual memory
	map,squeezed between two blocks of system memory.
	If 1:1 mapping is not used,Simple Executive applications load at 0x1000
	0000,but memory can be mapped anywhere install of immediately above and
	the applicatoin,so the application can be larger than 256 MBytes.


/**	name:	SDK tutorial
 *	time:	15:46 11/12/2012
 *	page:	234/562
 */	

Oprofile 是linux内核支持的一种性能分析机制。
	它在时钟中断处理入口处建立监测点，记录被中断的上下文现场，由配套的用户态的工具oprof_start负责在用户态收集数据，opreport则分析数据并给出分析报告.

FPA:Packet Data Buffers and Work Queue Entry Buffers
FAU:Fetch and add Unit.

WQE buffer 和 Packet Data Buffer 都在L2/DRAM上，这些缓冲都是系统初始化时在L2/DRAM上分配的。and are arranged into up to 8 pools of buffers.而且排列最多到8个缓冲池。(缓冲的池---pool contain buffers)

两个elf文件,产生两个load sets,不会共享‘sysinfo’数据结构。

/*
 * Readed in 2012 Holiday
 */
Pages 155 - 159
physical address space:		 _______________
	0x1 6400 0000 03ff	| I/O space.	|
				|		|
				|		|
	0x1 0700 0000 0000	|_______________|
							bit 48 is used to select either the IO space or
							system memory.If bit 48-1,IO space is selected.
						 	If bit 48=0,system memory is(DRAM) is selected.
				 _______________
	0x0 0004 1fff ffff	|DRAM Region 1(s|
				|ystem Memory)Th|	only 36 bits are needed to address all of syst-
				|e second 256 MB|	em memory(16GB)The current mexium system memory
	0x0 0004 1fff ffff	|__if__present__|	address is 0x4 1FFF FFFF.
				
				256MB alignment gap
				before the next me-
				mory block.
				 _______________
	0x0 0003 ffff ffff	|DRAM region 2(S|	DRAM Region 2 starts at the low address 0x0 0000
				|ystem Memory)Th|	2000 0000 and goes toward 0x0 0003 ffff ffff.The
				|e upper 15.5 GB|	exact high address depends on the amount of DRAM
				| as much as is	|	installed in the target system.
	0x0 0000 2000 0000	|____present____|
	0x0 0000 1fff ffff											在启动起来之后--bootoct
				256MB reserved for	Internally,once the boot bus addresses have been	内存控制器，会把，RAM1
				   Boot Bus.		handled, the high address bits<35:34>are ignored	映射到boot-bus，这样对于
							when talking to the DRAM controller,so DRAM Reg-	CPU是连续的。
							ion 1 addressed appear to the DRAM controller to
	0x0 0000 1000 0000	 _______________	be in the address range 0x1000 0000 to 0x1fff ff
	0x0 0000 0fff ffff	|DRAM Region 0(S|	ff . The DRAM controller thus sees system memory
				|stem Memory)The|	as contiguous address:Region 0,Region 1,Region 2
				|first 256MB(if |
	0x0 0000 0000 0000	|____present____|
Virtual Memory:
	The goal of virtual memory is to make accessing physical memory and I/O
	space safer and more convenient.

	Mapping:
	Mapping requires,at a minimum,entries into a Translation Look-aside Buf-	P162,P171
	fer (TLB). Simple Executive Standalone applications use only the TLB for
	mapping; Linux users a more complex memory management system(page tables
	and TLB miss handler).
	
	Generic MIPS Virtual Memory Map:
	xkphys segment to accesses physical memory and I/O space without mapping
	the virtual addresses.
	virtual address translation depends on:
	1. The number of address bits in the address space:64-bit or 32-bit add-
	   ress space
	2. The segment addressed
	3. The privilege level(model):kernel,supervisor,or user.

	xkphys:
	The xkphys addresses provide a "window" into the physical address space.
	The high bits are stripped off the virtual address,and the low PABITS(P-
	hysical Address BITS)are used as a physical address.On the OCTEON proce-
	ssor,PABITS is 49:bits<48:0>,matching the number of SEGBITS(49).
	The I/O space is selected if bit 48 of the physical address is "1".Phys-
	ical memory is selected if bit 48 of the physcial address is "0".

p168	xkphys window
	0xbfff ffff ffff ffff	--------------	0x1 ffff ffff ffff
						unmapped and uncached I/O
						Space used to access CSRs
						and PCI Space
				--------------	0x1 0000 0000 0000

				--------------	0x0 ffff ffff ffff		The system memory address space is architected
						unmapped and cached system	to 36 bits.Only 35 bits are currently used.
						memory				
										Boot Bus 256MB(1fc0 0000)
	0x8000 0000 0000 0000	--------------	0x0 0000 0000 0000

P171	64-Bits	Virtual address translation on MIPS

	SE-S applications run in kernel mode,but are mapped into the xuseg or u-
	seg virtual address space,depending on whether they are 64-bit or 32-bit
	applications.

	SE-UM applications run in user mode and  are mapped into the xuseg or u-
	seg virtual address space,depending on whether they are 64-bit or 32-bit
	applications.

	The Linux Kernel runs in kernel mode and is mapped into xkseg.It is alw-
	ays 64-bit.
Summary of Virtual Address Space on cnMIPS
	The MIPS virtual address space is divided into segments.The 64-bit virt-
	ual address space contains a 32-bit compatibility mode address space.
	The MIPS memory management unit is simplified,and consists only of a TLB
	Page tables are optionally implemented in software.
	Mapped:A virtual address is 'mapped' when access is through a TLB entry.
	Cached:When a virtual address accesses system memory,the system memory 
	is cached if it is stored in the L1 and/or L2 cache for fast access. On
	the OCTEON processor,all system memory access are cached.

		Mapped Segments			Mapped Segments
	xuseg	The xuseg segment is the user	SE-S 64-bit application run in
		address space(mapped).		kernel-mode,but are mapped into 
						xuseg.
	xsseg	The xsseg segment is the sup-	The xsseg segment is usually not
		ervisor address space(usually	used in OCTEON cnMIPS.
		not used)(mapped)
	xkseg	The xkseg segment is in the	The xkseg segment contains the
		kernel address space(mapped)	OCTEON-specific cvmseg segment.
						User-Mode access is allowed to
						cvmseg.
		Unmapped Segments			Unmapped Segments
	xkphys	The xkphys segment is in the	SE-UM 64-bit applications may be
		kernel address space.It is an	allowed access to xkphys address.
		unmapped address space:a win-	SE-S 64-bit applications always
		dow into the physical address	have access to xkphys addresses(
		space:system memory and I/O	they run in kernel-mode).Accesses
		space.				to system memory are always cached
						Accesses to I/O space are never cached.
	SE-S 64-bit applications run in kernel mode and are mapped to xuseg.
	SE-S 32-bit applications run in kernel mode and are mapped into useg.
	SE-UM 64-bit applications run in user mode and are mapped into xuseg.
	SE-UM 32-bit applications run in user mode and are mapped into useg.
	The Linux kernel is always 64-bit,runs in kernel mode,and is mapped into xkseg.

	SE-S applications run in kernel-mode but are loaded into useg.
BootMem:
	At boot time,the bootloader creates a pool of all free memory,bootmem.This mem-
	ory is managed by the bootmem allocator functions.These functios provide the n-
	eeded locking so that two applications will not get the same memory,and return
	the appropriate virtual address of the allocated memory region.
	Note that memory allocted via these functions is uninitialized:it is not guara-
	teed to be all zeroes.
	If CVMX_USE_1_TO_1_TLB_MAPPINGS is 1,then all of system memory is mapped into 
	the process address space(xuseg) by cvmx_user_app_init().
SE-S Memory Model:
	Simple Executive Standalone(SE-S) applications run in kernel mode.All of
	the system memory is mapped,allowing SE full access to memory, including
	memory they do not own.64-bit SE-S applications may also freely access
	the I/O space by using xkphys addresses.There are no context switches,a-
	nd context switches,and no TLB misses.
	On startup the bootloader and SE function cvmx_user_app_init() create a
	kernel-mode address space where all address mapping is complete by the		TLB --- stack area.
	time the application initialization routine completes.There are no expe-
	cted TLB misses when running under SE-S:there is no exception handler.A
	TLB miss will cause the system to crash,because there is no TLB miss ha-
	ndler for the hardware exception.The system would need to be reset or p-
	ower cycled to recover.

	Applications are loaded into xuseg or useg at virtual address 0x10000000
	There is some stack overflow protection.When the bootloader allocates m-
	emory for the stack,it leaves the page below the stack unmapped, so that
	any access to this region will generate a TLB exception.

	Mapping of System Memory:
	System memory may optionally be mapped 1:1 to the user's address space,
	so that physcical address 0 is virtual address 0.
	The reason the inmemory image size is limited to 256MB is because the SE
	application will be loaded into the virtual memory map,squeezed between
	two blocks of system memory.If 1:1 mapping is not used,SE load at 0x1000
	0000,but memory can be mapped anywhere instead of immediately above and
	below the applicatoin,so the application can be larger than 256MB.

P196	SE size Limitation if 1:1 Mapping is Used
	1:1 mapping limited table
	Not mapped, creating a window in the virtual memory map.
	SE applications are linked to load at virtual address 0x10000000(useg)
	When 1:1 Mapping is used,SE is surrounded by mapped memory, and cannot
	be larger than the 256MB Boot Bus Window.
	The application will only have access to the part of this space mapped 
	in by the bootloader.This space is mapped and cached.These address are
	the same in both 32-bit and 64-bit APIs.
	I/O address is unmapped,uncached.

P197	SE-S 64-Bit Virtual Memory Map
	Note that fewer TLB entries are needed if 1:1 mapping is not used,each
	double TLB entry will map 512MB of memory.

P201	SE-S 32-Bit Virtual Memory Map
	Downloading to the Reserved Download Block:
	After storing the ELF file in the Reserved Download Block(at system m-
	emory),the bootloader reads the ELF file,parses it,allocates system m-
	emory for the in-memory image,and creates the in-memory image(s) in d-
	ifferent system memory location(s).All of this processing is part of
	the boot command.
	The bootloader creates the needed TLB entries to map the virtual to p-
	hysical addresses for the in-memory image.Note that the in-memory ima-
	ge is larger than the ELF file:memory is allocated for the stack and
	heap.

	If the ELF file is in flash,then the reserved downloading memory loca-
	tion is not used.The bootloader will read the file from flash instead
	of the Reserved Download Block.

P221 The Power of One Load Set
	uboot_minicom# namedprint
	Name:__tmp_load, address:0x0000000020000000, size:0x0000000006000000
	index: 0
	means-- Reserved Download Block:"__tmp_load":
	the start address is 0x2000 0000,and the length is 96MB(0x6000000).

About Downloading the Application:
	When running a hybrid system(more than one load set),be sure to start to
	the application running on core 0 last.Once the application runs on core
	0,the other cores come out of reset and begin to run their applications.
	Core 0 may be one of many cores in the load set,there is no need to sta-
	rt an application only on core 0.

	As discussed above,this download requires temporary memory to store the
	image.At the next step,the ELF file boot step,the bootloader reads the
	ELF image from the Reserved Download Block,parse it,and loads the appl-
	ication into memory(creating the in-memory image).After the core 0 ima-
	ge starts to run,the memory used for the image download is freed and a-
	dded to the pool of free memory.

	Download ELF to Reserved Download Block:	download to: 0x2000 0000
	1. PCI :oct-pci-load
	2. Flash card :fatload
	3. TFTP :tftpboot
	4. Serial Port

	Load ELF from the Reserved Download Block to into memory(creating the in
	memory image):					load to: 0x1000 0000
	For SE processes,the ELF loader is bootoct.
	For linux,the ELF loader is bootoctlinux.
	For SE-UM instances,the kernel handles ELF file loading automatically.
	The oncpu utility may be used to start SE-UM applications on a subset
	of cores.

The Boot Command:
	The arguments to the boot command are used to specify the stack and h-
	eap sizes,and the coremask.In example programs such as hello,the defa-
	ult stack and heap size are adequate,so they are not specified on the
	command line.
	Note that the boot command will load the applications onto the cores,
	but all cores except core 0 are held in reset(the applications do not
	run)until the application running on core 0 is booted.For this reason,
	core 0 should be booted last.

Virtual memory map summary:
	0x1000 0000 to 0x2000 0000:This range is used to map the application's
	code,data,stack,and heap.This address range coresponds to the physical
	address for Octeon boot bus,so this does not conflict with any potential
	1-1 DRAM mappings.The stack and heap are placed at the top of this range
	These addresses are the same for boteh 64 bit and 32 bit ABIs.
	1-1 mappings as configured by the application(Typically done in cvmx_use
	r_app_init()) These mappings are done to avoid having to set and clear
	the XKPHYS bit(bit 63)in the address.With these mappings in place,the a-
	pplication can use 'physcial' address directly.
	为了让核去直接访问一个特定的物理内存，必须使用XKPHYS地址空间，这需要设置
	地址的63位(Unmapped，XKPHYS把最高位掩掉，就是对应的物理地址).为了避免重
	复设置和清楚bit 63位，SE使用1-1虚拟--物理地址映射。这样就不用设置63就可
	以使用“物理”地址了。(虚拟地址仍被使用，但是对被硬件共享的内存区域来说，物
	理地址和虚拟地址是一样的。）这些由应用程序使能映射来决定，应用程序可以通
	过函数cvmx_user_app_init()调用来实现，这个函数目的在于简化典型的应用程序
	配置。
cvmx_bootmem_alloc():
	它返回一个有效的全局物理内存池的物理地址。这个内存
	池由bootloader建立，在应用程序开始运行时它包含全部的未被程序的stack/heap
	/code/data或者bootloader分配的名字空间所占用的内存(未使用的内存).要注意
	它返回的是物理地址，因此要么建立1-1TLB映射，要么设置地址的XKPHYS位，二者
	选一。通常采用建立1-1TLB映射的方法。为保证多核的安全，cvmx_bootmem_alloc
	需要加锁。
Bootloader:
	The bootloader is reponsible for loading the Octeon application ELF file
	into DRAM from the boot bus(flash memory) and setting up the TLB mappin-
	gs required for running the application.The bootloader passes a list of
	the avaliable memory to the application,and this is available to the ap-
	plication in the cvmx_sysinfo_t structure.可以去查看Octeon Bootloader d-
	ocumentation.
