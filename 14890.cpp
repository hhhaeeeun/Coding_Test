#include<bits/stdc++.h>
using namespace std;
int n, m, L, dir;
int A[101][101];
//위, 왼, 아래, 오
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0,-1,0,1 };

bool go(int y, int x, int dir) {
	vector<int> visited(n, 0);
	visited[0] = 1;
	int ty = y; int tx = x;
	for (int i = 1; i < n; i++)
	{
		int ny = ty + dy[dir];
		int nx = tx + dx[dir];
		int tmp = A[ty][tx] - A[ny][nx];
		if (tmp == 1)//내리막
		{
			if (visited[i - 1] < 0) return false;
			visited[i] = -L + 1;
		}
		if (tmp == 0)//평지
		{
			visited[i] = visited[i - 1] + 1;
		}
		if (tmp == -1)//오르막
		{
			if (visited[i - 1] < L) return false;
			else//올라갈수 있으면
			{
				visited[i] = 1;
			}
		}
		if (abs(tmp) > 1)//경사가 2 이상인 경우
		{
			return false;
		}
		ty = ny; tx = nx;
	}


	if (visited[n - 1] < 0)
		return false;
	return true;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> L;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	}
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		if (go(0, i, 2)) ret++;
		if (go(i, 0, 3)) ret++;
	}
	cout << ret << "\n";


	return 0;
}


