#include<bits/stdc++.h>
using namespace std;
int n, m;
int A[51][51];
int visited[51][51];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0,-1,0,1 };


int bfs(int y, int x)
{
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
			if (visited[ny][nx] == 0 && A[ny][nx] == 0)
			{
				visited[ny][nx] = visited[_y][_x] + 1;
				if (ret < visited[ny][nx])
				{
					ret = visited[ny][nx];
				}
				q.push({ ny,nx });
			}
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
			else A[i][j] = 0;
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (A[i][j] == 0)
			{
				int now = bfs(i, j);
				memset(visited, 0, sizeof(visited));
				//fill(&visited[0][0], &visited[50][51], 0);
				if (max < now)
				{
					max = now;
				}
			}
		}
	}

	cout << max << "\n";
	return 0;
}



//int visited[50][50]
//memset(visited, 0, sizeof(visited));
// memset(배열 이름, 초기화 값, 배열 크기);
//fill(&visited[0][0], &visited[49][50], 0);
//fill(&arr[0][0], &arr[ROW - 1][COL], value)
//fill(시작 위치, 끝나는 위치 + 1, 초기화 값);