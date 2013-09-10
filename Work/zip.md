LZ77: 是一种基于字典的无损数据压缩算法（还有 LZ78, LZW 等）

deflate: 也是一种数据压缩算法，实际上就是先用 LZ77 压缩，然后用霍夫曼编码压缩

gzip: 是一种文件结构，也可以算一种压缩格式，通过 defalte 算法压缩数据，然后加上文件头和CRC校验

zlib: 是一个提供了 deflate, zlib, gzip 压缩方法的函数库；也是一种压缩格式（用 deflate 压缩数据，然后加上 zlib 头和 CRC 校验）

* [[LZ77]]
* [[zlib-format]]
* [[deflate-format]]
* [[octeon zip]]
* [[zip-tmp]]
