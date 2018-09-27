#include"include.h"

class Solution {
public:
	int minCut(string s) {
		const int n = s.size();
		// 2D array represented with 1D vector, where (i, j) is indexed by (i*n+j).
		// (i, j) is true if s[i] to s[j] is a palindrome.
		vector<bool> isPalindrome(n*n, false);

		for (int i = 0; i < n; ++i) {
			isPalindrome[i*n + i] = true;
		}

		// f(i) is the minCut of substring s[i] to s[n-1].
		// DP recursion formula: f(i) = min{ f(j)+1 }, where j in {i+1, ..., n-1} such that s[i] to s[j-1] is a palindrome.
		vector<int> f(n+1);
		f[n - 1] = 0;
		// f[n] is for special usage, when s[i] to s[n-1] is a palindrome, to cancel out the added 1.
		f[n] = -1;

		for (int i = n - 2; i >= 0; --i) {
			int fmin = f[i + 1];
			for (int j = i + 1; j < n+1; ++j) { // Note here that j = n is for the case where s[i] to s[n-1] may be a palindrome. 
				// Update isPalindrome (i, j-1) ...
				bool tmp = isPalindrome[i*n + j - 1] = (s[i] == s[j - 1]);
				if (i + 1<j - 2)
					tmp = isPalindrome[i*n + j - 1] = tmp && isPalindrome[(i + 1)*n + j - 2];
				// ... and use it in if-condition.
				if (tmp)
					fmin = min(fmin, f[j]);
			}
			f[i] = fmin + 1;
		}

		return f[0];

	}
};