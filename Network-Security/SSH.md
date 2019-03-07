Secure Shell（SSH）是一种加密 网络协议，用于在不安全的网络上安全地运行网络服务。[1]典型应用包括远程命令行 登录和远程命令执行，但可以使用SSH保护任何网络服务。

SSH 在客户端 - 服务器体系结构中通过不安全的网络提供安全通道，将SSH客户端应用程序与SSH服务器连接。
协议规范区分了两个主要版本，称为SSH-1和SSH-2。SSH的标准TCP端口是22. SSH通常用于访问类Unix操作系统，但也可以在Windows上使用。Windows 10使用OpenSSH作为其默认SSH客户端。

SSH被设计为替代Telnet和不安全的远程shell协议，例如Berkeley rlogin，rsh和rexec协议。这些协议以明文形式发送信息，特别是密码，使得它们易于使用数据包分析进行拦截和泄露。
SSH使用的加密旨在通过不安全的网络（如Internet）提供数据的机密性和完整性，尽管Edward Snowden泄露的文件表明国家安全局有时可以解密SSH，允许他们读取SSH会话的内容
