
如何在TensorFlow上高效地使用Dataset
专知发表于专知
2.6K

【导读】近日，机器学习工程师Francesco Zuppichini发表一篇教程，讲解了在TensorFlow中高效地输入数据集的方法，作者首先抛弃了feed-dict（它太慢了），然后介绍TensorFlow的内置API——Dataset，接下来就如何使用该API向模型中导入数据进行介绍。分为以下几部分讲解：导入数据、创建迭代器、使用数据、以及读入数据时的一些实用技巧。如果您还在使用feed-dict并受其速度低下的困扰，那么读一下这篇文章，相信定能有所启发。

How to use Dataset in TensorFlow

作者网址：

https://francescozuppichini.carrd.co/

经常使用TensorFlow的朋友可能知道，feed-dict是将信息输入给TensorFlow的最慢的方式，因此，要提高速度必须避免这种方式。将数据馈送到您的模型中的正确方法是使用输入管道来确保GPU不用等待。幸运的是，TensorFlow有一个内置的API——Dataset，它更容易完成这项任务，因此，使用内置的输入管道（Pipeline），不要使用‘feed-dict’。在本教程中，我们将学习如何使用它创建输入管道，以及如何有效地将数据输入到模型中。

本文将解释Dataset的基本机制，涵盖最常见的用例。您可以在jupyter notebook找到所有代码：

https://github.com/FrancescoSaverioZuppichini/Tensor?ow-Dataset-

Tutorial/blob/master/dataset_tutorial.ipynb

注意：更新为TensorFlow 1.5

▌概述：

为了使用Dataset，我们需要三个步骤：

1）导入数据：从一些数据中创建一个Dataset实例；

2）创建一个迭代器：通过使用创建的数据集来制作一个迭代器实例迭代遍历数据集；

3）使用数据：通过使用创建的迭代器，我们可以得到数据集的元素馈送给模型；

▌导入数据

我们首先需要一些数据放入我们的Dataset

1 从numpy导入数据

常见的情况下，我们有一个numpy数组，我们想通过它传送到tensorflow。

# create a random vector of shape (100,2)
x = np.random.sample((100,2))
# make a dataset from a numpy array
dataset = tf.data.Dataset.from_tensor_slices(x) 

我们也可以通过多个numpy数组，一个典型的例子是当我们将数据分为特征和标签时

features, labels = (np.random.sample((100,2)), np.random.sample((100,1)))
dataset = tf.data.Dataset.from_tensor_slices((features,labels)) 

2 从tensor导入数据

当然，我们可以用一些张量来初始化我们的数据集

# using a tensor
dataset = tf.data.Dataset.from_tensor_slices(tf.random_uniform([100, 2]))

3 从placeholder（占位符）导入数据

当我们想动态地改变数据集里面的数据时，placeholder是很有用的，我们稍后会做。

x = tf.placeholder(tf.float32, shape=[None,2])
dataset = tf.data.Dataset.from_tensor_slices(x)

4 从生成器导入数据

我们也可以从一个生成器初始化一个数据集，当我们有一个长度不同的元素数组（例如一个序列）时，这种方法非常有用的：

sequence = np.array([[1],[2,3],[3,4]])
def generator():
    for el in sequence:
        yield el
dataset = tf.data.Dataset().from_generator(generator,
                                           output_types=tf.float32, 
                                           output_shapes=[tf.float32])

在这种情况下，您还需要指定数据的类型和大小，用来创建正确的张量。

▌创建迭代器（Iterator）

我们已经知道如何创建一个数据集，但是如何获取我们的数据呢？ 那就必须使用迭代器，它使我们能够遍历数据集并找到数据的实际值。 有四种类型的迭代器。

1 One Shot迭代器

这是最简单的迭代器，请看下面的例子

x = np.random.sample((100,2))
# make a dataset from a numpy array
dataset = tf.data.Dataset.from_tensor_slices(x)
# create the iterator
iter = dataset.make_one_shot_iterator()

然后，您需要调用get_next（）来获取包含你的数据的张量

...
# create the iterator
iter = dataset.make_one_shot_iterator()
el = iter.get_next()

我们可以运行el看到它的值

with tf.Session() as sess:
    print(sess.run(el)) # output: [ 0.42116176  0.40666069] 

2 可初始化迭代器

如果我们要构建一个动态数据集，我们可以实时更改数据源，可以使用占位符创建数据集。然后我们可以使用feed-dict机制来初始化占位符。这是用一个可初始化的迭代器完成的。使用上一节的示例三

