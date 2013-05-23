  linux 下的google浏览器测试版已经发布了，前几天见师兄在用才知道，不过目前还没正式发布，官网还不能下载，可以到这里下载安装程序，或者添加第三方软件源，使用apt-get工具安装,linux测试版的chrome名称为chromium，由于发布已经有些时日，安装方法可以参见我给的连接，也可以到网上找，下面介绍如何使用chromium安装flash插件播放google音乐。
首先，使用命令检查在安装其他浏览器时是否已经安装flash插件，并定位插件的库文件
$:sudo locate libflashplayer.so
如果已经安装会返回（我的ubuntu804系统，不同系统可能有变化）：
/usr/lib/adobe-flashplugin/libflashplayer.so
/usr/lib/flashplugin-nonfree/libflashplayer.so
如果没有安装，使用$:sudo aptitude install flashplugin-installer 安装flash插件并找到 libflashplayer.so所在位置.
在成功安装了chromium和flash插件后，如何让chromium能够调用flash插件呢，其实很简单，只要把flash插件的libflashplayer.so文件复制到chromium的安装目录下的plugins目录中，查找安装目录可以使用：
$sudo find -name chromium-browser，
在我的系统中返回：
./usr/share/doc/chromium-browser
./usr/bin/chromium-browser
./usr/lib/chromium-browser
./usr/lib/chromium-browser/chromium-browser
./etc/chromium-browser
简单判断一下知道chromium安装在了/usr/lib/chromium-browser/目录中，然后复制插件文件：
$sudo cp /usr/lib/flashplugin-nonfree/libflashplayer.so  /usr/lib/chromium-browser/plugins
       最后后设置系统中的快捷方式,让chromium在每次启动时启用插件功能，不同的系统方法不固定也不唯一，给出一个参考：在桌面上方的面板上点击右键-->编辑菜单-->网络-->chromium-->单击右键-->属性-->修改命令为/usr/lib/chromium-browser/chromium-browser --enable-plugins %U  
（黄色的路径名改成自己的）
OK，现在关闭所有打开的chromium进程重启,打开http://www.google.cn/music/artist?id=Ac0784595de9d49bc，看下是不是已经能听歌了,打开www.uestc.edu.cn 呵呵，是不是flash也能正常显示了～

