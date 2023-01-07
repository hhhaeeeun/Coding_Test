#include<bits/stdc++.h>
using namespace std;
int n, m;
int A[20][20];
int visited[20][20][20][20];
pair<int, int> red;
pair<int, int> blue;
pair<int, int> hole;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int ans_count;

struct bead {
	int ry, rx, by, bx, c;
};

queue<bead> q;

void move(int& y, int& x, int& dy, int& dx, int& d)
{
	while (A[y+dy][x+dx] != 1 && A[y][x] != 5)
	{
		y += dy;
		x += dx;
		d++;
	}
}
void bfs() {

	while (q.size())
	{
		bead now = q.front(); q.pop();
		if (now.c >= 10)break;
		for (int i = 0; i < 4; i++)
		{
			int rny = now.ry; int bny = now.by;
			int rnx = now.rx; int bnx = now.bx;
			int rd = 0; int bd = 0;
			move(rny, rnx, dy[i], dx[i], rd);
			move(bny, bnx, dy[i], dx[i], bd);

			if (bny == hole.first && bnx == hole.second)
			{
				continue;
			}
			if (rny == hole.first && rnx == hole.second)
			{
				cout << now.c + 1 << "\n";
				return;
			}
			if (rny == bny && rnx == bnx)
			{
				if (rd > bd) //red가 많이 움직이면
				{
					rny -= dy[i];
					rnx -= dx[i];
				}
				else
				{
					bny -= dy[i];
					bnx -= dx[i];
				}
			}

			if (visited[rny][rnx][bny][bnx] == false)
			{
				visited[rny][rnx][bny][bnx] = true;
				q.push(bead{ rny,rnx,bny,bnx, now.c + 1 });
			}
		}

	}
	cout << "-1\n";
	return;
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
			if (s[j] == '#')
			{
				A[i][j] = 1;
			}
			else if (s[j] == 'B')
			{
				blue = make_pair(i, j);
			}
			else if (s[j] == 'R')
			{
				red = make_pair(i, j);
			}
			else if (s[j] == 'O')
			{
				hole = make_pair(i, j);
				A[i][j] = 5;
			}
		}
	}

	visited[red.first][red.second][blue.first][blue.second] = true;
	q.push(bead{ red.first, red.second,blue.first,blue.second,ans_count });
	bfs();
	return 0;
}