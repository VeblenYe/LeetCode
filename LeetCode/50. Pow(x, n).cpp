

// 乘方运算，主要考虑n为0或1或为负数的情况


double MyPow(double x, int n) {
	if (n == 0)
		return 1.0;
	if (n == 1)
		return x;

	auto t = n / 2;
	if (n < 0) {
		x = 1 / x;
		t = -t;
	}

	auto res = MyPow(x, t);
	if (n & 0x1)
		return res * res * x;
	else
		return res * res;
}
