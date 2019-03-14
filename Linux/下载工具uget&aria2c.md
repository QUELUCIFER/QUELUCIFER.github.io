首先是uget的安装：

1、添加uget的依赖：

sudo add-apt-repository ppa:plushuang-tw/uget-stable

2、更新依赖库（这一步需要一定的时间）：
sudo apt-get update

3、安装uget：
sudo apt-get uget

4、打开uget：
接下来是安装Aria2：

1、添加3Aria2的依赖：

sudo add-apt-repository ppa:t-tujikawa/ppa
2、更新依赖库：
sudo apt-get update

3、安装Aria2：
sudo apt-get install aria2

至此，Ubuntu环境下的下载器安装完成，将下载链接复制到uget中即可下载
--------------------- 
作者：oba没有马 
来源：CSDN 
原文：https://blog.csdn.net/u010317005/article/details/51138279 
版权声明：本文为博主原创文章，转载请附上博文链接！

0×3.使用纯终端aria2下载
　Aria2 是一个轻量级多协议多源命令行下载工具；支持 HTTP, HTTPS, FTP, SFTP, BT, Metalink等协议；下面是Aria2的常用实例：

1）下载单个文件

1
#a.下载单个文件,将要下载的文件地址包含在一对英文双引号中，aria会将文件下载到当前目录中，可以使用ctrl+c来中断下载，如果需要断点续传，只需要在相同的目录下执行相同的命令，
只要http源地址文件不变，就能直接断点续传，没有下载完的任务会同时存在两个文件，其中以.aria2结尾的文件保存着当前的下载进度和信息
2
qing@qingsword.com:~$ aria2c "http：//URL/file.zip"
3
 
4
#b.使用多连接，多线程下载单个文件，-x15同一服务器连接数15，-s15单个任务最大线程数15（比起单线程会明显快很多，一般会达到当前网络最大下载速度）
5
qing@qingsword.com:~$ aria2c -x15 -s15 "http：//URL/file.zip"
2）并行下载多个文件

01
#c.使用参数-Z（大写）并行下载任意数目的URL，每个URL用空格分隔
02
qing@qingsword.com:~$  aria2c -Z "http：//URL/file1.zip" "http：//URL/fileN.zip"
03
 
04
#d.将URL放在文本文件中，让aria2下载文本文件中所有的URL
05
qing@qingsword.com:~$ gedit TextFile
06
#每行一个URL，保存在TextFile文件中
07
http：//URL/file1.zip
08
http：//URL/file2.zip
09
......
10
http：//URL/fileN.zip
11
#-i后面是文件名，-j3表示，一次并行下载这个文件中的3条URL文件
12
qing@qingsword.com:~$ aria2c -i TextFile -j3
3）下载BT和磁力链接

01
#e.显示一个.torrent文件中的内容
02
qing@qingsword.com:~$ aria2c -S  "file.torrent"
03
 
04
#f.直接解析URL中的种子文件内容下载
05
qing@qingsword.com:~$ aria2c "http：//URL/file.torrent"
06
 
07
#g.解析本地种子文件内容下载
08
qing@qingsword.com:~$ aria2c "file.torrent"
09
 
10
#h.限制上传速度为20K，当下载速度低于100K时，尝试增加连接数来提高下载速度
11
qing@qingsword.com:~$ aria2c -u20K --bt-request-peer-speed-limit=200K "file.torrent"
12
 
13
#i.下载磁力连接
14
qing@qingsword.com:~$ aria2c "magnet:?xxx"
15
 
16
#j.选择下载种子中的哪些文件，配合-S参数使用，先列出种子文件内容，再根据内容选择下载哪几个文件,本例选择下载种子文件中第1~3以及第6个文件
17
qing@qingsword.com:~$ aria2c --select-file=1-3,6 -T "file.torrent"
4）使用本地配置文件中的属性

上面的例子中的所有属性都可以直接写在aria2的本地配置文件aria2.conf中，在使用aria2下载的时候，只需要在aria2c后面写上文件或者bt连接地址就可以了，
aria2会自动调用本地配置文件中的参数下载；

01
#k.创建本地配置文件
02
qing@qingsword.com:~$ gedit ~/.aria2/aria2.conf
03
#在文件中输入下面的内容，请根据自己的环境修改部分参数（比如下载文件夹，监听端口等）
04
 
05
# '#'开头为注释内容, 选项都有相应的注释说明, 根据需要修改
06
#被注释的选项填写的是默认值, 建议在需要修改时再取消注释
07
## 基本选项 ##
08
# 文件的保存路径(可使用绝对路径或相对路径，推荐使用绝对路径), 默认: 当前启动位置
09
dir=/home/qing/download
10
# 文件预分配方式, 能有效降低磁盘碎片, 默认:prealloc
11
# 预分配所需时间: none < falloc < trunc < prealloc
12
# falloc和trunc则需要文件系统和内核支持
13
# NTFS建议使用falloc, EXT3/4建议trunc, MAC 下需要注释此项
14
file-allocation=trunc
15
# 断点续传，目前只支持 HTTP/HTTPS/FTP 协议
16
continue=true
17
  
