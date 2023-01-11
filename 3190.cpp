#include<bits/stdc++.h>
using namespace std;
int n, m;
int A[101][101];
const int dy[] = { 0, +1, 0, -1 };
const int dx[] = { +1, 0, -1, 0 };
int ret;
char cmd[10001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int y = 0; int x = 0;
		cin >> y >> x;
		A[y][x] = 1;
	}
	int time = 0;
	cin >> m;
	for (int i = 0; i < m; i++) {
		 char c = ' ';
		cin >> time >> c;
		cmd[time] = c;
	}

	int ny = 1; int nx = 1;
	int dir = 0;
	time = 0;
	queue<pair<int, int>> tail;
	A[1][1] = -1;
	tail.push({ 1,1 });
	int k = 0; char x = ' ';
	while (1)
	{
		++time;
		ny += dy[dir];
		nx += dx[dir];
		if (A[ny][nx]==-1 || ny < 1 || ny > n || nx < 1 || nx > n)		{
			break;
		}
		if (A[ny][nx] == 0)
		{
			A[tail.front().first][tail.front().second] = 0;
			tail.pop();
		}
		A[ny][nx] = -1;
		tail.push({ ny,nx });

		if (cmd[time] == 'D') {
			dir = (dir + 1) % 4;
		}
		if (cmd[time] == 'L') {
			dir = (dir + 3) % 4;
		}
	}
	printf("%d\n", time);
	return 0;
}
