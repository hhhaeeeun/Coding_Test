#include<bits/stdc++.h>
using namespace std;
int n, m, y, x, k;
int A[21][21];
int dy[5] = { 0, 0, 0, -1,1 };
int dx[5] = { 0, 1,-1, 0, 0 };
int dir[1001];
int dice[6] = { 0, };
int m_d[5][6] = { {0,1,2,3,4,5} , { 3,1,0,5,4,2}, {2,1,5,0,4,3}, {1,5,2,3,0,4}, {4,0,2,3,5,1} };

void move_dice(int v) {
	int temp[6] = { 0, };

	for (int i = 0; i < 6; i++)
	{
		temp[i] = dice[m_d[v][i]];
	}
	for (int i = 0; i < 6; i++)
	{
		dice[i] = temp[i];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> y >> x >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < k; i++)
	{
		cin >> dir[i];
	}
	int ny = y; int nx = x;
	for (int i = 0; i < k; i++)
	{
		ny += dy[dir[i]];
		nx += dx[dir[i]];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m)
		{
			ny -= dy[dir[i]];
			nx -= dx[dir[i]];
			continue;
		}

		move_dice(dir[i]);
		if (A[ny][nx])
		{
			dice[0] = A[ny][nx];
			A[ny][nx] = 0;
			cout << dice[5] << endl;
		}
		else
		{
			A[ny][nx] = dice[0];
			cout << dice[5] << endl;
		}
	}
	return 0;
}