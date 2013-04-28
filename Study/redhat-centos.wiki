替换红帽源为cent源：

就是redhat必须注册才能使用它的源，解决方法就是使用centos的源，当然也得把红帽的
认证插件，和yum工具.

Redhat Linux无法使用yum快速安装软件解决方案

最近弄了一台阿里云服务器，安装的是RedHat5.4 64位的系统。有点奇怪的是阿里云只提
供CentOS 32位的系统，RH才有64位的。但是在使用yum的过程中报错：
 
[root@banping mysql-5.5.10]# yum install libaio-devel
 
Loaded plugins: rhnplugin, security
 
This system is not registered with RHN.
 
RHN support will be disabled.
 
Setting up Install Process
 
No package libaio-devel available.
 
Nothing to do
 
意思是这套RH没有在官网上注册，不能下载RH的软件包。后来我把yum替换成了CentOS 的
版本，过程如下：
 
首先看看有哪些yum包，然后卸载掉：
 
[root@banping mysql-5.5.10]# rpm -qa|grep yum
 
yum-rhn-plugin-0.5.4-13.el5
 
yum-3.2.22-20.el5
 
yum-metadata-parser-1.1.2-3.el5
 
yum-security-1.1.16-13.el5
 
yum-updatesd-0.9-2.el5
 
卸载要使用nodeps参数，否则由于依赖关系是无法卸载成功的：
 
rpm -e --nodeps yum-rhn-plugin-0.5.4-13.el5
 
......
 
然后可以从163的镜像下载CentOS的yum包：
 
[root@banping centos]# wget http://mirrors.163.com/centos/5/os/x86_64/CentOS/yum-3.2.22-37.el5.centos.noarch.rpm
 
[root@banping centos]# wget http://mirrors.163.com/centos/5/os/x86_64/CentOS/yum-fastestmirror-1.1.16-16.el5.centos.noarch.rpm
 
[root@banping centos]# wget http://mirrors.163.com/centos/5/os/x86_64/CentOS/yum-metadata-parser-1.1.2-3.el5.centos.x86_64.rpm
 
安装新下载的包：
 
[root@banping centos]# rpm -ivh yum-*
 
找一个CentOS的包资源配置库,名为CentOS-Base.repo，放到/etc/yum.repos.d/路径：
 
wget http://www.linuxidc.com/files/2011/05/06/CentOS-Base.repo
 
生成缓存文件到/var/cache/yum路径：
 
[root@banping yum.repos.d]# yum makecache
 
这样就可以使用CentOS的yum了。
 
centOS　　rpm下载地址http://mirrors.163.com/centos/
------------------------------------------------------------------------------
添加红帽的第三源：
安裝rpmforge-release
	wget http://dag.wieers.com/rpm/packages/rpmforge-release/rpmforge-release-0.3.6-1.el5.rf.i386.rpm
	rpm -Uvh rpmforge-release
