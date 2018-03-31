# 问题
一个点只能向左边和向下运动，并且在中间有障碍物，从左上角到右下角的路径条数

# 解决方法
经典的DP算法
$$
Dp(x,y)=(Dp(x,y-1)*battle(x,y-1)+(Dp(x-1,y))*battle(x-1,y))*battle(x,y) \\
battle(x,y):it \quad is \quad a \quad battle \quad 0:is \quad 1:not
$$
