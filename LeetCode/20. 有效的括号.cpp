

#include "leetcode.h"


bool isValid(string s) {
	if (s.empty())
		return true;

	stack<char> cstack;
	int i = 0;
	cstack.push(s[i]);
	while (!cstack.empty() && i < s.size()) {
		++i;
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			cstack.push(s[i]);
		}
		else {
			auto t = s[i];
			if (t == ')' && cstack.top() == ')' || t == '}' && cstack.top() == '{'
				|| t == ']' && cstack.top() == '[') {
				cstack.pop();
				if (cstack.empty() && ++i < s.size())
					cstack.push(s[i]);
			}
			else
				return false;
		}
	}
	return cstack.empty();
}
