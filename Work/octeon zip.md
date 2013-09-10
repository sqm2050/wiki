# zip
## Accelerated ZLIB
Cavium Networks provides ZLIB components with its SDK, these components support acceleration of ZIP operations in three separate modes of operation.
* CN3XXX-ZLIB-CORE

* CN3XXX-ZLIB-LINUX

* CN3XXX-ZLIB-HOST

## ZLIB API
### ZIP operation context
The application using ZLIB APIs must allocate the space for a structure calles `z_stream`, one per ZIP stream, and pass a pointer to it for successive operations.

### Stream Context and Operation Initialization
There are two ZIP operations avaliable:Inflate and Deflate.The function to call the initializes the `z_steam` context depends upon the operation.They are called:
```
	inflateInit()
	deflateInit()
```
And the argument is a pointer to a data stream's context `z_stream` structure.

### Inflate and Deflate operations
```
	inflate()
	deflate()
```
The application using this API will set the buffer pointers within the z_stream structure appropriately pointing to the data to be operated upon and where the results are to be stored. These operations will block until they complete.

non-blocking calls:
```
	inflate_nb()
	deflate_nb()
```
These functions take the same arguments as the blocking calls, but will return immediately.The application must use polling functions to determine when the opertion is complete.These functions are called:
```
	inflate_poll()
	deflate_poll()
```
### Completion Functions
Completion functions that close the stream and flush any pending data:
```
	inflateEnd()
	deflateEnd()
```
# White Paper
The compression coprocessor aggressively searches for history matches as far as 15360 bytes prior to the current byte in an input stream.

Prior to Huffman encoding,the compression coprocessor accumulates blocks of up to 16K literals,or 8K matches,or a combination of each.

The compression coprocessor creates compressed blocks for the input data stream, ending the output of a particular invocation on a block boundary so that the only partial-file state for compression is the output stream bits beyond the last byte.

The OCTEON ZIP coprocessor supports preset dictionaries(RFC 1950) through history bytes for both compression and decompression.

## ZIP Coprocessor Operation
ZIP is a DEFLATE engine *augmented* with instruction fetching and DMA engines.The OCTEON ZIP coprocessor is a single unit that is shared by instructions submitted from any OCTEON core.The OCTEON cores place their instructions in a dynamically-allocted input queue,residing in OCTEON main memory,and ring a doorbell to indicate instruction availability.

The OCTEON ZIP coprocessor contains five DMA engines used to read instructions,history,context,gather lists,scatter lists,and to write output and results.It can also *submit a work queue entry* once it completes an instruction.

### ZIP Instruction Queue
Each instruction queue is a linked list of chunks,or buffers.

>  queue是一系列的桶或者缓冲。

* ZIP_CMD_BUF[POOL]: 指定FPA内存池.

* ZIP_CMD_BUF[DWB]: 指定不用写回的个数.

* ZIP_CMD_BUF[SIZE]: 指示一个buffer/chunk的大小，单位是64的字.

The last 64-bit word in a chunk is a next chunk buffer pointer.

The instructions are numbered from zero to four,with smaller numbers for the older ZIP instructions,which will be started on the ZIP coprocessor first.

> 这里因为是一个向后链的链表，所以开头的是新的后面数字小的链接的要早些就是older的指令，会先被执行。 *先到-数字小-老的-先执行* .

Note that an individual ZIP instruction can $straddle a chunk boundary$.The minimum ZIP_CMD_BUF[SIZE] value is 9 words.

> straddle: if something straddles a line, road, or river, part of it is on one side and part on the other side.

The ZIP hardware maintains the tail pointer for the queue and the core software maintains the head pointer.

> 要分清头尾，在这个例子中, ---> 箭头是头， 后面是尾巴，对应next指针指向的是头，包含next指针的chunk/buffer是tail-尾巴。

To insert a packet into a queue,software must first write the ZIP instruction into the queue.allocating chunks if necessary,and then perform a ZIP doorbell operation with the number of instruction(64-bit) words added to the queue,which must always be a multiple of 8 because the ZIP instruction is a fixed 64 bytes.

> 插入一个报文数据之前，必须先写入ZIP 指令到队列。然后执行一个ZIP的按铃操作，参数是指令$字$的数目，这里的数目是指字的数目，不是指令的数目。因为一个指令是64位-8个字的，所以这个数目一定是8的倍数。

The distance between the head pointer and the tail pointer is both the size of the ZIP instruction queue and the outstanding doorbell count.Core software must guarantee that the queue is smaller than 220 words.

