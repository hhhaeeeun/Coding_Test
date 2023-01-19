#include<algorithm>
#include<iostream>
using namespace std;

int n,m;
int dp[10001];
int a[1001];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	fill(dp, dp + 10001, -232154);
	dp[0] = 0;
	sort(a, a+n);
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < n; j++) {
			if (i < a[j]) continue;
			dp[i] = max(dp[i - a[j]] + 1, dp[i]);
		}
	}
	if(dp[m])
		cout << dp[m];
	cout << "-1\n";
	return 0;
}