

// ��ȫƽ����Ϊǰn������������
bool isPerfectSquare(int num) {
	int sumnum = 1;
	while (num > 0) {
		num -= sumnum;
		sumnum += 2;
	}
	return num == 0;
}
