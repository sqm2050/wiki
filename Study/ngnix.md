wget http://nginx.org/download/nginx-1.0.13.tar.gz  


2.安装ngnix所依赖的环境 
Java代码  
yum install gcc gcc-c++ openssl-devel pcre-devel  
yum install gcc-c++  
yum install openssl-devel  
yum install pcre-devel  


3.解压ngnix，并且做相关调整 
关闭debug模式，在ngnix源码目录中找到/ngnix/auto/cc,编辑gcc文件，删除 # debug CFLAGS="$CFLAGS -g" 
修改herder信息，到/ngnix/src/core,编辑ngnix.h文件，修改服务器信息就ok了。、 

4.安装ngnix 
Java代码  
./configure --prefix=/opt/nginx --with-mail --with-mail_ssl_module --without-http-cache --without-http_fastcgi_module --without-http_uwsgi_module --without-http_scgi_module  --with-http_stub_status_module --without-http_memcached_module --with-http_gzip_static_module  --with-http_ssl_module  --with-cc-opt=-O4  
make && make install  
