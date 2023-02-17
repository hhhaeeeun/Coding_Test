#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
long long n, m, c;
long long a[1000001];
bool is_possible(int mid) {
	long long bus = 1;
	long long wait = a[0];
	long long count = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] - wait > mid || count >= c) {
			wait = a[i];
			bus++;
			count = 1;
		}
		else {
			++count;
		}

	}
	return (bus <= m);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> c;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	long long lo = 0;
	long long hi = 1e9;
	long long ret = 1e9;
	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		if (is_possible(mid)) {
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