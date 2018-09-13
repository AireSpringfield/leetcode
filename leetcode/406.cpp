#include"include.h"

class Solution {
public:
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people) {
		sort(people.begin(), people.end(),
			[](const pair<int, int> &l, const pair<int, int> &r) { return l.first != r.first ? l.first < r.first : l.second < r.second; });

		vector<pair<int, int>> inOrder;
		for (int i = 0; i < people.size(); ++i) {
			inOrder.insert(inOrder.begin() + people[i].second, people[i]);
		}

		return inOrder;
	}
};