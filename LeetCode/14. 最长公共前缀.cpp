

#include <vector>
#include <string>


std::string longestCommonPrefix(std::vector<std::string> &strs) {
	if (strs.empty())
		return "";
	for (int i = 0, j; i < strs[0].size(); ++i) {
		for (j = 1; j < strs.size(); ++j) {
			if (i == strs[j].size())
				return strs[0].substr(0, i);
			if (strs[0][i] != strs[j][i])
				return strs[0].substr(0, i);
		}
	}
	return strs[0];
}
