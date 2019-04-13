

/* 思路：对整型数，取其一半位数反转，判断其是否与前半位数相等 
 * 每次更新反转的数和原数，当反转数大于原数时说明反转一半位数
 * 注意奇偶位数
 */

bool isPalindrome(int x) {
	if (x < 0 || x % 10 == 0 && x != 0)
		return false;

	int revertedNumber = 0;
	while (revertedNumber < x) {
		revertedNumber = revertedNumber * 10 + x % 10;
		x /= 10;
	}

	return x == revertedNumber || x == revertedNumber / 10;
}
