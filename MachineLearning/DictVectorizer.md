[Python机器学习中的DictVectorizer（特征向量化）的使用说明](https://blog.csdn.net/Jon_Sheng/article/details/79693971)


特征转换

最近在看《PYTHON机器学习及实践+从零开始通往KAGGLE竞赛之路》这本书，

书中采用最简单直接的方式介绍了机器学习的入门实践语句，简单介绍原理以后，就开始代码实现了。

刚好看到一个例子，关于DictVectorizer的使用，很是喜欢这种操作方式，代码如下：

from sklearn.feature_extraction import DictVectorizer
 
dict_vec = DictVectorizer(sparse=False)# #sparse=False意思是不产生稀疏矩阵
 
X_train = dict_vec.fit_transform(X_train.to_dict(orient='record'))
X_test = dict_vec.transform(X_test.to_dict(orient='record'))
print(dict_vec.feature_names_)#查看转换后的列名
print(X_train)#查看转换后的训练集
['age','pclass=1st', 'pclass=2nd', 'pclass=3rd', 'sex=female', 'sex=male']
[[31.19418104  0.          0.          1.          0.          1.        ]
 [31.19418104  1.          0.          0.          1.          0.        ]
 [31.19418104  0.          0.          1.          0.          1.        ]
 ...
 [12.          0.          1.          0.          1.          0.        ]
 [18.          0.          1.          0.          0.          1.        ]
 [31.19418104  0.          0.          1.          1.          0.        ]]
原pclass和sex列如下：

full[['Pclass','Sex']].head()
	Pclass	Sex
0	3	male
1	1	female
2	3	female
3	1	female
4	3	male
即pclass和sex两列分类变量转换为了数值型变量（只有0和1），age列数值型保持不变，达到了机器学习的识别目的。



该方法可用pandas中的get_dummies实现（同样可以实现one-hot编码），操作会复杂一些，代码如下：

Pclassdf = pd.DataFrame()
Pclassdf = pd.get_dummies(full['Pclass'],prefix='Pclass')
Pclassdf.head()
	Pclass_1	Pclass_2	Pclass_3
0	0	0	1
1	1	0	0
2	0	0	1
3	1	0	0
4	0	0	1
有多少特征，就会新创建多少列，在之后用pd.concat连接即可，并且需要把原Pclass给drop掉。
--------------------- 
作者：成名在望 
来源：CSDN 
原文：https://blog.csdn.net/Jon_Sheng/article/details/79693971 
版权声明：本文为博主原创文章，转载请附上博文链接！
