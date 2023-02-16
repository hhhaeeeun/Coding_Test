#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
int n, t;
int a[10001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("ps9.txt", "r", stdin);
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int lo = 1;
	int hi = n;
	int ret = INT_MAX;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		priority_queue<int> q;
		for (int i = 0; i < mid; i++) {
			q.push(-a[i]);
		}
		for (int i = mid; i < n; i++) {
			int now = q.top() * (-1); q.pop();
			q.push((now + a[i]) * (-1));
		}
		int last = 0;
		while (q.size()) {
			last = q.top() * (-1); q.pop();
		}

		if (last <= t) {
			hi = mid - 1;
			ret = min(ret, mid);
		}
		else {
			lo = mid + 1;
		}
	}
	cout << ret;
	return 0;
}