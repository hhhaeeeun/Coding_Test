#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
int n, m;
const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };
int a[101][101];
int visited[101][101];
int color[101][101];
vector<pair<int, int>>v;
void dfs(int sy, int sx, int mid) {
	if (visited[sy][sx] == 1) return;
	visited[sy][sx] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = sy + dy[i];
		int nx = sx + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx] == 1)continue;
		if (abs(a[sy][sx] - a[ny][nx]) > mid) continue;
		dfs(ny, nx, mid);
	}

}
bool is_possible(int mid) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
		}
	}
	dfs(v[0].first, v[0].second, mid);

	for (auto i : v) {
		if (visited[i.first][i.second] == 0)
			return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("ps11.txt", "r", stdin);
	cin >> n>>m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> color[i][j];
			if (color[i][j] == 1) {
				v.push_back({ i,j });
			}
		}
	}
	int ret = INT_MAX;
	int lo = 0;
	int hi = 1000000000;
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