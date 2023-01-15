#include<bits/stdc++.h>
using namespace std;
int n, m;
const int INF = 987654321;
int A[9][9];
int visited[9][9];
//위, 왼, 아래, 오
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0,-1,0,1 };
vector<pair<int, int>> cctv;
void cctv_on(int y, int x, int dir, int depth);
void cctv_off(int y, int x, int dir, int depth);
void check();
int cctv_dir_3[4][2] = { {0,1}, {0,3}, {1,2},{2,3} };
int cctv_dir_4[4][3] = { {0,1,2}, {0,2,3}, {0,1,3},{1,2,3} };
int ret = INF;
//일단 이쪽방향 키기
void cctv_on(int y, int x, int dir, int depth) {
	int ny = y; int nx = x;
	while (1) {
		ny += dy[dir];
		nx += dx[dir];
		if (A[ny][nx] == 6 || ny < 0 || ny >= n || nx < 0 || nx >= m){
			return;
		}
		if (visited[ny][nx] == 0)
			visited[ny][nx] = depth+1;
	}
}
//킨거 끄기
void cctv_off(int y, int x, int dir, int depth) {
	int ny = y; int nx = x;
	while (1) {
		ny += dy[dir];
		nx += dx[dir];
		if (A[ny][nx] == 6 || ny < 0 || ny >= n || nx < 0 || nx >= m) {
			return;
		}
		if( visited[ny][nx] == depth+1)
			visited[ny][nx] = 0;
	}
}
void check() {

	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 0 && A[i][j] == 0)
				temp++;
		}
	}
	ret = min(ret, temp);
}

void dfs( int depth) {
	//종료조건.. ? 
	if (depth == cctv.size())
	{
		check();
		return;
	}
	int y = cctv[depth].first;
	int x = cctv[depth].second;
	for (int i = 0; i < 4; i++) {
		if (A[y][x] == 1) {
			cctv_on(y, x, i,depth);
			dfs(depth + 1);
			cctv_off(y, x, i, depth);
		}
	}

	if (A[y][x] == 2) {
		for (int i= 0; i < 2; i++) {
			cctv_on(y, x, i, depth);
			cctv_on(y, x, i + 2, depth);
			dfs(depth + 1);
			cctv_off(y, x, i, depth);
			cctv_off(y, x, i + 2, depth);
		}
	}


	if (A[y][x] == 3) {
		for (int i = 0; i < 4; i++) {
			cctv_on(y, x, cctv_dir_3[i][0], depth);
			cctv_on(y, x, cctv_dir_3[i][1], depth);
			dfs(depth + 1);
			cctv_off(y, x, cctv_dir_3[i][0], depth);
			cctv_off(y, x, cctv_dir_3[i][1], depth);
		}
	}

	if (A[y][x] == 4) {
		for (int i = 0; i < 4; i++) {
			cctv_on(y, x, cctv_dir_4[i][0], depth);
			cctv_on(y, x, cctv_dir_4[i][1], depth);
			cctv_on(y, x, cctv_dir_4[i][2], depth);
			dfs(depth + 1);
			cctv_off(y, x, cctv_dir_4[i][0], depth);
			cctv_off(y, x, cctv_dir_4[i][1], depth);
			cctv_off(y, x, cctv_dir_4[i][2], depth);
		}
	}
	if (A[y][x] == 5) {
		for (int i = 0; i < 4; i++) {
			cctv_on(y, x, i, depth);
		}
		dfs(depth + 1);
	}


}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
			if (A[i][j] > 0 && A[i][j] < 6)
				cctv.push_back({ i,j });
		}
	}

	dfs(0);
	cout << ret << "\n";

	return 0;
}