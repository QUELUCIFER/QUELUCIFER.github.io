#coding:utf-8
import numpy as np
import tensorflow as tf
BATCH_SIZE=8
SEED=23455

rng=np.random.RandomState(SEED)
X=rng.rand(32,2)
Y=[[x1+x2+rng.rand()/10.0-0.05] for (x1,x2) in X]
x=tf.placeholder(tf.float32,shape=(None,2))
y_=tf.placeholder(tf.float32,shape=(None,1))
w1=tf.Variable(tf.random_normal([2,1],stddev=1,seed=1))
y=tf.matmul(x,w1)

loss_mse=tf.reduce_mean(tf.square(y_-y))
train_step=tf.train.GradientDescentOptimizer(0.001).minimize(loss_mse)

with tf.Session() as sess:
	init_op=tf.global_variables_initializer()
	sess.run(init_op)
	print("w1:\n",sess.run(w1))
	STEP=20000
	for i in range(STEP):
		start=(i*BATCH_SIZE)%32
		end=(i*BATCH_SIZE)%32+BATCH_SIZE
		sess.run(train_step,feed_dict={x:X[start:end],y_:Y[start:end]})
		if i%500==0:
			#total_loss=sess.run(loss_mse,feed_dict={x:X,y_:Y})
			print("After %d train steps, w1 is:"%i)
			print("w1:\n",sess.run(w1))
	print("The final w1 is:\n",sess.run(w1))