# using a placeholder
x = tf.placeholder(tf.float32, shape=[None,2])
dataset = tf.data.Dataset.from_tensor_slices(x)
data = np.random.sample((100,2))
iter = dataset.make_initializable_iterator() # create the iterator
el = iter.get_next()
with tf.Session() as sess:
    # feed the placeholder with data
    sess.run(iter.initializer, feed_dict={ x: data }) 
    print(sess.run(el)) # output [ 0.52374458  0.71968478]

我们调用make_initializable_iterator。 然后，在sess范围内，我们运行初始化操作来传递我们的数据，在这种情况下数据是一个随机的numpy数组。 

想象一下，在实际场景中，我们有一个训练集和一个测试集：

train_data = (np.random.sample((100,2)), np.random.sample((100,1)))
test_data = (np.array([[1,2]]), np.array([[0]]))

我们想训练模型，然后在测试数据集上评估它，这可以通过在训练之后再次初始化迭代器来完成

# initializable iterator to switch between dataset
EPOCHS = 10
x, y = tf.placeholder(tf.float32, shape=[None,2]), tf.placeholder(tf.float32,
 shape=[None,1])
dataset = tf.data.Dataset.from_tensor_slices((x, y))
train_data = (np.random.sample((100,2)), np.random.sample((100,1)))
test_data = (np.array([[1,2]]), np.array([[0]]))
iter = dataset.make_initializable_iterator()
features, labels = iter.get_next()
with tf.Session() as sess:
#     initialise iterator with train data
    sess.run(iter.initializer, feed_dict={ x: train_data[0], 
y: train_data[1]})
    for _ in range(EPOCHS):
        sess.run([features, labels])
#     switch to test data
    sess.run(iter.initializer, feed_dict={ x: test_data[0], y: test_data[1]})
    print(sess.run([features, labels]))

3 重新初始化的迭代器

这个概念与上一个类似，我们要在数据之间进行动态切换。 但是，不是将新数据馈送到相同的数据集，而是切换数据集。和以前一样，我们要有一个训练数据集和一个测试数据集

# making fake data using numpy
train_data = (np.random.sample((100,2)), np.random.sample((100,1)))
test_data = (np.random.sample((10,2)), np.random.sample((10,1)))

我们可以创建两个数据集

# create two datasets, one for training and one for test
train_dataset = tf.data.Dataset.from_tensor_slices(train_data)
test_dataset = tf.data.Dataset.from_tensor_slices(test_data) 

现在要使用一个技巧，即创建一个通用的迭代器

# create a iterator of the correct shape and type
iter = tf.data.Iterator.from_structure(train_dataset.output_types,
                                           train_dataset.output_shapes) 

然后进行两次初始化操作：

# create the initialisation operations
train_init_op = iter.make_initializer(train_dataset)
test_init_op = iter.make_initializer(test_dataset)

我们像以前一样得到下一个元素

features, labels = iter.get_next()

现在，我们可以使用我们的会话直接运行两个初始化操作。综合起来，我们得到：

# Reinitializable iterator to switch between Datasets
EPOCHS = 10
# making fake data using numpy
train_data = (np.random.sample((100,2)), np.random.sample((100,1)))
test_data = (np.random.sample((10,2)), np.random.sample((10,1)))
# create two datasets, one for training and one for test
train_dataset = tf.data.Dataset.from_tensor_slices(train_data)
test_dataset = tf.data.Dataset.from_tensor_slices(test_data)
# create a iterator of the correct shape and type
iter = tf.data.Iterator.from_structure(train_dataset.output_types,
                                           train_dataset.output_shapes)
features, labels = iter.get_next()
# create the initialisation operations
train_init_op = iter.make_initializer(train_dataset)
test_init_op = iter.make_initializer(test_dataset)
with tf.Session() as sess:
    sess.run(train_init_op) # switch to train dataset
    for _ in range(EPOCHS):
        sess.run([features, labels])
    sess.run(test_init_op) # switch to val dataset
    print(sess.run([features, labels]))

4 可馈送的迭代器（Feedable Iterator）

老实说，我不认为这个方法是有用的。它不是在数据集之间切换，而是在迭代器之间切换，例如，您可以从make_one_shot_iterator（）获得一个迭代器，而从make_initializable_iterator（）获得另一个迭代器。

▌使用数据

在前面的例子中，我们使用会话来打印数据集中下一个元素的值

...
next_el = iter.get_next()
...
print(sess.run(next_el)) # will output the curr 

为了将数据传递给模型，我们必须通过张量从get_next（）生成。在下面的代码片段中，我们有一个包含两个numpy数组的数据集，使用第一节中的示例。注意我们需要将.random.sample封装到另一个numpy数组中，以添加一个维度，我们需要批量处理数据

