#coding:utf-8
import tensorflow as tf
import numpy as np
BATCH_SIZE=8
PROFIT=9
COST=1
SEED=23455

rdm=np.random.RandomState(SEED)
X=rdm.rand(32,2)
Y_=[[x1+x2+(rdm.rand()/10.0-0.05)] for (x1,x2) in X]
x=tf.placeholder(tf.float32,shape=(None,2))
y_=tf.placeholder(tf.float32,shape=(None,1))
w1=tf.Variable(tf.random_normal([2,1],stddev=1,seed=1))
y=tf.matmul(x,w1)

loss=tf.reduce_sum(tf.where(tf.greater(y,y_),COST*(y-y_),PROFIT*(y_-y)))
tf.train_step=tf.train.GradientDescentOptimizer(0.001).minimize(loss)
with tf.Session() as sess:
	init_op=tf.global_variables_initializer()
	sess.run(init_op)
	STEPS=20000
	for i in range(STEPS):
		start=(i*BATCH_SIZE)%32
		end=start+BATCH_SIZE
		sess.run(loss,feed_dict={x:X[start:end],y_:Y_[start:end]})
		if i % 500 == 0:
			print("After %d training steps, w1 is:"%i)
			print(sess.run(w1))
	print("The final w1 is %g:",sess.run(w1))
