#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
#include<set>
using namespace std;
int n;
const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };
int a[101][101];
int visited[101][101];
int dfs(int sy, int sx, int mid) {
	if (visited[sy][sx])
		return 0;
	visited[sy][sx] = 1;

	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int ny = sy + dy[i];
		int nx = sx + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (visited[ny][nx] == 1)continue;
		if (abs(a[ny][nx] - a[sy][sx]) > mid)continue;
		ret += dfs(ny, nx, mid);
	}
	return ret;
}


bool is_possible(int mid) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dfs(i, j, mid) * 2 >= n * n) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	vector<tuple<int, int, int >>v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int lo = 0;
	int hi = 1000000;

	int ret = INT_MAX;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		if (is_possible(mid)) {
			hi = mid - 1;
			ret = min(ret, mid);
		}
		else {
			lo = mid + 1;
		}
	}
	cout << ret;
	return 0;
}