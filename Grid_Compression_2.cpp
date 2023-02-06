#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
#include<unordered_map>
#include<climits>
#include<tuple>
#include<algorithm>
#define MAX_N 1000
#define MAX_Q 100000
#define MAX_M 2000
using namespace std;
int n, q;
vector<pair<int, int>> points;
set<int> s;
unordered_map<int, int> mapper;
int prefix_sum[MAX_M + 2][MAX_M + 2];
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	freopen("gc2.txt", "r", stdin);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		int y = 0;  int x = 0; cin >> y >> x;
		s.insert(y);
		s.insert(x);
		points.push_back({ y,x });
	}
	s.insert(INT_MAX);
	s.insert(INT_MIN);
	int cnt = 0;
	for (auto i : s) {
		mapper[i] = cnt;
		cnt++;
	}

	for (auto i : points) {
		++prefix_sum[mapper[i.first]][mapper[i.second]];
	}



	for (int i = 1; i < cnt; i++) {
		for (int j = 1; j < cnt; j++) {
			prefix_sum[i][j] += prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
		}
	}
	int ret = 0;
	for (int i = 0; i < q; i++) {
		int y1 = 0; int y2 = 0; int x1 = 0; int x2 = 0; 
		cin >> y1 >> x1 >> y2 >> x2;
		//보정작업
		auto k = s.lower_bound(y1);
		y1 = *k;
		k = s.lower_bound(x1);
		x1 = *k;
		k = s.upper_bound(y2);
		--k;
		y2 = *k;
		k = s.upper_bound(x2);
		--k;
		x2 = *k;
		ret = prefix_sum[mapper[y2]][mapper[x2]] - prefix_sum[mapper[y2]][mapper[x1] - 1]
			- prefix_sum[mapper[y1] - 1][mapper[x2]] + prefix_sum[mapper[y1] - 1][mapper[x1] - 1];
		cout << ret << '\n';
	}
	return 0;
}