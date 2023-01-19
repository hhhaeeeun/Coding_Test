#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int m, n;
int a[101][10001];
int dp[10001];
vector<pair<int, int>> v;
int main() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		int w = 0; int val = 0;
		cin >> w >> val;
		v.push_back({ w,val });
	}
	fill(dp, dp + 10001, INT_MIN);
	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = m; j > 0; j--) {
			if (j < v[i].first)continue;
			dp[j] = max(dp[j - v[i].first] + v[i].second, dp[j]);
		}
	}

	int ret = 0;
	for (int i = 0; i <= m; i++)
	{
		ret = max(ret, dp[i]);
	}
	cout << ret << endl;
}