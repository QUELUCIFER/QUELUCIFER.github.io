
文章目录

##生成模型
生成模型，即，一个数据分布为P的模型，P的分布和[Math Processing Error] P_{gt}(X)P 
gt
​	
 (X) 几乎相似(gt应该是生成分布的意思(generative distribution))，那[Math Processing Error] P_{gt}(X)P 
gt
​	
 (X) 是什么呢？这便是我们假设的样本数据X所服从的未知分布，即：
[Math Processing Error] X\sim P_{gt}(X) \tag{1}
X∼P 
gt
​	
 (X)(1)

当我们学习得到一个生成模型时，便可以从该模型采样(sample)获取近似真实数据的样本。
举例：假设数据是图片，目的是从图片学习生成模型。每一张图片由像素(pixels)组合决定，即整个图片的像素是一个高维度分布，像素与像素之间存在相关性，比如靠近的像素之间颜色接近，
某部分像素的组合形成一个目标，比如图片是一只狗，那某一部分的像素组合构成狗的耳朵鼻子之类，但是这样的分布关系是很难用推理的方式学习得到的，而生成模型+神经网络便可以捕获这样的分布关系。
##隐变量

直觉理解：假设输入的是一张猫的图片，隐变量可以是“腿的个数”/“耳朵的大小”等。
形式化：
z是隐变量，[Math Processing Error] z\in \mathcal Zz∈Z ,[Math Processing Error] \mathcal ZZ 表示隐变量z服从的高维空间，方便我们从定义在 
[Math Processing Error] \mathcal ZZ 上的PDF(概率密度函数)P(z)上采样。
对于真实数据样本 [Math Processing Error] \mathrm XX 中的每一个样本x，隐变量都有一个或多个setting(即映射关系)可以生产相似的x,所以可以合理的假设隐变量属于一类函数族
[Math Processing Error] f(z; \theta)f(z;θ) ,参数 [Math Processing Error] \theta \in\mathcal \Thetaθ∈Θ,
则函数为[Math Processing Error] f:\mathcal Z \times \Theta \rightarrow \mathrm Xf:Z×Θ→X。
f是一个确定的函数，当固定参数 [Math Processing Error] \thetaθ后，由于z是随机变量，则 函数 [Math Processing Error] f(z; \theta)f(z;θ) 是一个等价于自变量x的概率密度函数 ,
即空间 [Math Processing Error] \mathrm XX内的随机变量。
目标便是优化参数 [Math Processing Error] \thetaθ使得因变量z的采样有很高的概率是P(z)中得到的，注意p(z)的定义就是为了近似真实数据X，隐变量必须服从的分布，
这个分布p(z)在学习过程中越来越达到符合它的定义要求。
##编码器
传统的编码器：


也就是x作为输入，要努力使输出 [Math Processing Error] \hat x 
x
^
 接近x，最终使用的是中间的隐层向量，作为输入x的特征。
VAE是结合了 隐变量(latent variable) 的Auto-Encoder。

公式：
由形式化3及连续随机变量的概率密度函数公式：
[Math Processing Error] P(X) = \int f(z;\theta)dz \tag{2}
P(X)=∫f(z;θ)dz(2)
由全概率公式改变公式(2)：
[Math Processing Error] P(x)=\int P(X|z;\theta)P(z)dz \tag{3}
P(x)=∫P(X∣z;θ)P(z)dz(3)


由边缘分布完全由原分布F确定的事实，如果知道了[Math Processing Error] P(X,z)P(X,z) ,便知道了[Math Processing Error] P(X\vert z)P(X∣z) 和
[Math Processing Error] P(z)P(z) …

VAE的idea是用[Math Processing Error] P(z\vert X)P(z∣X) 去推理[Math Processing Error] P(z)P(z) ,推理的方法称为VI(Variational Inference),
是属于bayesian inference的方法
之一，另一个是MCMC方法。
VI的主要想法是把用一个优化问题去近似该推理问题。(KL-divergence metric).
但是手动去设计z向量显然是不可操作的，于是VAE假设，z的某个维度并不能简单地解释，并且[Math Processing Error] z\sim N(0,I)z∼N(0,I)。即便有这样的先验假设，
只要映射函数足够复杂（P(X|z)），最终的P(X)也可以足够复杂。

