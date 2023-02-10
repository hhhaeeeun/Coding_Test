#define _CRT_SECURE_NO_WARNINGS
#include<algorithm>
#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int n;
int a[101][101];
int n_sum[10001][101][101];
unordered_set<int> s;
int get_max(int y1, int y2) {
	int ret = 0;
	int dp[101] = { 0, };
	bool is_it = false;
	for (int i = 1; i <= n; i++) {
		for (auto k : s) {
			if (n_sum[k][y2][i] - n_sum[k][y1 - 1][i] > 1) {
				dp[i] = 0;
				is_it = true;
				break;
			}
		}
		if (is_it == false) {
			dp[i] = dp[i - 1] + 1;
			ret = max(ret, dp[i]);
		}
		else
		{
			is_it = false;
		}
	}
	return ret * (y2 - y1 + 1);
}

int main(int argc, char** argv)
{

	int test_case;
	int T;
	freopen("input_230128.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
				++n_sum[a[i][j]][i][j];
				s.insert(a[i][j]);
			}
		}
		for (auto k : s) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					n_sum[k][i][j] += n_sum[k][i - 1][j] + n_sum[k][i][j - 1] - n_sum[k][i - 1][j - 1];
				}
			}
		}
		int ret = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if (n * (j - i + 1) < ret)continue;
				ret = max(get_max(i, j), ret);
			}
		}
		cout << '#' << test_case << ' ' << ret << '\n';
	}
	return 0;
}