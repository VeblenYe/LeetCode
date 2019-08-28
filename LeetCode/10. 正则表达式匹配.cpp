
#include "LeetCode.h"

// ���б���¼�Ż��İ汾��Ҳ�����Զ����¶�̬�滮��������Ҫ����ռ�
bool dp(const string &s, const string &p, int i, int j, map<pair<int, int>, bool> &memo) {
	if (memo.find({ i, j }) != memo.end())
		return memo[{i, j}];

	if (j == p.size())
		return i == s.size();

	bool first = false;
	bool ans = false;

	if (i < s.size() && (p[j] == s[i] || p[j] == '.'))
		first = true;

	if (j <= p.size() - 2 && p[j + 1] == '*')
		ans = dp(s, p, i, j + 2, memo) || (first && dp(s, p, i + 1, j, memo));
	else
		ans = first && dp(s, p, i + 1, j + 1, memo);

	memo[{i, j}] = ans;

	return ans;
}


// ��������¼�ĵݹ�汾��ʱ�临�Ӷ��Ըߣ����ռ临�ӶȽϵ�
bool dp(const string &s, const string &p, int i, int j) {
	if (j == p.size())	// ��ģʽ���������ʱ���ж����봮�Ƿ�Ҳ�������
		return i == s.size();

	auto firstMatch = i < s.size() && (p[j] == s[i] || p[j] == '.');	// ����ƥ��Ľ��

	if (j <= p.size() - 2 && p[j + 1] == '*')	// �����һ��ģʽΪ'*'����ǰ����ƥ��0�λ�1��
		// ����ǰƥ��0�Σ���ֱ������'*'�����ҵ�ǰ�ַ���ƥ����Ҫ����һ���ж���
		// ����ǰƥ��1�Σ��򲻸���ģʽ��ֱ�ӽ�����һ�ַ�
		return dp(s, p, i, j + 2) || (firstMatch && dp(s, p, i + 1, j));
	else
		// ������֮
		return firstMatch && dp(s, p, i + 1, j + 1);
}


bool isMatch(string s, string p) {
	map<pair<int, int>, bool> memo;
	return dp(s, p, 0, 0, memo);
}
