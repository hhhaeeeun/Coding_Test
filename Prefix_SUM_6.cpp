#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int n, k;
int a[301][301];
int sum[301][301];
int get_max_sum(int x1, int x2) {
	int m_sum[301] = { 0, };
	int dp[301] = { 0, };
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		m_sum[i] = sum[x2][i] - sum[x1 - 1][i] - sum[x2][i - 1] + sum[x1 - 1][i - 1];
		dp[i] = max(m_sum[i], dp[i - 1] + m_sum[i]);
		ret = max(ret, dp[i]);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	freopen("ps6.txt", "r", stdin);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
		}
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			ret = max(ret, get_max_sum(i, j));
		}
	}
	cout << ret;
	return 0;
}