#pragma once


double MyPow(double x, int n) {
	if (n == 0)
		return 1;
	if (n == 1)
		return x;

	int t = n / 2;
	// ��Ҫ������Ϊ���������
	if (n < 0) {
		x = 1 / x;
		t = -t;
	}

	double res = MyPow(x, t);
	if (n % 2 == 0)
		return res * res;
	else
		return res * res * x;
}
