#include "include.h"
class Solution
{
  public:
	int longestValidParentheses(string s)
	{
		stack<int> left;
		int leftest = 0, maxLen = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == '(')
			{
				left.push(i);
			}
			else
			{
				if (!left.empty()) // Valid
				{
					left.pop();
					if(!left.empty())
						maxLen = max(maxLen, i - left.top());
					else
						maxLen = max(maxLen, i - leftest + 1);	
				}
				else // Invalid
				{
					leftest = i + 1;
				}
			}
		}
		return maxLen;
	}
};