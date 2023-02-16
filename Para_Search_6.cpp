#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
long long n, m;
long long a[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("ps6.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	sort(a, a + m);
	long long ret = LLONG_MAX;
	long long lo = 1;
	long long hi = a[m - 1] * n;
	while (lo <= hi) {
		long long mid = (lo + hi) / 2;

		long long k = 0;

		for (int i = 0; i < m; i++) {
			k += mid/ a[i];
		}
		if (k < n) {
			lo = mid + 1;
		}
		if (k >= n) {
			hi = mid - 1;
			ret = min(ret, mid);
		}
	}

	cout << ret;
	return 0;
}