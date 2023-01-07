#include<bits/stdc++.h>
using namespace std;
int n, m;
int A[51][51];
int visited[51][51];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0,-1,0,1 };


int bfs(int y, int x)
{
	fill(&visited[0][0], &visited[51][51], 0);
	int ret = 0;
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({ y,x });
	while (q.size())
	{
		int _y = q.front().first;
		int _x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = _y + dy[i];
			int nx = _x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
			if (visited[ny][nx]) continue;
			if (A[ny][nx] == 1)continue;
			visited[ny][nx] = visited[_y][_x] + 1;
			ret = max(ret, visited[ny][nx]);
			q.push({ ny,nx });
		}
	}
	return ret - 1;
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
			if (s[j] == 'W')A[i][j] = 1;
			else if (s[j] == 'L') A[i][j] = 0;
		}
	}

	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (A[i][j] == 0)
			{
				int now = bfs(i, j);
				ret = max(ret, now);
			}
		}
	}

	cout << ret << "\n";
	return 0;
}
