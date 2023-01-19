#include<algorithm>
#include<iostream>
#include<climits>
using namespace std;

int n, m;
int a[101];
int dp[101];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	fill(dp, dp+ n, INT_MIN);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {

		for (int j = 0; j <= i; j++)
		{
			
			dp[i] = max(dp[i - j] + a[j], dp[i]);
		}
	}
	cout << dp[n] << endl;
	return 0;
}