#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0,-1,0,1 };
int n, m;
int a[101][101];
int visited[101][101];
/*
bool is_possible(int mid) {
	queue<pair<int, int>>q;

	q.push({ 0,0 });
	visited[0][0] = 1;
	int min_h = a[0][0];
	int max_h = a[0][0];
	while (q.size()) {
		int y = q.front().first; int x = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
			if (visited[ny][nx] == 1)continue;
			int now_minh = min(min_h, a[ny][nx]);
			int now_maxh = max(max_h, a[ny][nx]);
			if (now_maxh - now_minh > mid)continue;

			min_h = now_minh;
			max_h = now_maxh;
			q.push({ ny,nx });
			visited[ny][nx] = 1;
		}
	}

	if (visited[n - 1][m - 1] == 1)
		return true;
	return false;

}
*/

int dfs(int sy, int sx, int min_h, int max_h) {
	if (visited[sy][sx] == 1) return 0;
	visited[sy][sx] = 1;
	if (sy == n - 1 && sx == m - 1) {
		return 0;
	}
	for (int i = 0; i < 4; i++) {
		int ny = sy + dy[i];
		int nx = sx + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
		if (visited[ny][nx] == 1)continue;
		if (min_h > a[ny][nx]) continue;
		if (max_h < a[ny][nx])continue;
		dfs(ny, nx, min_h, max_h);
	}
}
void clear_visited() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
		}
	}
}
bool is_possible(int mid) {

	for (int lo = 1; lo <= 500; lo++) {
		clear_visited();

		int hi = lo + mid;
		if (a[0][0] >= lo && a[0][0] <= hi)
			dfs(0, 0, lo, hi);
		if (visited[n - 1][m - 1]) return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("ps16.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int lo = 0;
	int hi = 500;
	int ret = 500;
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