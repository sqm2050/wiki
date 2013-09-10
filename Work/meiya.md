# 标签格式
## G网
### 打印格式
<div class=box><img src=png/gn-imsi-lai.png align=middle></br>图 1 - 1</div>

* Tag-ID：9200，两个字节长度。

* Length：Tag-ID、length、IMSI、LAC、SAC、CI的长度和。`0x11 = 2 + 1 + 8 + 2 + 2 + 2`。

* IMSI：国际移动用户识别码。8个字节长度，16个BCD码值（4位二进制组），有效数位15位，最后以F（无效位）结尾。如上标签报文：`46 00 09 42 11 81 04 9f`对应IMSI号码：$460009421181049$ 。

* LAC：位置区编码，两个字节长度。

* SAC：服务区编码，两个字节长度。

* CI：Cell ID，两个字节长度。

## C网
### 打印格式
<div class=box><img src=png/cdma-msid-bsid.png align=middle></br>图 2 - 1</div>

* Tag-ID：9300，两个字节长度。

* Length：Tag-ID、length、MSID、BSID的长度和。`0x17 = 2 + 1 + 8 + 12`。

* MSID：移动台识别码。8个字节长度，16个BCD码值（4位二进制组），有效数位15位，最后以1（无效位）开头。如上标签报文：`14 60 03 60 60 06 65 14`对应MSID码：$460036060066514$。

* BSID：基站编码。12个字符的ASCII码值，如上标签报文：`33 37 41 44 30 30 30 44 30 44 39 32`对应BSID：$37AD000D0D92$。
