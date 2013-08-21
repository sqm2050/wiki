## CPU Cache
CPU Cache是并发编程设计中的技术难点。

http://igoro.com/archive/gallery-of-processor-cache-effects/

测试平台：
```
Logical Processor to Cache Map:
*— Data Cache 0, Level 1, 32 KB, Assoc 8, LineSize 64
*— Instruction Cache 0, Level 1, 32 KB, Assoc 8, LineSize 64
-*– Data Cache 1, Level 1, 32 KB, Assoc 8, LineSize 64
-*– Instruction Cache 1, Level 1, 32 KB, Assoc 8, LineSize 64
**– Unified Cache 0, Level 2, 4 MB, Assoc 16, LineSize 64
–*- Data Cache 2, Level 1, 32 KB, Assoc 8, LineSize 64
–*- Instruction Cache 2, Level 1, 32 KB, Assoc 8, LineSize 64
—* Data Cache 3, Level 1, 32 KB, Assoc 8, LineSize 64
—* Instruction Cache 3, Level 1, 32 KB, Assoc 8, LineSize 64
–** Unified Cache 1, Level 2, 4 MB, Assoc 16, LineSize 64

（译者注：作者平台是四核机，所以L1编号为0~3，数据/指令各一个，L2只有数据缓存，两个处理器共享一个，编号0~1。)
```

### 内存访问和运行
有时候内存访问的次数更大程度的影响性能，表明cache的重要性。

访问同一段内存，计算的次数的影响反而较小。

所以以下的结论可以忽略忽略计算次数的影响。

### 缓存行的影响
使用的内存跨越越多的缓存行就会花费更多的时间，基本上是正比关系。

### L1和L2缓存大小
读写一段L1和L2大小内存的时间是个梯形增长,L1大小内的时间差不多，L2大小内的时间也是条直线(时间相差较小)。l1一个阶梯时间，l2一个阶梯时间，超过l2是另外一个时间。

### 指令级别并发
```
	int steps = 256 * 1024 * 1024;
	int[] a = new int[2];
	
	// Loop 1
	for (int i = 0; i < steps; i++) {
			a[0]++; a[0]++;
	}
	// Loop 2
	for (int i = 0; i < steps; i++) {
			a[0]++; a[1]++;
	}
```
结果是第二个循环约比第一个快一倍。这跟两个循环体内的操作指令依赖性有关。

第一个循环体内，操作是相互依赖的。

许多人在reddit上询问有关编译器优化的问题，像{ a[0]++; a[0]++; }能否优化为{ a[0]+=2; }。实际上，C#编译器和CLR JIT没有做优化——在数组访问方面。我用release模式编译了所有测试（使用优化选项），但我查询了JIT汇编语言证实优化并未影响结果。

### 缓存关联性
