文字常量区不可修改：
* 在编译时加上 -fwriteable-strings 参数
* 先用 gcc 将  .c  文件转为 .s 文件， 然后将 .rdata 改为 .data 然后 .....
* 或者.c里面进行申明（在一个特殊的段），然后.s进行定义
