
/* ��¥�� */


/* ˼·�������Ǽ���쳲��������� */
int climbStairs(int n) {
	int i = 1;
	int j = 2;
	while (--n) {
		j += i;
		i = j - i;
	}
	return i;
}
