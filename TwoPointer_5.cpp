#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include<vector>
#include<tuple>
using namespace std;
int n, m;
int a[100001];
int main() {
	freopen("tp5.txt", "r", stdin);
	vector<pair<int, int>>v;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int candy = 0; int x = 0;
		cin >> candy >> x;
		v.push_back({ x, candy });
	}
	sort(v.begin(), v.end());
	int j = -1;
	int total_sum = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		while(j + 1 < n && (v[j + 1].first - v[i].first) <= 2 * m) {
			j++;
			total_sum += v[j].second;
		}
		ans = max(ans, total_sum);
		total_sum -= v[i].second;
	}
	cout << ans;
	return 0;
}