但是这里还有一个问题，即，对于大多数的z，P(X|z)=0，直接去做积分是一个很没有必要的劳动。

于是有人提出，学一个Q(z|X)，这个Q可以根据某个X，返回可能的z的分布。我们希望这里的z是比较可能产生X的，即P(X|z)>0，并且这里的z的空间比一开始z的空间要小。这样的话，计算 
[Math Processing Error] E_{z\sim Q}P(X|z)E 
z∼Q
​	
 P(X∣z) 去代替上面的积分(z服从Q分布函数)，会更简单。
下面计算Q(Z|X)和P(z|X)的KL散度：
[Math Processing Error] D_{KL}[Q(z|X)\Vert P(z|X)]=\sum_z Q(z|X)log \frac{Q(z|X)}{P(z|X)} \\=E_{z\sim Q}[log\frac{Q(z|X)}{P(z|X)}] \\=
E_{z\sim Q}[logQ(z|X) - logP
(z|X)]\\=E_{z \sim Q}[logQ(z|X) - log\frac{P(X|z)P(z)}{P(X)}]\\=E_{z\sim Q}[logQ(z|X)-logP(X|z)-logP(z)+logP(X)]\tag{4}
D 
KL
​	
 [Q(z∣X)∥P(z∣X)]= 
z
∑
​	
 Q(z∣X)log 
P(z∣X)
Q(z∣X)
​	
 
=E 
z∼Q
​	
 [log 
P(z∣X)
Q(z∣X)
​	
 ]
=E 
z∼Q
​	
 [logQ(z∣X)−logP(z∣X)]
=E 
z∼Q
​	
 [logQ(z∣X)−log 
P(X)
P(X∣z)P(z)
​	
 ]
=E 
z∼Q
​	
 [logQ(z∣X)−logP(X∣z)−logP(z)+logP(X)](4)

交换[Math Processing Error] logP(X)logP(X) 到左边：
[Math Processing Error] logP(X)-D_{KL}[Q(z|X)\Vert P(z|X)]=E_{z\sim Q}[logP(X|z)]-(logQ(z|X)-logP(z))]\\=E_{z\sim Q}[logP(X|z)]-E_{z\sim Q}[logQ(z|X)-logP(z)]
\\=E_{z\sim Q}[logP(X|z)]-D_{KL}[Q(z|X)\Vert P(z)]\tag{5}
logP(X)−D 
KL
​	
 [Q(z∣X)∥P(z∣X)]=E 
z∼Q
​	
 [logP(X∣z)]−(logQ(z∣X)−logP(z))]
=E 
z∼Q
​	
 [logP(X∣z)]−E 
z∼Q
​	
 [logQ(z∣X)−logP(z)]
=E 
z∼Q
​	
 [logP(X∣z)]−D 
KL
​	
 [Q(z∣X)∥P(z)](5)

得到了VAE的核心方程(目标函数)：
[Math Processing Error] logP(X)-D_{KL}[Q(z|X)\Vert P(z|X)]=E_{z\sim Q}[logP(X|z)]-D_{KL}[Q(z|X)\Vert P(z)]\tag{6}
logP(X)−D 
KL
​	
 [Q(z∣X)∥P(z∣X)]=E 
z∼Q
​	
 [logP(X∣z)]−D 
KL
​	
 [Q(z∣X)∥P(z)](6)

等式的左边：
[Math Processing Error] logP(X)logP(X) 是用来对数据分布建模的对数似然函数，是要最大化的对象；
2.[Math Processing Error] -D_{KL}[Q(z|X)\Vert P(z|X)]−D 
KL
​	
 [Q(z∣X)∥P(z∣X)] 是使用[Math Processing Error] Q(z|X)Q(z∣X) 代替[Math Processing Error] P(z|X)P(z∣X) 时的产生的误差项。