18
## 下载连接相关 ##
19
# 最大同时下载任务数, 运行时可修改, 默认:5
20
max-concurrent-downloads=20
21
# 同一服务器连接数, 添加时可指定, 默认:1
22
max-connection-per-server=15
23
# 单个任务最大线程数, 添加时可指定, 默认:5
24
split=5
25
# 整体下载速度限制,单位K或M, 运行时可修改, 默认:0
26
#max-overall-download-limit=0
27
# 单个任务下载速度限制, 默认:0
28
#max-download-limit=0
29
# 整体上传速度限制, 运行时可修改, 默认:0
30
#max-overall-upload-limit=10K
31
# 单个任务上传速度限制, 默认:0
32
#max-upload-limit=0
33
  
34
  
35
## RPC相关设置 ##
36
# 启用RPC, 默认:false
37
enable-rpc=true
38
# 允许所有来源, 默认:false
39
rpc-allow-origin-all=true
40
# 允许非外部访问, 默认:false
41
rpc-listen-all=true
42
# RPC监听端口, 端口被占用时可以修改, 默认:6800
43
rpc-listen-port=51112
44
# 设置的RPC授权令牌, v1.18.4新增功能, 取代 --rpc-user 和 --rpc-passwd 选项
45
#rpc-secret=TOKEN
46
# 设置的RPC访问用户名, 此选项新版已废弃, 建议改用 --rpc-secret 选项
47
#rpc-user=USER
48
# 设置的RPC访问密码, 此选项新版已废弃, 建议改用 --rpc-secret 选项
49
#rpc-passwd=PASSWD
50
  
51
## BT/PT下载相关 ##
52
# 当下载的是一个种子(以.torrent结尾)时, 自动开始BT任务, 默认:true
53
#follow-torrent=true
54
# BT监听端口, 当端口被屏蔽时使用, 默认:6881-6999
55
listen-port=51111
56
# 单个种子最大连接数, 默认:55
57
bt-max-peers=500
58
# 打开DHT功能, PT需要禁用, 默认:true
59
enable-dht=true
60
# 打开IPv6 DHT功能, PT需要禁用
61
#enable-dht6=true
62
# DHT网络监听端口, 默认:6881-6999
63
dht-listen-port=16881-16999
64
# 客户端伪装, PT需要
65
peer-id-prefix=-TR2770-
66
user-agent=Transmission/2.77
67
# 继续之前的BT任务时, 无需再次校验, 默认:false
68
bt-seed-unverified=true
69
# 保存磁力链接元数据为种子文件(.torrent文件), 默认:false
70
bt-save-metadata=true
71
# 当速度总是低于200K/s，aria2将临时增加连接数来试着提高下载速度
72
bt-request-peer-speed-limit=100K
73
# 下载完成多少分钟后停止做种，本例设置为1分钟
74
seed-time=1
Ps：经过测试，aria2对热门的bt资源下载速度可以达到带宽上限，对于一些冷门的资源，建议大家用迅雷离线下好后再以上方法下载到本地。另外，aria2的本地配置文件与uGet并不兼容，
创建了本地aria2.conf后会导致uGet启动后不能启动aria2，所以，建议大家选择一种自己喜欢的下载方式，或者不创建本地配置文件，在使用aria2终端下载的时候手动添加一些常用参数。

0×4.使用纯终端wget下载
纯终端下除了aria2之外，还有一个十分常用的下载器wget，使用方法如下：

01
#1.在ubuntu上的安装
02
www@qingsword.com:~$ sudo apt-get install wget
03
 
04
#2.常用参数介绍
05
-c 断点续传
06
-P 指定下载目录
07
-O 常用于重命名下载文件
08
 
09
#3.实例一，下载单个文件保存到终端所在目录的www.qingsword.com目录下（如果不指定目录，就是下载到当前目录中）
10
www@qingsword.com:~$ wget -c -P /www.qingsword.com "要下载的文件URL地址"
11
 
12
#4.实例二，后台下载
13
www@qingsword.com:~$ wget -cb "要下载的文件URL地址"
14
在后台运行，pid 为 7461。 #后台进程ID
15
将把输出写入至 “wget-log”。#下载进度文件
16
 
17
#查看下载进度（上面的输出写入的是哪个文件，下面的tail命令就查看哪个文件，因为在相同目录中同时在后台下载多个文件时，输出会写入不同的wget-log文件，例如wget-log.1,wget-log.2等等）
18
www@qingsword.com:~$ tail -f wget-log
19
 
20
#5.实例三，将下载的文件重命名为qingsword.exe保存
21
www@qingsword.com:~$ wget -c -O qingsword.exe "要下载的文件URL地址"


