#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
int n, m;
vector<pair<int, int>> v;
int dp[10001];
int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int w = 0; int val = 0;
		cin >> w >> val;
		v.push_back({ w,val });
	}
	fill(dp, dp + m, INT_MIN);
	dp[0] = 0;
	for(int i =0; i<v.size();i++){
		for (int j = 1; j <= m; j++) {
			if (j < v[i].first) continue;
			dp[j] = max(dp[j - v[i].first] + v[i].second, dp[j]);
		}
	}
	int ret = 0;
	for (int i = 0; i <= m; i++)
		ret = max(dp[i], ret);
	cout << ret;
	return 0;
}