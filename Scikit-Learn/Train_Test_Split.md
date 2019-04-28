
python 划分数据集为训练集和测试集的方法
 更新时间：2018年12月11日 15:29:51   作者：心雨心辰     我要评论

今天小编就为大家分享一篇python 划分数据集为训练集和测试集的方法，具有很好的参考价值，希望对大家有所帮助。一起跟随小编过来看看吧
sklearn的cross_validation包中含有将数据集按照一定的比例，随机划分为训练集和测试集的函数train_test_split

        from sklearn.cross_validation import train_test_split
        #x为数据集的feature熟悉，y为label.
        x_train, x_test, y_train, y_test = train_test_split(x, y, test_size = 0.3)
        
        得到的x_train,y_train（x_test,y_test）的index对应的是x,y中被抽取到的序号。

        若train_test_split传入的是带有label的数据，则如下代码：

        from sklearn.cross_validation import train_test_split
        #dat为数据集,含有feature和label.
        train, test = train_test_split(dat, test_size = 0.3)
        train,test含有feature和label的。

自己写了一个函数：

        #X:含label的数据集：分割成训练集和测试集
        #test_size:测试集占整个数据集的比例
        def trainTestSplit(X,test_size=0.3):
          X_num=X.shape[0]
           train_index=range(X_num)
            test_index=[]
            test_num=int(X_num*test_size)
          for i in range(test_num):
          randomIndex=int(np.random.uniform(0,len(train_index)))
          test_index.append(train_index[randomIndex])
           del train_index[randomIndex]
          #train,test的index是抽取的数据集X的序号
          train=X.ix[train_index] 
          test=X.ix[test_index]
          return train,test

