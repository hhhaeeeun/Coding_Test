#include<algorithm>
#include<iostream>
using namespace std;
int n, m;
int dp[10001];
int a[101];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	fill(dp, dp + 10001, 100001);
	dp[0] = 0;
	for (int i = 1; i <= m; i++) {

		for (int j = 0; j < n; j++) {
			if (i - a[j] >= 0)
				dp[i] = min(dp[i], dp[i - a[j]] + 1);
			
		}
	}
	if (dp[m] == 100001)
		cout << "-1";
	else
		cout << dp[m];

}