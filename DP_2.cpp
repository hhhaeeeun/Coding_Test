#include<algorithm>
#include<iostream>
#include <climits>

using namespace std;
int dp[51][51];
int a[51][51];
int n, m, ret;

void jump(int sy, int sx) {

	for (int i = 0; i < sy; i++) {
		for (int j = 0; j < sx; j++) {
			if (a[i][j] < a[sy][sx])
			{
				dp[sy][sx] = max(dp[sy][sx], dp[i][j] + 1);
			}
		}
	}
}
int main() {

	cin >> n>>m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	fill(&dp[0][0], &dp[50][51], INT_MIN);
	
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			jump(i, j);
		}
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ret = max(ret, dp[i][j]);
		}
	}
	cout << ret;
	return 0;
}