At boot time,software must configure the ZIP instruction queue with the original next chunk buffer pointer with a write to ZIP_CMD_BUF[PTR].

## ZIP Generic Pointer (ZPTR) Format
```
ZPTP	 0      F N L  LENGTH                   ADDR
		+-----+-+-+-+----------------+----------------------------------------+
		+-----+-+-+-+----------------+----------------------------------------+
```
When a ZPTR is in an instrcution word,ZPTR[ADDR] is either:

* a) A direct byte pointer into OCTEON's attached memory

* b) A pointer to a gather/scatter list in OCTEON's memory

When a ZPTR is in a gather-scatter list,ZPTR[ADDR] is:

* c) A direct byte pointer into OCTEON's attached memory.

b: ZPTR[ADDR<2:0>] must be zero.(All these cases must be aligned on an 8 byte boundary.)

ZPTR[ADDR<39:36>] are reserved and must be zero.

### ZPTR[LENGTH]
In case (a) and (c) above,ZPTR[LENGTH] is the number of bytes pointed at by ZPTR[ADDR]. ZPTR[LENGTH] must be non-zero in this case.

In case(b) above,ZPTR[LENGTH] is the number of gather/scatter list pointer entries pointed at by ADDR.(ZPTR[LENGTH]*8 is the number of bytes).ZPTR[LENGTH] must be at least 2 in this case.

ZPTR[LENGTH] must be zero for context and result pointers,because each has an implied fixed-size length(of 512 bytes and 24 bytes,respectively).

## ZIP instruction Field Descriptions
一个zip指令总是64个字节(64 乘 8位)，而且总是8字节(64位)对齐的。

* IWORD0[HG]
	如果设置，IWORD3指向一系列指针，这些指针被协处理器在读入当强历史数据之前读入。当是压缩操作时一定要是零。如果被设置，历史数据必须存在，而且IWORD3长度域指示在解压缩历史gather list中的指针数目，而且至少是2。

* IWORD0[DG]
	如果设置，IWORD4（输入和压缩历史指针）将会在在输入数据/历史数据之前被协处理器读入。如果被置位，IWORD4的长度域值，指示输入/压缩历史的gather list中指针数目，而且至少是2。

* IWORD0[DS]
	如果设置，IWORD5（输出指针）将会在协处理器写输出数据之前读入。如果被设置，IWORD5长度值，指示输出scatter list的指针数目，并且至少是2.

* IWORD0[C]
	指示操作类型，Compress == 1， Uncompress == 0.

* IWORD0[BF]
	设置输入流开始时候开启一个文件。注意在压缩的时候，如果IWORD1[HISTORYLENGTH]不为空，输入流是历史数据。不管历史数据是否存在，IWORD0[BF]应该指示第一个non-historys字节是文件的第一个字节;在解压缩时，IWORD0[BF]指明协处理器是读入上下文数据还是为了开始一个文件创建一个上下文。
	
* IWORD0[EF]
	设置输入流结束时候结束一个文件。对于解压缩，如果ZIP没有完成所有块的压缩，而她被置位了，是个错误。当zip完成文件中的所有的解压缩，如果没有被设置这时候不是错误.

* IWORD0[FD]
	强制ZIP对于所有块使用动态huffman编码。IWORD0[FD]一定不能位置，在IWORD0[FF]被置位的情况下。当解压缩的时候，IWORD0[FD]一定是0.

* IWORD0[FF]
	强制使用静态Buffman编码，如果FD置位，FF一定不能置位。对于解压缩，FF一定是零。

* IWORD0[EXN],IWORD0[EXBITS]
	这些是压缩之前生成的bit位，写在最后一个压缩字节之后。当IWORD0[BF]被置位，他们一定是0.如果IWORD0[BF]没有置位，他们通常与RWORD2中一样。对于解压缩，必须被设置为0.	

* IWORD0[TOTALOUTPUTLENGTH]
	指示可以写的输出流字节的最大值。对于压缩ZIP会返回一个错误指示，如果压缩输出的数据大于这个值。对于解压缩ZIP可以动态停止当这个值接近或者小于解压出来的数据。不论什么时候ZIP在解压缩操作中动态停止了，ZIP会保存状态到上下文，而且指示输入和输出的数目：RWORD1[TOTOALBYTESREAD]、RWORD1[TOTOALBYTESWRITTEN]. TOTALOUTPUTLENGTH一定不会是0，而且至少是512bytes。

*
