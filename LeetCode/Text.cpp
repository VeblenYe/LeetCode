

#include <vector>
#include <string>
#include <iostream>


#include "最长公共前缀.h"


using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ends;


int main() {
	string s1("bc"), s2("ab"), s3("a");
	vector<string> svec{ s1, s2, s3 };
	cout << longestCommonPrefix(svec) << endl;
	getchar();
	return 0;
}
