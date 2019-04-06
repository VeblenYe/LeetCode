

/* ·­×ª×Ö·û´® */


#include <string>
#include <algorithm>


using std::string;
using std::reverse;


string reverseString1(string s) {
	reverse(s.begin(), s.end());
	return s;
}


string reverseString2(string s) {
	if (s.empty() || s.size() == 1)
		return s;

	int i = 0;
	int j = s.size() - 1;
	while (i < j) {
		auto t = s[i];
		s[i++] = s[j];
		s[j--] = t;
	}

	return s;
}

