#include"include.h"
class Solution {
public:
	bool isValid(string s) {
		stack<char> stack;
		map<char, char> l2r = { {'(',')'},{ '[',']'}, {'{','}'} };
		for (auto c : s) {
			if (l2r.find(c) != l2r.cend())
				stack.push(c);
			else {
				if (stack.empty() || l2r[stack.top()] != c) return false;
				else stack.pop();
			}
		}
		if (stack.empty())	return true;
		else return false;

	}
};