于是左边整体理解成：我们要找一个[Math Processing Error] logP(X)logP(X) 的下界函数；那我们求解等式右侧就行了。

等式的右边：这部分是我们可以用随机梯度下降去优化的部分。
[Math Processing Error] E_{z\sim Q}[logP(X|z)]E 
z∼Q
​	
 [logP(X∣z)] 是Decoder的目标函数，即如果把z理解成输入，X是输出，则[Math Processing Error] E_{z\sim Q}[logP(X|z)]E 
z∼Q
​	
 [logP(X∣z)] 是极大似然函数，即在模型参数下去优化条件分布[Math Processing Error] P(X \vert z)P(X∣z)，这可以用任何分类器的损失函数作为目标函数。
[Math Processing Error] -D_{KL}[Q(z|X)\Vert P(z)]−D 
KL
​	
 [Q(z∣X)∥P(z)] 是Encoder的目标函数，要训练一个使Q(z|X)尽可能接近P(z)的Encoder。
之前我们已经限定[Math Processing Error] z∼N(0,I)z∼N(0,I)，现在再限定[Math Processing Error] Q(z|X)Q(z∣X) 服从参数是[Math Processing Error] μ(X)μ(X) 和[Math 
ProcessingError] Σ(X)Σ(X) 的高斯分布。这时，右边第二项是有准确表达式的：
[Math Processing Error] D_{KL}[N(\mu(X),\Sigma(X))\Vert N(0,1)] = \frac{1}{2}\sum_k(exp(\Sigma(X))+\mu^2(X)-1-\Sigma(X))\tag{7}
D 
KL
​	
 [N(μ(X),Σ(X))∥N(0,1)]= 
2
1
​	
  
k
∑
​	
 (exp(Σ(X))+μ 
2
 (X)−1−Σ(X))(7)

至于右边第一个表达式，我们可以使用二次损失函数(交叉熵)替代。

