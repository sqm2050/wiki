1. 首先在服务器上安装ssh的服务器端。

$ sudo aptitude install openssh-server

2. 启动ssh-server。

$ /etc/init.d/ssh restart

3. 确认ssh-server已经正常工作。

$ netstat -tlp

tcp6    0    0 *:ssh                *:*                   LISTEN     -

看到上面这一行输出说明ssh-server已经在运行了。

