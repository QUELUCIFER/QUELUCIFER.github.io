
6. 第 6 个问题
Which ones of the following statements on Residual Networks are true? (Check all that apply.)

- [ ] The skip-connections compute a complex non-linear function of the input to pass to a deeper layer in the network.


- [x] Using a skip-connection helps the gradient to backpropagate and thus helps you to train deeper networks

- [x] The skip-connection makes it easy for the network to learn an identity mapping between the input and the output within the ResNet block.

- [ ] A ResNet with L layers would have on the order of L^2L2 skip connections in total.

9. 第 9 个问题
Which ones of the following statements on Inception Networks are true? (Check all that apply.)

- [ ] Inception networks incorporates a variety of network architectures (similar to dropout, which randomly chooses a network architecture on each step) and 
thus has a similar regularizing effect as dropout.


- [x] A single inception block allows the network to use a combination of 1x1, 3x3, 5x5 convolutions and pooling.

- [x] Inception blocks usually use 1x1 convolutions to reduce the input data volume’s size before applying 3x3 and 5x5 convolutions.

- [ ] Making an inception network deeper (by stacking more inception blocks together) should not hurt training set performance.

10. 第 10 个问题

Which of the following are common reasons for using open-source implementations of ConvNets (both the model and/or weights)? Check all that apply.

- [x] Parameters trained for one computer vision task are often useful as pretraining for other computer vision tasks.

- [ ] A model trained for one computer vision task can usually be used to perform data augmentation even for a different computer vision task.

- [x] It is a convenient way to get working an implementation of a complex ConvNet architecture.

- [ ] The same techniques for winning computer vision competitions, such as using multiple crops at test time, are widely used in practical 
deployments (or production system deployments) of ConvNets.
