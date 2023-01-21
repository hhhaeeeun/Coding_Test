#include<algorithm>
#include<iostream>
#include<climits>
using namespace std;
int t, w;
int a[1001];
int dp[1004][2];
void init() {
	fill(&dp[0][0], &dp[1003][2], INT_MIN);
	dp[0][0] = 0;
	for (int i = 1; i <= t; i++)
	{
		dp[i][0] = dp[i - 1][0] + (a[i] - 1 == 0);
	}
}
int main() {

	cin >> t >> w;
	for (int i = 1; i <= t; i++)
	{
		cin >> a[i];
	}
	init();
	for (int i = 1; i <= w; i++) {
		for (int j = 1; j <= t; j++) {
			dp[j][i % 2] = max(dp[j - 1][i % 2], dp[j - 1][(i % 2) ^ 1]) + ((a[j] - 1) == i % 2);
		}
	}
	int ret = 0;
	ret = max(dp[t][0], dp[t][1]);
	cout << ret;
	return 0;
}