![pic](https://raw.githubusercontent.com/zhengchu1994/images/master/VAE/VAE%201.png)

这里为了训练的方便，使用了重参数技巧（reparameterization trick），即，引入一个随机性变量：[Math Processing Error] \epsilon \sim N(0,1),z=\mu(X)+ \Sigma^{\frac{1}{2}}
(X)*
\epsilonϵ∼N(0,1),z=μ(X)+Σ 
2
1
​	
 
 (X)∗ϵ ，这样使得网络反向传播时没有涉及到随机变量。


###补充一下似然函数
--------------------- 
作者：NockinOnHeavensDoor 
来源：CSDN 
原文：https://blog.csdn.net/NockinOnHeavensDoor/article/details/80351283 
版权声明：本文为博主原创文章，转载请附上博文链接！

### TF
        import tensorflow as tf
        import numpy as np
        import matplotlib.pyplot as plt
        import matplotlib.gridspec as gridspec
        import os
        from tensorflow.examples.tutorials.mnist import input_data


       mnist = input_data.read_data_sets('../../MNIST_data', one_hot=True)
       mb_size = 64 #minibatch的大小
       z_dim = 100  #隐变量z的维度
       X_dim = mnist.train.images.shape[1]  #784 #图片平展后的维度
       y_dim = mnist.train.labels.shape[1] #10 #0—9的标签
       h_dim = 128 #隐层维度
       c = 0
       lr = 1e-3


      def plot(samples):
         fig = plt.figure(figsize=(4, 4))
         gs = gridspec.GridSpec(4, 4)
         gs.update(wspace=0.05, hspace=0.05)

       for i, sample in enumerate(samples):
           ax = plt.subplot(gs[i])
           plt.axis('off')
           ax.set_xticklabels([])
           ax.set_yticklabels([])
           ax.set_aspect('equal')
           plt.imshow(sample.reshape(28, 28), cmap='Greys_r')

       return fig


       def xavier_init(size):
            in_dim = size[0]
            xavier_stddev = 1. / tf.sqrt(in_dim / 2.)
        return tf.random_normal(shape=size, stddev=xavier_stddev)


### =============================== Q(z|X) ======================================

             X = tf.placeholder(tf.float32, shape=[None, X_dim])#(None,784)
z = tf.placeholder(tf.float32, shape=[None, z_dim])#(None,100)

Q_W1 = tf.Variable(xavier_init([X_dim, h_dim])) #(784,128)
Q_b1 = tf.Variable(tf.zeros(shape=[h_dim]))    #128

Q_W2_mu = tf.Variable(xavier_init([h_dim, z_dim])) #(128, 100)
Q_b2_mu = tf.Variable(tf.zeros(shape=[z_dim])) #100

Q_W2_sigma = tf.Variable(xavier_init([h_dim, z_dim])) #(128,100)
Q_b2_sigma = tf.Variable(tf.zeros(shape=[z_dim]))   #(100)


def Q(X):
    h = tf.nn.relu(tf.matmul(X, Q_W1) + Q_b1) #(None,128)
    z_mu = tf.matmul(h, Q_W2_mu) + Q_b2_mu   #(None,100)
    z_logvar = tf.matmul(h, Q_W2_sigma) + Q_b2_sigma #(None,100)
    return z_mu, z_logvar


def sample_z(mu, log_var):
    eps = tf.random_normal(shape=tf.shape(mu))
    return mu + tf.exp(log_var / 2) * eps


# =============================== P(X|z) ======================================

P_W1 = tf.Variable(xavier_init([z_dim, h_dim])) #(100,128)
P_b1 = tf.Variable(tf.zeros(shape=[h_dim]))   #128

P_W2 = tf.Variable(xavier_init([h_dim, X_dim])) #(128,784)
P_b2 = tf.Variable(tf.zeros(shape=[X_dim])) #784


def P(z):
    h = tf.nn.relu(tf.matmul(z, P_W1) + P_b1)  (,128)
    logits = tf.matmul(h, P_W2) + P_b2   (,784)
    prob = tf.nn.sigmoid(logits)
    return prob, logits


# =============================== TRAINING ====================================

z_mu, z_logvar = Q(X)   #真实数据X中获取关于得到隐变量z的信息
z_sample = sample_z(z_mu, z_logvar)   #从信息采样得到隐变量z样本
_, logits = P(z_sample) #拿隐变量z样本进行采样得到真实数据的logits

# Sampling from random z
X_samples, _ = P(z)

# E[log P(X|z)] #重构损失
recon_loss = tf.reduce_sum(tf.nn.sigmoid_cross_entropy_with_logits(logits=logits, labels=X), 1)
# D_KL(Q(z|X) || P(z)); calculate in closed form as both dist. are Gaussian
#公式(7)的计算
kl_loss = 0.5 * tf.reduce_sum(tf.exp(z_logvar) + z_mu**2 - 1. - z_logvar, 1)
# VAE loss
vae_loss = tf.reduce_mean(recon_loss + kl_loss)

solver = tf.train.AdamOptimizer().minimize(vae_loss)

sess = tf.Session()
sess.run(tf.global_variables_initializer())

if not os.path.exists('out/'):
    os.makedirs('out/')

i = 0

for it in range(1000000):
    X_mb, _ = mnist.train.next_batch(mb_size) #标签没用
                        #同时运行solver和vae_loss的列表
    _, loss = sess.run([solver, vae_loss], feed_dict={X: X_mb})

    if it % 1000 == 0:
        print('Iter: {}'.format(it))
        print('Loss: {:.4}'. format(loss))
        print()

        samples = sess.run(X_samples, feed_dict={z: np.random.randn(16, z_dim)})

        fig = plot(samples)
        plt.savefig('out/{}.png'.format(str(i).zfill(3)), bbox_inches='tight')
        i += 1
        plt.close(fig)


### pytorch

        import torch
import torch.nn.functional as nn
import torch.autograd as autograd
import torch.optim as optim
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec
import os
from torch.autograd import Variable
from tensorflow.examples.tutorials.mnist import input_data


mnist = input_data.read_data_sets('../../MNIST_data', one_hot=True)
mb_size = 64
Z_dim = 100
X_dim = mnist.train.images.shape[1]
y_dim = mnist.train.labels.shape[1]
h_dim = 128
c = 0
lr = 1e-3


def xavier_init(size):
    in_dim = size[0]
    xavier_stddev = 1. / np.sqrt(in_dim / 2.)
    return Variable(torch.randn(*size) * xavier_stddev, requires_grad=True)


# =============================== Q(z|X) ======================================

Wxh = xavier_init(size=[X_dim, h_dim])
bxh = Variable(torch.zeros(h_dim), requires_grad=True)

Whz_mu = xavier_init(size=[h_dim, Z_dim])
bhz_mu = Variable(torch.zeros(Z_dim), requires_grad=True)

Whz_var = xavier_init(size=[h_dim, Z_dim])
bhz_var = Variable(torch.zeros(Z_dim), requires_grad=True)


def Q(X):
    h = nn.relu(X @ Wxh + bxh.repeat(X.size(0), 1))
    z_mu = h @ Whz_mu + bhz_mu.repeat(h.size(0), 1)
    z_var = h @ Whz_var + bhz_var.repeat(h.size(0), 1)
    return z_mu, z_var


def sample_z(mu, log_var):
    eps = Variable(torch.randn(mb_size, Z_dim))
    return mu + torch.exp(log_var / 2) * eps


# =============================== P(X|z) ======================================

Wzh = xavier_init(size=[Z_dim, h_dim])
bzh = Variable(torch.zeros(h_dim), requires_grad=True)

Whx = xavier_init(size=[h_dim, X_dim])
bhx = Variable(torch.zeros(X_dim), requires_grad=True)


def P(z):
    h = nn.relu(z @ Wzh + bzh.repeat(z.size(0), 1))
    X = nn.sigmoid(h @ Whx + bhx.repeat(h.size(0), 1))
    return X


# =============================== TRAINING ====================================

params = [Wxh, bxh, Whz_mu, bhz_mu, Whz_var, bhz_var,
          Wzh, bzh, Whx, bhx]

solver = optim.Adam(params, lr=lr)

for it in range(100000):
    X, _ = mnist.train.next_batch(mb_size)
    X = Variable(torch.from_numpy(X))

    # Forward
    z_mu, z_var = Q(X)
    z = sample_z(z_mu, z_var)
    X_sample = P(z)

    # Loss
    recon_loss = nn.binary_cross_entropy(X_sample, X, size_average=False) / mb_size
    kl_loss = torch.mean(0.5 * torch.sum(torch.exp(z_var) + z_mu**2 - 1. - z_var, 1))
    loss = recon_loss + kl_loss

    # Backward
    loss.backward()

    # Update
    solver.step()

    # Housekeeping
    for p in params:
        if p.grad is not None:
            data = p.grad.data
            p.grad = Variable(data.new().resize_as_(data).zero_())

    # Print and plot every now and then
    if it % 1000 == 0:
        print('Iter-{}; Loss: {:.4}'.format(it, loss.data[0]))

        samples = P(z).data.numpy()[:16]

        fig = plt.figure(figsize=(4, 4))
        gs = gridspec.GridSpec(4, 4)
        gs.update(wspace=0.05, hspace=0.05)

        for i, sample in enumerate(samples):
            ax = plt.subplot(gs[i])
            plt.axis('off')
            ax.set_xticklabels([])
            ax.set_yticklabels([])
            ax.set_aspect('equal')
            plt.imshow(sample.reshape(28, 28), cmap='Greys_r')

        if not os.path.exists('out/'):
            os.makedirs('out/')

        plt.savefig('out/{}.png'.format(str(c).zfill(3)), bbox_inches='tight')
        c += 1
        plt.close(fig)


参考来源:https://wiseodd.github.io/
        

