#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
int n;
vector<pair<long long, long long>>v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long x = 0; long long y = 0;
		cin >> x >> y;
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end());
	long long ret = 0;
	long long lo = 1;
	long long hi = v[n - 1].second;
	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		long long before_index = v[0].first - mid;
		long long k = 0;
		bool pass = true;
		for (int i = 0; i < n; i++) {
			if (before_index + mid <= v[i].first) {
				before_index = v[i].first;
				k++;
			}
			else if (before_index + mid <= v[i].second) {
				before_index = before_index + mid;
				k++;
			}
		}
		if (pass == true && k >= n) {
			ret = max(ret, mid);
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	cout << ret;
	return 0;
}