[链接](https://zhuanlan.zhihu.com/p/43630912)

任何参与过机器学习比赛的人，都能深深体会特征工程在构建机器学习模型中的重要性，它决定了你在比赛排行榜中的位置。

特征工程具有强大的潜力，但是手动操作是个缓慢且艰巨的过程。Prateek Joshi，是一名数据科学家，花了不少时间研究多种特征，并从不同角度分析其可行性。

现在，整个特征工程过程可实现自动化，他将通过这篇文章进行详细介绍。


下面会使用Python特征工程库Featuretools来实现这个任务。在讨论之前，我们先介绍特征工程的基本组成，再用直观例子来理解它们，最后把自动特征工程应用到BigMart Sales数据集中验证实际效果。

本文目录
1. 特征是什么
2. 特征工程
3. 特征工程必要性
4. 自动特征工程
5. Featuretools简介
6. Featuretools实现
7. Featuretools可解释性

1 特征
在机器学习中，特征可以描述为解释现象发生的一组特点。当这些特点转换为一些可测量的形式时，它们就称作特征。

例如，在一个学生列表中，包含每个学生的姓名name、学习小时数study_hours、智商IQ和先前考试的总分数marks。现在给你一个新学生，他的信息只有学习小时数和智商，他的总分数缺失，你需要来估计他可能的分数值。

在这里，你要使用智商值和学习小时数构建预测模型来估计这些缺失值。因此，智商值和学习小时数称作这个模型的特征。


2 特征工程
特征工程可以简单定义为从数据集的已有特征创建新特征的过程。

下面是一个样本数据，包括每个项目的详细信息，如它们的重量Item_Weight和价格Item_Price。


现在，我们可以使用重量和价格创建新特征，于是创建了一个名为Price_per_Weight的特征，它指的是物品的单位质量价格。这个过程叫做特征工程。


这只是利用已有特征创建新特征的一个简单示例，而在实际应用中，当特征数量较多时，特征工程可能会变得相当复杂和繁琐。

下面是另一个例子。在经典的Titanic数据集中，有个特征为乘客姓名，下面是这个数据集中的一些名字：

Montvila, Rev. Juozas
Graham, Miss. Margaret Edith
Johnston, Miss. Catherine Helen “Carrie”
Behr, Mr. Karl Howell
Dooley, Mr. Patrick
实际上，这些姓名可以分解为其他有意义的特征。比如，我们把相似称号提取并分到单个类别。下面是乘客姓名中各个称号的对应频率。


事实上，有些称号，如’Dona’, ‘Lady’, ‘Countess’, ‘Capt’, ‘Col’, ‘Don’, ‘Dr’, ‘Major’, ‘Rev’, ‘Sir’和’Jonkheer ‘，出现频率很低，可以划为同一类，作为rare_title类。此外，称号’Mlle’和’Ms’可以放在’Miss’中，’Mme’可以用’Mrs’替换。


新的称号特征只有5个唯一值，如下所示：


因此，这就是我们借助特征工程来提取有用信息的过程，甚至能从最初看起来毫无意义的乘客名称中提取特征。

3 特征工程必要性
一个预测模型的性能很大程度上取决于训练该模型的数据集的特征质量。

如果能创建新特征来帮助向模型提供有关目标变量的更多信息，那么它的性能将会提升。因此，当数据集中没有足够有用特征时，我们必须依靠特征工程。

在Kaggle竞赛“自行车共享需求预测（Bike Sharing Demand Prediction）”中，参与者被要求根据历史模式（包括使用情况，及对应的天气、时间和其他数据）来预测华盛顿地区的租赁需求。

在一篇获胜者分享中也提到，智能特征工程有助于提高模型性能。他创建的一些特征如下：

1. Hour Bins：利用决策树分箱小时级别特征来创建新特征；
2. Hour Bins：类似地，温度变量的分箱特征；
3. Year Bins：为持续2年的数据创建了8个季度分箱；
4. Day Type：当天类型，分为工作日、周末和假日。

分享全文见：https://www.analyticsvidhya.com/blog/2015/06/solution-kaggle-competition-bike-sharing-demand/

创建这样特征并非一件容易的事，它需要大量的头脑风暴和广泛的数据探索。但是，并非所有人都擅长特征工程，因为无法通过阅读书籍或观看教程学到这些东西。这就是特征工程也被称为艺术的原因。如果你擅长它，那么你在竞赛中占据较大优势。

4 自动特征工程

分析上面的两张图片，左图展示了20世纪初一群人在组装汽车，右图展示了如今机器人在做着同样工作。自动化任何流程都有可能使其更加高效且节约成本。同样地，特征工程可以并且已经在机器学习中实现自动化。

构建机器学习模型通常是一个艰苦且乏味的过程。它涉及多个步骤，因此如果我们能够自动执行一定比例的特征工程任务，那么数据科学家或工程师可以专注于模型的其他方面。

我们已经了解自动特征工程十分有用，那你可能会问，该如何把它应用到模型中？别担心，已经有一个很好的Python工具库解决了这个问题，那就是Featuretools。

5 Featuretools简介

Featuretools是一个用于执行自动特征工程的开源库，旨在快速推进特征生成过程，从而有更多时间专注于机器学习模型构建的其他方面。

在使用Featuretools之前，我们要了解这个库的三个主要组件：

实体Entities
深度特征合成Deep Feature Synthesis
特征基元Feature primitives
实体可看作是Pandas中数据帧的表征，多个实体的集合称为实体集Entityset。

深度特征合成（DFS）与深度学习无关。作为一种特征工程方法，它实际上是Featuretools库的核心。它支持从单个数据帧和多个数据帧中创建新特征。

DFS通过把特征基元应用于实体集中的实体关系来创建特征。这些基元经常被用来手动生成特征，比如，基元“mean”可在聚合级别找到变量均值。

千看不如一练，熟悉Featuretools的最佳方法是多在数据集中尝试。因此，我们会在下部分使用BigMart Sales数据集来巩固概念。

6 Featuretools实现
BigMart Sales数据集面临的挑战是建立一个预测模型来估算某个商店中每种产品的销售额。这将有助于BigMart决策者寻找每个产品或商店的特性，这对提高整体销售额起着关键作用。在给定数据集中，包括10个商店中的1559种产品。

下表给出了数据中提供的特征：


数据集下载地址：
Big Mart Sales III

6.1 安装
Featuretools适用于Python 2.7、3.5和3.6，可使用pip命令快速安装Featuretools。

pip install featuretools
6.2 加载外部库和数据
import featuretools as ft 
import numpy as np 
import pandas as pd 
train = pd.read_csv("Train_UWu5bXk.csv") 
test = pd.read_csv("Test_u94Q5KV.csv")
6.3 准备数据
首先，我们把目标Item_Outlet_Sales存储到sales变量，把test_Item_Identifier和test_Outlet_Identifier存储到id变量。

# saving identifiers 
test_Item_Identifier = test['Item_Identifier'] test_Outlet_Identifier = test['Outlet_Identifier'] 
sales = train['Item_Outlet_Sales'] 
train.drop(['Item_Outlet_Sales'], axis=1, inplace=True)
然后，组合训练集和测试集，这样省去两次执行相同步骤的麻烦。

combi = train.append(test, ignore_index=True)
接着，检查数据集中的缺失值。

combi.isnull().sum()

变量Item_Weight和Outlet_size中有相当多缺失值，用下面方法快速处理：

# imputing missing data 
combi['Item_Weight'].fillna(combi['Item_Weight'].mean(), 
                            inplace = True) 
combi['Outlet_Size'].fillna("missing", inplace = True)
6.4 数据预处理
这里不会涉及过多预处理操作，因为本文的主要目的是介绍Featuretools。

combi['Item_Fat_Content'].value_counts()

Item_Fat_Content似乎只包含两个类别，即“低脂”和“常规”，未涉及到“冗余”类别，所以我们把它转换成二进制变量。

# dictionary to replace the categories 
fat_content_dict = {'Low Fat':0, 'Regular':1, 'LF':0, 'reg':1, 
                    'low fat':0} 
combi['Item_Fat_Content'] = combi['Item_Fat_Content'].replace(   
                            fat_content_dict, regex=True)
6.5 使用Featuretools执行特征工程
在这节，我们要使用Featuretools来执行自动特征工程。

对于数据集，必须具有唯一标识符特征，但是我们的数据集目前还没有。因此，我们要为这个组合数据集创建唯一ID。你可能会注意到，数据集中有两个ID，一个用于item，另一个用于outlet。因此，对这两者简单相加会得到一个唯一ID。

combi['id'] = combi['Item_Identifier'] + combi['Outlet_Identifier'] 
combi.drop(['Item_Identifier'], axis=1, inplace=True)
要注意，由于不再需要，我删除了特征Item_Identifier。但是，我保留了特征Outlet_Identifier，因为我稍后还要用到它。

接着，我们要创建一个实体集EntitySet。实体集是一种包含多个数据帧及其之间关系的结构。那么，我们创建一个EntitySet并添加数据帧组合。

# creating and entity set 'es' 
es = ft.EntitySet(id = 'sales') 
# adding a dataframe 
es.entity_from_dataframe(entity_id = 'bigmart', 
                         dataframe = combi, 
                         index = 'id')
我们数据中包含两个级别的信息，即 item级别和 outlet级别。Featuretools能把一个数据集拆分成多个表格。我们根据outlet ID Outlet_Identifier从BigMart表中创建一个新表“outlet”。

es.normalize_entity(base_entity_id='bigmart', 
                    new_entity_id='outlet', 
                    index = 'Outlet_Identifier', 
                    additional_variables =   
                    ['Outlet_Establishment_Year', 'Outlet_Size',  
                     'Outlet_Location_Type', 'Outlet_Type'])
下面打印出实体集EntitySet的组成。

print(es)



如上所示，它包含两个实体，为bigmart和outlet。这两个表之间也形成了一种关系，用Outlet_Identifier连接。这种关系将在生成新特征中发挥关键作用。

现在我们要使用DFS来自动创建新特征。上面提到，DFS使用特征基元和实体集中给出的多个表来创建特征。

feature_matrix, feature_names = ft.dfs(entityset=es, 
                                       target_entity = 'bigmart', 
                                       max_depth = 2, 
                                       verbose = 1, 
                                       n_jobs = 3)



target_entity只是创建新特征的实体ID，这种情况下为实体“bigmart”。参数max_depth控制着通过堆叠基元生成的要素复杂性。
参数n_jobs通过使用多个内核来辅助并行特征计算。

这就是使用Featuretools的过程，它已经产生了许多新特征。

来看下这些新创建的特征。

feature_matrix.columns



DFS在这么短的时间内创建了29个新特征，而手动操作需要更长时间。如果数据集包含多个相互关联的表，Featuretools仍然有效。在这种情况下，你不必对表进行标准化，因为多个表已经可用。

下面打印出feature_matrix的前几行。

feature_matrix.head()



这个数据帧存在一个问题，即未正确排序。我们必须根据combi数据帧中的id变量对其进行排序。

feature_matrix = feature_matrix.reindex(index=combi['id']) feature_matrix = feature_matrix.reset_index()
现在，数据帧feature_matrix已正确排序。

6.6 构建模型
现在该验证这些生成特征的效果了。我们将使用它们来构建模型并预测Item_Outlet_Sales值。由于最终数据feature_matrix具有多个分类特征，因此我决定使用CatBoost算法。它可以直接使用分类特征，并且本质上是可扩展的。有关CatBoost的更多内容可阅读这篇文章：
https://www.analyticsvidhya.com/blog/2017/08/catboost-automated-categorical-data/。

from catboost import CatBoostRegressor
CatBoost要求所有分类变量都使用字符串格式。因此，我们首先将数据中的分类变量转换为字符串：

categorical_features = np.where(feature_matrix.dtypes =='object')[0] 
for i in categorical_features: 
    feature_matrix.iloc[:,i]=feature_matrix.iloc[:,i].astype('str')
接着把feature_matrix分解为训练集和测试集。

feature_matrix.drop(['id'], axis=1, inplace=True) 
train = feature_matrix[:8523] 
test = feature_matrix[8523:]
# removing uneccesary variables 
train.drop(['Outlet_Identifier'], axis=1, inplace=True) test.drop(['Outlet_Identifier'], axis=1, inplace=True)
# identifying categorical features categorical_features = np.where(train.dtypes == 'object')[0]
然后把训练数据拆分为训练和验证集，并本地验证模型性能。

from sklearn.model_selection import train_test_split 
# splitting train data into training and validation set 
xtrain, xvalid, ytrain, yvalid = train_test_split(train, sales, 
                                                  test_size=0.25, 
                                                  random_state=11)
最后，训练模型时，我们使用的评估指标是RMSE（均方根误差）。

model_cat = CatBoostRegressor(iterations=100, learning_rate=0.3, 
                              depth=6, eval_metric='RMSE',  
                              random_seed=7) 
# training model 
model_cat.fit(xtrain, ytrain, cat_features=categorical_features, 
              use_best_model=True)
# validation score 
model_cat.score(xvalid, yvalid)
训练完成后，模型在验证集上的RMSE值大约为1092.24。

这个模型在公共排行榜上的得分为1155.12。在没有任何特征工程的情况下，在验证集和公共排行榜上的得分大约分别为1103和1183。因此，Featuretools创建的特征不只是随机特征，它们非常有价值和有效果。最重要的是，它在特征工程中节省的时间是令人难以置信的。

7 Featuretools可解释性
让数据科学模型具有可解释性是执行机器学习中一个很重要的方面。Featuretools生成的特征甚至能很容易地解释给非技术人员，因为它们是基于容易理解的基元构建的。

例如，特征outlet.SUM（bigmart.Item_Weight）和outlet.STD（bigmart.Item_MRP）分别表示items中权重的outlet级总和和items中成本的标准偏差。

这使得那些不是机器学习专家的使用者能够在他们的专业领域中理解和应用这个方法。

总结
Featuretools库真正地改变了机器学习的游戏规则。虽然它在工业领域的应用还十分有限，但是它在机器学习竞赛中很快地受到大家的欢迎。它能在构建机器学习模型中节省很多时间，且产生的特征很有效果，这也是我想把Featuretools介绍给大家的原因。

欢迎大家在处理数据集时尝试下这种方法！

原文：
https://medium.com/analytics-vidhya/a-hands-on-guide-to-automated-feature-engineering-in-python-13260eae9270

