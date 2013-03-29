Acknowledgments									致谢
Preface										前言，序
1 Introduction									介绍
	1.1 Shared Objects and Synchronization					共享对象和同步
	1.2 A Fable								寓言
		1.2.1 Properties of Mutual Exclusion				互斥对象的特性
		1.2.2 The Moral							规则
	1.3 The Producer-Consumer Problem					生产者-消费者问题
	1.4 The Reader-Writers Problem						读者-作者问题
	1.5 The Harsh Realities of Parallelization				并行的严酷现实
	1.6 Parallel Programming						并行编程
	1.7 Chapter Notes							本章注解
	1.8 Exercises								练习
PRINCIPLES									规则
2 Mutal Exclusion								共同的互斥
	2.1 Time								定时
	2.2 Critical Sections							临界区
	2.3 2-Thread Solutions							2-线程 解决方法
		2.3.1 The LockOne Class						
		2.3.2 The LockTwo Class						
		2.3.3 The Peterson Lock
	2.4 The Filter Lock
	2.5 Fairness								公平
	2.6 Lamport's Bakery Algorithm
	2.7 Bounded Timestamps							绑定时间戳
	2.8 Lower Bounds on the Number of Locations
	2.9 Chapter Notes
	2.10 Exercises
3 Concurrent Objects								并发的对象
	3.1 Concurrency and Correctness						并发和正确
	3.2 Sequential Objects							顺序对象
	3.3 Quiescent Consistency						静态一致性
		3.3.1 Remarks
	3.5 Linearizability							线性一致性
		3.5.1 Linearization Points					线性化重点 
		3.5.2 Remarks							注释
