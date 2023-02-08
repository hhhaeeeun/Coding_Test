#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include<vector>
#include<tuple>
#include<climits>
#include<set>
using namespace std;
int n, d;
vector<pair<int, int>>v;
int main() {
	freopen("pt7.txt", "r", stdin);
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		int x = 0; int y = 0;
		cin >> x >> y;
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end());
	int j = 0;
	int total_sum = 0;
	int ans = INT_MAX;
	int max_y = v[0].second;
	int min_y = v[0].second;
	set<pair<int, int>> s;
	s.insert({ v[0].second, 0 });
	for (int i = 0; i < n - 1; i++) {
		while ((max_y - min_y) < d && j + 1 < n) {
			j++;
			max_y = max(max_y, v[j].second);
			min_y = min(min_y, v[j].second);
			s.insert({ v[j].second, j });
		}
		if ((max_y - min_y) < d)
			break;
		ans = min(ans, v[j].first - v[i].first);
		s.erase({ v[i].second, i });
		max_y = s.rbegin()->first;
		min_y = s.begin()->first;
	}
	if (ans == INT_MAX) {
		cout << "-1\n";
	}
	else {
		cout << ans;
	}
	return 0;
}