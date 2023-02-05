#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int n, k, b;
int a[100001];
int sum[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	freopen("ps4.txt", "r", stdin);
	cin >> n >> k >> b;
	for (int i = 0; i < b; i++) {
		int x = 0; cin >> x;
		a[x] = 1;
	}
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	int ret = INT_MAX;
	for (int i = k; i <= n; i++) {
		int tem = sum[i] - sum[i - k];
		ret = min(tem, ret);
	}
	cout << ret;
	return 0;
}