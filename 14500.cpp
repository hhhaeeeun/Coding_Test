#include<bits/stdc++.h>
using namespace std;
int n, m;
int A[501][501];
int visited[501][501];
//À§, ¿Þ, ¾Æ·¡, ¿À
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0,-1,0,1 };
long long ret;
long long sum;
int all_sum(int y, int x, int k)
{
	int tmp = 0;
	tmp += A[y][x];
	for (int i = 0; i < 4; i++)
	{
		if (i == k)continue;
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) return -1;
		tmp += A[ny][nx];
	}
	return tmp;
}

void dfs(int y, int x) {
	
	if (visited[y][x] == 4)
	{
		ret = max(ret, sum);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx]) continue;
		sum += A[ny][nx];
		visited[ny][nx] = visited[y][x] + 1;
		dfs(ny, nx);
		visited[ny][nx] = 0;		
		sum -= A[ny][nx];
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
		}
	}
	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < m; j++) {
			visited[i][j] = 1;
			sum = A[i][j];
			dfs(i, j);
			visited[i][j] = 0;
			sum = 0;
		}
	}
	long long temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++)
				temp = all_sum(i, j, k);
			if (temp != -1)
			{
				ret = max(ret, temp);
			}
		}
	}
	cout << ret << "\n";

	return 0;
}