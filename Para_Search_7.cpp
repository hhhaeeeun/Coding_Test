#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("ps7.txt", "r", stdin);
	cin >> n >> m;
	vector<pair<long long, long long>> v;
	for (int i = 0; i < m; i++) {
		int x = 0; int y = 0;
		cin >> x >> y;
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end());

	long long lo = 1;
	long long hi = v[m-1].second;
	long long ret = 0;
	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		long long k = 1;
		long long before_idx = v[0].first;
		for (int i = 0; i < m; i++) {
			if (before_idx + mid <= v[i].first) {
				before_idx = v[i].first;
				k++;
			}
			while (before_idx + mid <= v[i].second) {
				before_idx += mid;
				k++;
			}
		}

		if (k >= n) {
			lo = mid + 1;
			ret = max(ret, mid);
		}
		if (k < n) {
			hi = mid - 1;
		}
	}
	
	cout << ret;
	return 0;
}