# using two numpy arrays
features, labels = (np.array([np.random.sample((100,2))]), 
                    np.array([np.random.sample((100,1))]))
dataset = tf.data.Dataset.from_tensor_slices((features,labels)).
repeat().batch(BATCH_SIZE)

然后像往常一样，我们创建一个迭代器

iter = dataset.make_one_shot_iterator()
x, y = iter.get_next() 

我们做一个模型，一个简单的神经网络

# make a simple model
net = tf.layers.dense(x, 8) # pass the first value from iter.get_next() 
as input
net = tf.layers.dense(net, 8)
prediction = tf.layers.dense(net, 1)
loss = tf.losses.mean_squared_error(prediction, y) # pass the second value 
from iter.get_net() as label
train_op = tf.train.AdamOptimizer().minimize(loss) 

我们直接使用iter.get_next（）中的张量作为第一层的输入，并作为损失函数的标签。 一起封装：

EPOCHS = 10
BATCH_SIZE = 16
# using two numpy arrays
features, labels = (np.array([np.random.sample((100,2))]), 
                    np.array([np.random.sample((100,1))]))
dataset = tf.data.Dataset.from_tensor_slices((features,labels)).repeat().
batch(BATCH_SIZE)
iter = dataset.make_one_shot_iterator()
x, y = iter.get_next()
# make a simple model
net = tf.layers.dense(x, 8, activation=tf.tanh) # pass the first value 
from iter.get_next() as input
net = tf.layers.dense(net, 8, activation=tf.tanh)
prediction = tf.layers.dense(net, 1, activation=tf.tanh)
loss = tf.losses.mean_squared_error(prediction, y) # pass the second value 
from iter.get_net() as label
train_op = tf.train.AdamOptimizer().minimize(loss)
with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())
    for i in range(EPOCHS):
        _, loss_value = sess.run([train_op, loss])
        print("Iter: {}, Loss: {:.4f}".format(i, loss_value)) 

输出：

Iter: 0, Loss: 0.1328 
Iter: 1, Loss: 0.1312 
Iter: 2, Loss: 0.1296 
Iter: 3, Loss: 0.1281 
Iter: 4, Loss: 0.1267 
Iter: 5, Loss: 0.1254 
Iter: 6, Loss: 0.1242 
Iter: 7, Loss: 0.1231 
Iter: 8, Loss: 0.1220 
Iter: 9, Loss: 0.1210

▌实用技巧

    批量（Batch）

通常，批处理数据是一件痛苦的事情，使用Dataset API我们可以使用批处理方法（BATCH_SIZE），该方法会自动将数据集批量化为所提供的大小。 默认值是1。 在下面的例子中，我们使用批量大小为4

# BATCHING
BATCH_SIZE = 4
x = np.random.sample((100,2))
# make a dataset from a numpy array
dataset = tf.data.Dataset.from_tensor_slices(x).batch(BATCH_SIZE)
iter = dataset.make_one_shot_iterator()
el = iter.get_next()
with tf.Session() as sess:
    print(sess.run(el))  

输出：

[[ 0.65686128  0.99373963]
 [ 0.69690451  0.32446826]
 [ 0.57148422  0.68688242]
 [ 0.20335116  0.82473219]]

    重复（Repeat）

使用.repeat（）我们可以指定我们希望迭代数据集的次数。如果没有参数传递，它将永远循环，通常来说，永久运行循环和在标准循环中直接控制 epoch 的数量可以得到不错的结果。

    洗牌（Shuffle）

我们可以通过使用方法shuffle（）来对数据集进行洗牌，该方法在每个时期默认洗牌数据集。 记住：洗牌数据集是非常重要的，可以有效避免过度拟合。我们也可以设置参数buffer_size，一个固定大小的缓冲区，下一个元素将从该固定大小的缓存中均匀地选取。例如：

# BATCHING
BATCH_SIZE = 4
x = np.array([[1],[2],[3],[4]])
# make a dataset from a numpy array
dataset = tf.data.Dataset.from_tensor_slices(x)
dataset = dataset.shuffle(buffer_size=100)
dataset = dataset.batch(BATCH_SIZE)
iter = dataset.make_one_shot_iterator()
el = iter.get_next()
with tf.Session() as sess:
    print(sess.run(el)) 

第一次运行的输出：

[[4]
 [2]
 [3]
 [1]] 

第二次运行的输出：

[[3]
 [1]
 [2]
 [4]] 

这就是shuffle过程，另外，你也可以设置种子（seed）参数。

    映射（Map）

您可以使用映射方法将自定义函数应用于数据集的每个成员。在下面的例子中，我们将每个元素乘以二：

