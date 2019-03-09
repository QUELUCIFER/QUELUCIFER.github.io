cloud native   CNCF云原生计算基金会   持续交付Continuous Delivery Martin Fowler 
  1.speed of innovation 
  2.always-available services
  3.web scale
  4.mobile-centric user experiences
  
  
container:容器虚拟化技术    容器编排与调度  namespace cgroup

单体架构:Docker  Swarm&Compose

分布式架构:[Kubernetes](https://kubernetes.io/)   [github]( https://github.com/kubernetes)      Borg-GOOGLE

[12-factors](https://12factor.net)

I. 基准代码
一份基准代码，多份部署
II. 依赖
显式声明依赖关系
III. 配置
在环境中存储配置
IV. 后端服务
把后端服务当作附加资源
V. 构建，发布，运行
严格分离构建和运行
VI. 进程
以一个或多个无状态进程运行应用
VII. 端口绑定
通过端口绑定提供服务
VIII. 并发
通过进程模型进行扩展
IX. 易处理
快速启动和优雅终止可最大化健壮性
X. 开发环境与线上环境等价
尽可能的保持开发，预发布，线上环境相同
XI. 日志
把日志当作事件流
XII. 管理进程
后台管理任务当作一次性进程运行

Linux容器技术：LXC， Open VZ，Linux-VServer
