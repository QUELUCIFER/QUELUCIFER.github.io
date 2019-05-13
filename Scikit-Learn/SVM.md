[链接](http://www.stardustsky.net/index.php/post/53.html)


机器学习库sklearn中svm函数特性详解
 Stardustsky   2017-10-16 17:54   6662 人阅读  0 条评论
本文可能是你能在网上找到的对svm参数解析最详细的一篇文章。写文源于之前使用到svm做攻击识别，一直纠结于一些函数的参数，对我个人自定义的一些偏好设定无法很好的完成，所以对其好好的研究了一番。这篇算是一篇工具文，来详解一下python sklearn中svm的一些参数，以及结合具体的例子来进行详细说明。

svm函数简介
sklearn中的svm基于libsvm，基础的svm函数大概如下所示，其中涉及到的参数很多，下面有一个简单的讲解：

SVC(C=1.0, cache_size=200, class_weight=None, coef0=0.0,
    decision_function_shape=None, degree=3, gamma='auto', kernel='rbf',
    max_iter=-1, probability=False, random_state=None, shrinking=True,
    tol=0.001, verbose=False)

＝＝＝＝＝＝＝＝＝参数＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝

C：C-SVC的惩罚参数C?默认值是1.0，C越大，相当于惩罚松弛变量，希望松弛变量接近0，即对误分类的惩罚增大，趋向于对训练集全分对的情况，这样对训练集测试时准确率很高，但泛化能力弱。C值小，对误分类的惩罚减小，允许容错，将他们当成噪声点，泛化能力较强。
kernel ：核函数，默认是rbf，可以是‘linear’, ‘poly’, ‘rbf’, ‘sigmoid’, ‘precomputed’ 
  　　0 – 线性：u\'v
 　　 1 – 多项式：(gamma*u\'*v + coef0)^degree
  　　2 – RBF函数：exp(-gamma|u-v|^2)
  　　3 – sigmoid：tanh(gamma*u\'*v + coef0)
degree ：多项式poly函数的维度，默认是3，选择其他核函数时会被忽略。
gamma ： ‘rbf’,‘poly’和‘sigmoid’的核函数参数。默认是’auto’，如果是auto，则值为1/n_features
coef0 ：核函数的常数项。对于‘poly’和 ‘sigmoid’有用。
probability ：是否采用概率估计？.默认为False
shrinking ：是否采用shrinking heuristic方法，默认为true
tol ：停止训练的误差值大小，默认为1e-3
cache_size ：核函数cache缓存大小，默认为200
class_weight ：类别的权重，字典形式传递。设置第几类的参数C为weight*C(C-SVC中的C)
verbose ：允许冗余输出
max_iter ：最大迭代次数。-1为无限制。
decision_function_shape ：‘ovo’, ‘ovr’ or None, default=ovr
random_state ：数据洗牌时的种子值，int值
svm参数解析
虽然上述已经对每个参数做了解释，但不够彻底，我以实际案例，分别解析一下这个函数里各个参数的具体作用以及其对最后模型的影响。

参数kernel
代表了svm的核函数，不同的核函数对最后的分类效果影响也比较大，其中precomputed表示自己提前计算好核函数矩阵，这时候算法内部就不再用核函数去计算核矩阵，而是直接用你给的核矩阵，我们说说另外的几种。

线性核函数
κ(x,xi)=x⋅xi
线性核，主要用于线性可分的情况，我们可以看到特征空间到输入空间的维度是一样的，其参数少速度快，对于线性可分数据，其分类效果很理想，因此我们通常首先尝试用线性核函数来做分类，看看效果如何，如果不行再换别的

多项式核函数
κ(x,xi)=((x⋅xi)+1)d
多项式核函数可以实现将低维的输入空间映射到高纬的特征空间，但是多项式核函数的参数多，当多项式的阶数比较高的时候，核矩阵的元素值将趋于无穷大或者无穷小，计算复杂度会大到无法计算。

高斯（RBF）核函数
κ(x,xi)=exp(−||x−xi||2δ2)
高斯径向基函数是一种局部性强的核函数，其可以将一个样本映射到一个更高维的空间内，该核函数是应用最广的一个，无论大样本还是小样本都有比较好的性能，而且其相对于多项式核函数参数要少，因此大多数情况下在不知道用什么核函数的时候，优先使用高斯核函数。

sigmoid核函数
κ(x,xi)=tanh(η<x,xi>+θ)
采用sigmoid核函数，支持向量机实现的就是一种多层神经网络。 因此，在选用核函数的时候，如果我们对我们的数据有一定的先验知识，就利用先验来选择符合数据分布的核函数；如果不知道的话，通常使用交叉验证的方法，来试用不同的核函数，误差最下的即为效果最好的核函数，或者也可以将多个核函数结合起来，形成混合核函数。在吴恩达的课上，也曾经给出过一系列的选择核函数的方法：

如果特征的数量大到和样本数量差不多，则选用LR或者线性核的SVM；
如果特征的数量小，样本的数量正常，则选用SVM+高斯核函数；
如果特征的数量小，而样本的数量很大，则需要手工添加一些特征从而变成第一种情况。
实际上使用可以对多个核函数进行测试，选择表现效果最好的核函数。

参数degree
该参数上文中也说的比较详细了，仅适用于poly，在实际应用中当数据量达到二十w以上，3层degree将会收敛的极其慢，不推荐使用。

参数gamma
这个值可能看官方文档不怎么看得懂，它是一个浮点数，作为三个核函数的参数，隐含地决定了数据映射到新的特征空间后的分布，gamma越大，支持向量越少，。gamma值越小，支持向量越多。支持向量的个数影响训练与预测的速度。

参数C
这个值官方文档说的比较明白了，就是在泛化能力和准确度间做取舍，一般来说不需要做修改，如果不需要强大的泛化能力，可减小C的值，即：C值越大，在测试集效果越好，但可能过拟合，C值越小，容忍错误的能力越强，在测试集上的效果越差。参数C和gamma是svm中两个非常重要的参数，对其值的调整直接决定了整个模型最终的好坏。

参数coef0
该参数默认值为0，是poly和sigmoid的核函数常数项，用于解决poly函数中当<x,y>值趋近，没有明显区分时，对于不同值之间差异的衡量问题，一般采用默认值0即可。在scikit-learn-svc-coef0-parameter-range这个问题中有比较详细的讲解。

参数probability
默认为False决定最后是否按概率输出每种可能的概率，但需注意最后的预测函数应改为clf.predict_proba，代码举例：

x=[[1,2,3],[11,18,16],[22,27,26],[33,34,39]]
y=[1,1,2,2]
clf=svm.SVC(probability=True,kernel='poly', degree=2,gamma=0.1,coef0=1)
clf.fit(x,y)
print clf.predict_proba([10,15,13])

output：
[[ 0.62913274  0.37086726]]
参数shrinking
该参数默认为True，即采用启发式收缩方式，如果能预知哪些变量对应着支持向量，则只要在这些样本上训练就够了，其他样本可不予考虑，这不影响训练结果，但降低了问题的规模并有助于迅速求解，起到一个加速训练的效果。

参数tol
svm停止训练的误差精度，float参数 默认为1e^-3，精度达到该标准则停止训练。

参数cache_size
该参数很明显，就是设置svm在训练时允许的缓存大小，默认为200。

参数class_weight
字典类型或者‘balance’字符串,默认为None。 给每个类别分别设置不同的惩罚参数C，如果没有给，则会给所有类别都给C=1，即前面指出的参数C.

x=[[1,2,3],[11,18,16],[22,27,26],[33,34,39]]
y=[2,1,2,3]
clf=svm.SVC(probability=True,kernel='rbf', degree=2,gamma=0.1,decision_function_shape="ovr",class_weight={1:10})
clf.fit(x,y)
print clf.predict([10,15,13])
print clf.predict_proba([10,15,13])
print clf.decision_function([10,15,13])

output:
[2]
[[ 0.23039413  0.44680601  0.32279986]]
[[ 1.01201676  2.48798324 -0.5       ]]
如果给定参数‘balance’，则使用y的值自动调整与输入数据中的类频率成反比的权重。

参数verbose
是否启用详细输出。 此设置利用libsvm中的每个进程运行时设置，如果启用，可能无法在多线程上下文中正常工作。一般情况都设为False，不用管它。以上段代码为例，开启verbose后输出结果为：

output：

[LibSVM]*
optimization finished, #iter = 1
obj = -0.000139, rho = 2.133417
nSV = 2, nBSV = 0
Total nSV = 2
*
optimization finished, #iter = 1
obj = -0.000139, rho = 2.133417
nSV = 2, nBSV = 0
Total nSV = 2
*
optimization finished, #iter = 1
obj = -0.000139, rho = 2.133417
nSV = 2, nBSV = 0
Total nSV = 2
*
optimization finished, #iter = 1
obj = -0.000057, rho = 1.013360
nSV = 2, nBSV = 0
Total nSV = 2
*
optimization finished, #iter = 1
obj = -0.000021, rho = 1.432067
nSV = 2, nBSV = 0
Total nSV = 2
*
optimization finished, #iter = 1
obj = -0.000139, rho = -2.133417
nSV = 2, nBSV = 0
Total nSV = 2
[[ 0.62917149  0.37082851]]
参数max_iter
int参数 默认为-1，最大迭代次数，如果为-1，表示不限制

参数decision_function_shape
决策函数类型，在不同版本默认值不一样。如果最后预测函数使用clf.decision_function可以看到效果，输出结果为该类到对应超平面的距离。

a.一对多法（one-versus-rest,简称1-v-r SVMs）。训练时依次把某个类别的样本归为一类,其他剩余的样本归为另一类，这样k个类别的样本就构造出了k个SVM。分类时将未知样本分类为具有最大分类函数值的那类。

b.一对一法（one-versus-one,简称1-v-1 SVMs）。其做法是在任意两类样本之间设计一个SVM，因此k个类别的样本就需要设计k(k-1)/2个SVM。当对一个未知样本进行分类时，最后得票最多的类别即为该未知样本的类别。Libsvm中的多类分类就是根据这个方法实现的。

OVR模式：
x=[[1,2,3],[11,18,16],[22,27,26],[33,34,39]]
y=[1,1,2,3]
clf=svm.SVC(probability=True,kernel='rbf', degree=2,gamma=0.1,random_state=2,decision_function_shape="ovr")
clf.fit(x,y)
print clf.predict([10,15,13])
print clf.predict_proba([10,15,13])
print clf.decision_function([10,15,13])

output：
[1]
[[ 0.34890691  0.32548254  0.32561055]]
[[ 2.5   0.75 -0.25]]

OVO模式：
x=[[1,2,3],[11,18,16],[22,27,26],[33,34,39]]
y=[1,1,2,3]
clf=svm.SVC(probability=True,kernel='rbf', degree=2,gamma=0.1,random_state=2,decision_function_shape="ovo")
clf.fit(x,y)
print clf.predict([10,15,13])
print clf.predict_proba([10,15,13])
print clf.decision_function([10,15,13])

output：
[1]
[[ 0.34890691  0.32548254  0.32561055]]
[[  5.74784310e-01   5.74784310e-01   1.42148466e-20]]
参数random_state
int型参数 默认为None, 伪随机数发生器的种子,在混洗数据时用于概率估计,没什么影响。

SVM方法及属性
方法
fit：用于训练SVM，具体参数已经在定义SVC对象的时候给出了，这时候只需要给出数据集X和X对应的标签y即可。
predict：基于以上的训练，对预测样本T进行类别预测，因此只需要接收一个测试集T，该函数返回一个数组表示个测试样本的类别。
predict_probe：基于以上的训练，对预测样本T进行类别预测，因此只需要接收一个测试集T，该函数返回一个数组表示测试样本属于每种类型的概率。
decision_function：基于以上的训练，对预测样本T进行类别预测，因此只需要接收一个测试集T，该函数返回一个数组表示测试样本到对应类型的超平面距离。
get_params：获取当前svm函数的各项参数值
score：获取预测结果准确率
import numpy as np from sklearn 
import cross_validation from sklearn 
import datasets from sklearn import svm

iris = datasets.load_iris() iris.data.shape, iris.target.shape ((150, 4), (150,))

我们现在可以很快的采样出一个训练集，并且拿出40%的数据来测试（评估）我们的估计器:

X_train, X_test, y_train, y_test = cross_validation.train_test_split(iris.data, iris.target, test_size=0.4, random_state=0)

X_train.shape, y_train.shape ((90, 4), (90,)) X_test.shape, y_test.shape ((60, 4), (60,))

clf = svm.SVC(kernel='linear', C=1).fit(X_train, y_train)
clf.score(X_test, y_test)  

output:
0.96...
set_params：设置SVC函数的参数

属性
svc.nsupport：各类各有多少个支持向量
svc.support_：各类的支持向量在训练样本中的索引
svc.supportvectors：各类所有的支持向量
intercept_ ：决策函数中的常量值
coef_：特征权重，仅适用于linear内核，来源于dual_coef_和support_vectors_属性
dualcoef ：决策函数中支持向量的系数值
参考文档
sklearn.svm.SVC

scikit-learn学习之SVM算法

本文地址：http://www.stardustsky.net/index.php/post/53.html
版权声明：本文为原创文章，版权归 Stardustsky 所有，欢迎分享本文，转载请保留出处！


