#include<algorithm>
#include<iostream>
using namespace std;
int n, m;
int a[101];
int dp[10001];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	fill(dp, dp + 10001, -23443252);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {

		for (int j = m; j > 0; j--) {
			if (j< a[i])continue;
			dp[j] = max(dp[j],dp[j-a[i]]+1);
		}
	}
	if (dp[m] < 1)
		cout << "No";
	else
		cout << "Yes";
	return 0;
}