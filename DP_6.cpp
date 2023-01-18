#include<algorithm>
#include<iostream>
using namespace std;
int n, m;
int a[101];
int dp[10001];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	fill(dp, dp + 10001, 10001);
	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = m; j > 0; j--)
		{
			if (j - a[i] < 0)break;
			if (dp[j - a[i]] != 10001)
				dp[j] = min(dp[j - a[i]] + 1, dp[j]);
		}
	}
	if (dp[m] == 10001)
		cout << "-1";
	else
		cout << dp[m];
	return 0;
}