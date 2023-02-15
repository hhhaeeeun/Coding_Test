#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
long long n;
long long k;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	long long lo = 1;
	long long hi = n * n;
	long long ans = n * n;

	while (lo <= hi) {
		long long mid = (hi + lo) / 2;
		long long val = 0;
		for (int i = 1; i <= n; i++) {
			val += min(n, mid / i);
		}

		if (k <= val) {
			hi = mid - 1;
			ans = min(ans, mid);
		}
		if (k > val)
			lo = mid + 1;

	}
	cout << ans;
	return 0;
}