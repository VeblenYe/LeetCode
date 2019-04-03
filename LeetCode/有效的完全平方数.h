#pragma once


// 完全平方数为前n个连续奇数和
bool isPerfectSquare(int num) {
	int sumnum = 1;
	while (num > 0) {
		num -= sumnum;
		sumnum += 2;
	}
	return num == 0;
}
