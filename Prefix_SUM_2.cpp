#include<iostream>
using namespace std;
int n, k;
int a[501][501];
int sum[501][501];
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> n >> k;

	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <=n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
		}
	}
	int ret = 0;
	for (int i = k; i <= n; i++) {
		for (int j = k; j <= n; j++) {
			int tmp = sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i - k][j - k];
			ret = max(tmp, ret);
		}
	}

	return 0;
}