#coding:utf-8
import tensorflow as tf
w1=tf.Variable(0,dtype=tf.float32)
global_step=tf.Variable(0,trainable=False)
MOVING_AVERAGE_DECAY=0.99
ema=tf.train.ExponentialMovingAverage(MOVING_AVERAGE_DECAY,global_step)

ema_op=ema.apply([w1])
#ema_op=ema.apply(tf.trainable_variables())
#自动将所有待训练参数汇总为列表

with tf.Session() as sess:
	init_op=tf.global_variables_initializer()
	sess.run(init_op)
	print(sess.run([w1,ema.average(w1)]))
	#给w1赋值为1
	sess.run(tf.assign(w1, 1))
	sess.run(ema_op)
	print(sess.run([w1,ema.average(w1)]))
	
	#模拟出100轮迭代后，w1变为10
	#for i in range(1, ITERATIONS):

    # ...

    # Discard the second element of the result.
	#	numpy_state, _ = sess.run([final_state, train_step], feed_dict={initial_state: numpy_state,input_sequence: batch[0],output_actual: batch[1]})
	global_step=tf.assign(global_step,100)
	sess.run(tf.assign(w1,10))
	sess.run(ema_op)
	print(sess.run([w1,ema.average(w1)]))
	#每次sess.run()后更新w1的滑动平均值
	sess.run(ema_op)
	w1_1_val=sess.run([w1,ema.average(w1)])
	print(w1_1_val)
	sess.run(ema_op)
	print(sess.run([w1,ema.average(w1)]))
	sess.run(ema_op)
	print(sess.run([w1,ema.average(w1)]))
	sess.run(ema_op)
	print(sess.run([w1,ema.average(w1)]))
	sess.run(ema_op)
	print(sess.run([w1,ema.average(w1)]))
	sess.run(ema_op)
	w1_5_val=sess.run([w1,ema.average(w1)])
	print(w1_5_val)
