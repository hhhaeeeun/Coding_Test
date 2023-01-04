#include<bits/stdc++.h>
using namespace std;
int n, m;
int matrix[101][101];
int visited[101][101];
int A[101][101];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0,-1,0,1 };
void bfs(int y, int x) {
	A[0][0] = 1;
	queue<pair<int,int>> q;

	visited[y][x] = 1;
	q.push(make_pair(x, y));
	while (q.size() != 0)
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny > n || nx < 0 || nx > m) continue;
			if (visited[ny][nx] == true || matrix[ny][nx] == 0) continue;
			visited[ny][nx] = true;
			q.push(make_pair(ny, nx));
			A[ny][nx] = A[y][x] + 1;
		}
	}


}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s = "";
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = s[j] - '0';
		}
	}

	bfs(0, 0);

	cout << A[n - 1][m - 1] << "\n";

	return 0;
}