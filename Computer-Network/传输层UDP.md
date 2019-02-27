# 端口与套接字  传输层复用 分用
** 常用应用进程默认端口   端口16bit:应用层进程的标识  熟知端口0-1023  一般端口

DNS|DHCP|FTP|SMTP|Telnet|HTTP
-|-|-|-|-|-
UDP/53|UDP/67|TCP/21|TCP/25|TCP/23|TCP/80

### 套接字sockets = IP+端口号
五元组=[源IP, 源端口， 目的IP， 目的端口， 传输协议]


无连接服务|面向连接服务
-|-
UDP(user datagram protocol)|TCP(Translation Control Protocol)














