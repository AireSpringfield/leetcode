#include "include.h"
class Solution {
public:
	bool isPalindrome(string s) {
		if (s.empty()) return true;
		transform(s.cbegin(), s.cend(), s.begin(), ::tolower);
		auto left = s.cbegin(), right = --s.cend();
		while (left < right) {
			if(!isalnum(*left) && left != --s.cend())
				++left;
			else if(!isalnum(*right) && right != s.cbegin())
				--right;
			else if(*left != *right)
				return false;
			else
				++left, --right;
		}
		return true;
	}
};
