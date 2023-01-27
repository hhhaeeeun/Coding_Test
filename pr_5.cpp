#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int n, m;
int a[12][27];
int visited[12][27];
int dy[3] = { 1, 0, 1 };
int dx[3] = { 0, 1, 1 };
//12
int dp[4][12][27];
bool is_possible(int sy, int sx) {
	if (a[sy][sx] == 1)
		return false;
	if (visited[sy][sx] == 1)
		return false;
	for (int i = 0; i < 3; i++) {
		int ny = sy + dy[i];
		int nx = sx + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m)
			return false;
		if (visited[ny][nx] == 1 || a[ny][nx] == 1)
			return false;
	}
	return true;
}
void yes_visited(int sy, int sx, int dir, int ret) {
	dp[dir][sy][sx] = ret;
	visited[sy][sx] = 1;
	for (int i = 0; i < 3; i++) {
		dp[dir][sy + dy[i]][sx + dx[i]] = ret;
		visited[sy + dy[i]][sx + dx[i]] = 1;
	}
	return;
}

void no_visited(int sy, int sx) {

	for (int i = 0; i < 3; i++) {
		visited[sy + dy[i]][sx + dx[i]] = 0;
	}
	return;
}
int go_0() {
	int ret = 0;
	for (int i = 0; i <n; ++i) {
		for (int j = 0; j < m; j++) {
			if (is_possible(i, j))
			{
				++ret;
				yes_visited(i, j, 0, ret);
			}
		}
	}
	return ret;
}
int go_1() {
	int ret = 0;
	for (int i = n-1; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			if (is_possible(i, j))
			{
				++ret;
				yes_visited(i, j, 1, ret);
			}
		}
	}
	return ret;
}
int go_2() {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = n-1; j >= 0; j--) {
			if (is_possible(i, j))
			{
				++ret;
				yes_visited(i, j, 2, ret);
			}
		}
	}
	return ret;
}
int go_3() {
	int ret = 0;
	for (int i = n-1; i >= 0; --i) {
		for (int j = n-1; j >= 0; --j) {
			if (is_possible(i, j))
			{
				++ret;
				yes_visited(i, j, 3, ret);
			}
		}
	}
	return ret;
}
void reset_visited() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
		}
	}
}
void reset_dp() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				dp[k][i][j] = 0;
			}
		}
	}
}
int main() {

	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);


	int test_case;
	int T;
	freopen("sample_sample_input_pr_5.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}


		int ret = 0;
		ret = max(ret, go_0());
		reset_visited();
		ret = max(ret, go_1());
		reset_visited();
		ret = max(ret, go_2());
		reset_visited();
		ret = max(ret, go_3());
		reset_visited();
		int l = 0;
		int r = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (dp[0][i][j] > l) {
					l = dp[0][i][j];
					visited[i][j] = 1;
					for (int k = 0; k < 3; k++) {
						int ny = i + dy[k];
						int nx = j + dx[k];

						visited[ny][nx] = 1;
						if (dp[3][ny][nx])
							r = min(r, dp[3][ny][nx]);
					}
				}
				else if (visited[i][j] == 0 && dp[3][i][j]<r) {
					ret = max(ret, l + dp[3][i][j]);
				}
			}
		}
		reset_visited();

		l = 0;
		 r = 0;
		 for (int i = n - 1; i >= 0; i--) {
			 for (int j = 0; j < m; j++) {
				if (dp[1][i][j] > l) {
					l = dp[1][i][j];
					visited[i][j] = 1;
					for (int k = 0; k < 3; k++) {
						int ny = i + dy[k];
						int nx = j + dx[k];

						visited[ny][nx] = 1;
						if (dp[2][ny][nx])
							r = min(r, dp[2][ny][nx]);
					}
				}
				else if (visited[i][j] == 0 && dp[2][i][j] < r) {
					ret = max(ret, l + dp[2][i][j]);
				}
			}
		}
		reset_visited();
		reset_dp();
		cout << '#' << test_case << ' ' << ret << '\n';
	}


	return 0;
}