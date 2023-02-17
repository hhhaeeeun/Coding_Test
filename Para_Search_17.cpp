#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
long long n, k, l;
int a[100001];
int post[100001];
bool is_possible(int mid) {
	long long s = 0;
	for (int i = n - 1; i >= n - mid; --i) {
		if (a[i] >= mid) {
		}
		else {
			s += mid - a[i];
		}
	}
	if (s <= k * l && a[n - mid] + k >= mid)
		return true;
	return false;

}
void init_post() {
	for (int u = 0; u < 100001; u++) {
		post[u] = 0;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k >> l;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int lo = 0;
	int hi = n;
	int ret = 0;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		if (is_possible(mid)) {
			lo = mid + 1;
			ret = max(ret, mid);
		}
		else {
			hi = mid - 1;
		}
		init_post();
	}
	cout << ret;
	return 0;
}