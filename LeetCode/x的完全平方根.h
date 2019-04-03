#pragma once


// 牛顿迭代法
/*
计算x2 = n的解，令f(x) = x2 - n，相当于求解f(x) = 0的解，如左图所示。
首先取x0，如果x0不是解，做一个经过(x0, f(x0))这个点的切线，与x轴的交点为x1。
同样的道理，如果x1不是解，做一个经过(x1, f(x1))这个点的切线，与x轴的交点为x2。
以此类推。
以这样的方式得到的xi会无限趋近于f(x) = 0的解。
判断xi是否是f(x) = 0的解有两种方法：
一是直接计算f(xi)的值判断是否为0，二是判断前后两个解xi和xi - 1是否无限接近。
经过(xi, f(xi))这个点的切线方程为f(x) = f(xi) + f’(xi)(x - xi)，其中f'(x)为f(x)的导数，本题中为2x。令切线方程等于0，即可求出xi+1=xi - f(xi) / f'(xi)。
继续化简，xi + 1 = xi - (xi2 - n) / (2xi) = xi - xi / 2 + n / (2xi) = xi / 2 + n / 2xi = (xi + n / xi) / 2。
*/
int mySqrt(int x) {
	if (x == 0 || x == 1)
		return x;

	int r = x >> 1;
	while (r > x / r)
		r = (r + x / r) >> 1;
	return r;
}
