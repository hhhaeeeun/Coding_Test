#include<bits/stdc++.h>
using namespace std;
int n, m, r, c, d, ret;
int A[51][51];
int visited[51][51];
//위, 오, 아래, 왼
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0,1,0,-1 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> A[i][j];
	}
	ret = 1;
	visited[r][c] = 1;
	int dir = d;
	int y = r;
	int x = c;

	while (1) {
		//네 방향 탐색
		int p = 0;
		for (int i = 0; i < 4; i++) {
			dir = (dir + 3) % 4;
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (visited[ny][nx] == 1 || A[ny][nx] == 1 || ny < 0 || ny >= n || nx < 0 || nx >= m) {
				continue;
			}
			if (visited[ny][nx] == 0 && A[ny][nx] == 0) {
				p = 1; y = ny; x = nx;
				visited[ny][nx] = 1;
				ret++;
				break;
			}
		}
		//네 방향 모두 청소됨
		if (p == 0) {
			//남쪽으로 빠꾸,방향은 유지
			int ny = y + dy[(dir + 2) % 4];
			int nx = x + dx[(dir + 2) % 4];
			if (A[ny][nx] == 1 || ny < 0 || ny >= n || nx < 0 || nx >= m) {
				break;
			}
			else
			{
				y = ny; x = nx;
			}
		}
		
	}
	cout << ret << "\n";
	return 0;
}