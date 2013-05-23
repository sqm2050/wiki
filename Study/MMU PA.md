	CPU通过地址来访问内存中的单元，地址有虚拟地址和物理地址之分，如果CPU没有
	MMU（Memory Management Unit，内存管理单元），或者有MMU但没有启用，CPU核
	在取指令或访问内存时发出的地址将直接传到CPU芯片的外部地址引脚上，直接被
	内存芯片（以下称为物理内存，以便与虚拟内存区分）接收，这称为物理地址（P-
	hysical Address，以下简称PA）
	MIPS中CP0就是MMU，而且CP0的寄存器SR包括确定CPU特权等级，那些中断引脚使能
	和其它的CPU模式等位域。
	
