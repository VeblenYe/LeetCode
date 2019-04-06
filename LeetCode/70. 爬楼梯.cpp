
/* 爬楼梯 */


/* 思路：本质是计算斐波那契数列 */
int climbStairs(int n) {
	int i = 1;
	int j = 2;
	while (--n) {
		j += i;
		i = j - i;
	}
	return i;
}
