#include<bits/stdc++.h>
using namespace std;
int n, m,k;
int A[6][6];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0,-1,0,1 };
int ans;
int visited[6][6];
void dfs(int y, int x)
{
	if (y == 0 && x == (m - 1))
	{
		if (visited[y][x] == k)
			ans++;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
		if (visited[ny][nx] == 0 && A[ny][nx] == 0)
		{
			visited[ny][nx] = visited[y][x] + 1;
			dfs(ny, nx);
			visited[ny][nx] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		string s = "";
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			if (s[j] == '.') A[i][j] = 0;
			else if(s[j] == 'T') A[i][j] = 1;
		}
	}
	visited[n - 1][0] = 1;
	dfs(n - 1, 0);

	cout << ans << "\n";
	return 0;
}