# MAP
x = np.array([[1],[2],[3],[4]])
# make a dataset from a numpy array
dataset = tf.data.Dataset.from_tensor_slices(x)
dataset = dataset.map(lambda x: x*2)
iter = dataset.make_one_shot_iterator()
el = iter.get_next()
with tf.Session() as sess:
#     this will run forever
        for _ in range(len(x)):
            print(sess.run(el)

输出：

[2]
[4]
[6]
[8]

▌总结：

Dataset API为我们提供了一种快速而强大的方法来创建优化的输入管道，以训练，评估和测试我们的模型。在这篇文章中，我们已经看到了我们可以使用其中的大部分常见操作。 您可以使用我为本文撰写的jupyter笔记本作为参考。

感谢您的阅读

    相关链接

TensorFlow dataset教程：

https://www.tensorcow.org/programmers_guide/datasets

    Dataset docs：

https://www.tensorcow.org/api_docs/python/tf/data/Dataset

    其他相关资源

TensorFlow读取数据的三种方法：

1. Feeding，在TensorFlow程序运行的每一步， 让Python代码来供给数据。

2. 从文件读取数据： 在TensorFlow图的起始， 让一个输入管线从文件中读取数据。

3. 预加载数据： 在TensorFlow图中定义常量或变量来保存所有数据(仅适用于数据量比较小的情况)。

其实已经介绍了第一点，下面简单看一下2/3点。

从文件读取数据：

1. 从不同格式读取文件

CSV文件：从CSV文件中读取数据， 需要使用TextLineReader和decode_csv 操作， 如下：

filename_queue = tf.train.string_input_producer(["file0.csv", "file1.csv"])

reader = tf.TextLineReader()
key, value = reader.read(filename_queue)

# Default values, in case of empty columns. Also specifies the type of the
# decoded result.
record_defaults = [[1], [1], [1], [1], [1]]
col1, col2, col3, col4, col5 = tf.decode_csv(
    value, record_defaults=record_defaults)
features = tf.concat(0, [col1, col2, col3, col4])

with tf.Session() as sess:
  # Start populating the filename queue.
  coord = tf.train.Coordinator()
  threads = tf.train.start_queue_runners(coord=coord)

  for i in range(1200):
    # Retrieve a single instance:
    example, label = sess.run([features, col5])

  coord.request_stop()
  coord.join(threads)

固定长度的记录：从二进制文件中读取固定长度纪录， 可以使用tf.FixedLengthRecordReader的tf.decode_raw操作。decode_raw操作可以讲一个字符串转换为一个uint8的张量。

如，CIFAR-10 dataset的文件格式定义是：每条记录的长度都是固定的，一个字节的标签，后面是3072字节的图像数据。uint8的张量的标准操作就可以从中获取图像片并且根据需要进行重组。

标准TensorFlow格式：另一种保存记录的方法可以允许你讲任意的数据转换为TensorFlow所支持的格式， 这种方法可以使TensorFlow的数据集更容易与网络应用架构相匹配。这种建议的方法就是使用TFRecords文件，TFRecords文件包含了tf.train.Example 协议内存块(protocol buffer)(协议内存块包含了字段 Features)。你可以写一段代码获取你的数据， 将数据填入到Example协议内存块(protocol buffer)，将协议内存块序列化为一个字符串， 并且通过tf.python_io.TFRecordWriter class写入到TFRecords文件。

例子如下：

https://tensorflow.googlesource.com/tensorflow/+/master/tensorflow/g3doc/how_tos/reading_data/convert_to_records.py

2. 预加载数据

这种方法仅用于可以完全加载到存储器的小数据集。可以存储在常量和变量中。

存储在常量中更简单，但是需要更多内存，如下：

training_data = ...
training_labels = ...
with tf.Session():
    input_data = tf.constant(training_data)
    input_labels = tf.constant(training_labels)
    ...

存储在变量中需要进行初始化，如下：

training_data = ...
training_labels = ...
with tf.Session() as sess:
  data_initializer = tf.placeholder(dtype=training_data.dtype,
                                    shape=training_data.shape)
  label_initializer = tf.placeholder(dtype=training_labels.dtype,
                                     shape=training_labels.shape)
  input_data = tf.Variable(data_initalizer, trainable=False, collections=[])
  input_labels = tf.Variable(label_initalizer, trainable=False, 
collections=[])
  ...
  sess.run(input_data.initializer,
           feed_dict={data_initializer: training_data})
  sess.run(input_labels.initializer,
           feed_dict={label_initializer: training_lables})

参考链接：

https://towardsdatascience.com/how-to-use-dataset-in-tensorflow-c758ef9e4428

https://zhuanlan.zhihu.com/p/29756826

