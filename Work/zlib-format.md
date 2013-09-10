# RFC1950
## 简介
### 目的
该文档的目的是定义一个无损压缩数据的格式:

* 与以下内容无关：CPU类型，操作系统，文件系统，字符集；因此可以互相交换.

* 可以生产、消费，甚至对于任意长度有序的输入数据流，仅仅使用一个先前限定数量的中间内存。因此可以用于数据通信或者相近数据形式，比如Unix filters

* 可以使用一些不同的压缩算法

* 可以在友好的方式下实现，不必考虑专利，因此可以免费使用

### 面向读者
本文档是让压缩数据到zlib格式或者从zlib格式解压缩的软件实现者使用。

文档内容假定读者有“比特”级或者其他原始数据的编程基本背景。

### 适用范围
本文档指定一种可以在内存中压缩任意数据的压缩数据格式。

### 兼容
除非另有说明($Unless otherwise indicate below$)，一个基于本文档的解压缩工具必须可以能够接受和解压缩遵循本说明的任何数据。压缩工具亦然。

### 术语定义和约定的使用
byte: 8 bits stored or trasmitted as a unit.

### 在先前版本的改动
版本3.1 是本说明的第一个发布版本。在版本3.2中一些术语更改了，而且Adler-32的简单代码为了更清晰重写了。在版本3.3中，介绍了对于字典的支持，而且文档也转成了RFC风格。

## 详细说明
### 大体约定
* 数字表示的图表的定义

* 最高、最低有效位. 大端处理

### 数据格式
一个zlib流有如下结构： 
```
| CMF | FLG | (more-->)
```
(if FLG.FDICT set)
```
|DICTID| (more-->)
```

```
| ... compressed data... | ADLE32 |
```
任何出现在ADLE32后的数据，不属于zlib数据流。

#### CMF(compression method and flags)
这个字节分为4位的压缩方法，和4位依赖压缩方法的信息域。

* bits 0 to 3 CM	Compression method
> CM=8表示“deflate”压缩方法，而且窗口大小最大是32K. CM=15是保留的,用于只是其他域的存在，在压缩数据之前。

* bits 4 to 7 CINFO	Compression info
> CINFO在本文档中不会大于7的，而且只在CM=8的时候被定义。

#### FLG(FLaGs)

* bits 0 to 4	FCHECK check bit for CMF and FLG

* bits 5 		FDICT  present dictionary
 
* bits 6 to 7	FLEVEL compresion level

#### 压缩数据
对于使用压缩方法8，压缩数据的格式保存在deflate压缩方法格式中。

#### ALDER32
包含未压缩数据的校验和，根据Adler-32算法计算出来的。

Adler-32是由两个和组成的，s1是所有字节的和，s2是所有s1值的和。每个和以65521为模。s1初始化为1，s2初始化为0.校验和保存为s2*65536 + s1（大端，网络序).

### 遵循
一个标准的压缩器必须能生成正确的CMF，FLG和校验和，不一定支持 $预置字典$ .

一个标准的解压缩工具必须能够检查CMF，FLG和校验和，而且在这些值不对的时候提供错误提示。如果CM的值不等于8（本文档支持8），而且FDICT是被设置的，但是DICTID不是一个被认可的预置字典ID。FLEVEL可能被忽略，而且也是遵循标准的。

当zlib数据流被用作其他标准格式的一部分的时候，解压缩工具必须支持其他格式指定的所有字典。当其他格式不使用预置字典特点是，解压缩工具必须拒绝任何FDICT被置位的流。

## 参考
一大通人名，和文档。

## 源码
ftp://ftp.uu.net/pub/archiving/zip/zlib.

## 安全考虑 感谢 作者地址
如此云云

## 附录：基本原理
### 预置字典
预置字典对于压缩短的输入序列相当有用。压缩可以利用字典内容以更加紧凑的方式转码输入。

解压缩可以通过使用合适的上下文虚拟的解压缩一个字典的压缩版本，但不产生输出。然而对于确定的压缩算法，比如deflate算法，这个操作可以不用真正的执行解压缩就能完成。

压缩和解压缩必须使用一样的字典。字典可能是固定的一个，也能在一些预置好的字典中选，根据输入数据的类别。

解压缩工具和通过字典标识判断知道那个字典被压缩工具选择了。

本文档没有指定预置字典的内容，最理想的字典是软件指定的。使用zlib指定特点的标准数据格式必须精准的定义允许的字典。

### Adler-32算法
Adler-32算法是比CRC32快很多的算法，同时出现未检测的错误的可能很低。

## Adler-32源码
```
#define BASE 65521	/* larget prime smaller than 65536 */

unsigned long adler = 1L;

while (read_buffer(buffer, length) != EOF) {
	adler = update_alder32(adler, buffer, length);
	
	if (adler != original_adler) error();
}

unsigned long update_adler32(unsigned long adler, unsigned char *buf, int len)
{
		unsigned long s1 = adler & 0xffff;
		unsigned long s2 = (adler >> 16) & 0xffff;
		
		int n;
		for (n = 0; n < len; n++) {
				s1 = (s1 + buf[n]) % BASE;
				s2 = (s2 + s1) % BASE;
		}
		return (s2 << 16) + s1;
}

unsigned long adler32(unsigned char *buf, int len)
{
		return update_adler32(1L, buf, len);
}
```

