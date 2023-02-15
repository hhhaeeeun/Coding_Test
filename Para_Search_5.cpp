#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
int n, m;
int a[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int lo = 1;
	int hi = 1000000000;
	int ans = 0;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int last_index = 0;
		int num = 1;
		for (int i = 0; i < n; i++) {
			if (a[i] - a[last_index] >= mid) {
				num++;
				last_index = i;
			}

		}

		if (num >= m) {
			lo = mid + 1;
			ans = max(mid, ans);
		}
		if (num < m) {
			hi = mid - 1;
		}
	}
	cout << ans;
	return 0;
}