#include<bits/stdc++.h>
using namespace std;
int n, l, r;
int A[51][51];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0,-1,0,1 };
int visited[51][51];
int check[51][51];
vector<pair<int, int>> v;
int ret;
int open;
bool is_open(int y, int x, int ny, int nx)
{

	if (abs(A[y][x] - A[ny][nx]) >= l && abs(A[y][x] - A[ny][nx]) <= r)
	{
		return true;
	}
	return false;
}
void dfs(int y, int x)
{
	check[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n)continue;
		if (check[ny][nx] == 0)
		{
			if (is_open(y, x, ny, nx))
			{
				if (visited[y][x] == 0)
				{
					open++;
					visited[y][x] = open;
					v[open].first += A[y][x];
					v[open].second++;
				}			
				visited[ny][nx] = open;
				v[open].first += A[ny][nx];
				v[open].second++;
				dfs(ny, nx);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	}
	int ret = 0;
	v.resize(n*n+1);
	while (1) {
		//연합 계산
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dfs(i, j);
			}
		}
		//visited가 다 똑같으면 그만!
		//visited가 안똑같으면 계속
		int is_keep_going = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j])
				{
					A[i][j] = v[visited[i][j]].first / v[visited[i][j]].second;
					is_keep_going = 1;
				}
			}
		}

		if (is_keep_going == 0)
			break;
		else
			ret++;
		fill(&visited[0][0], &visited[50][51], 0);
		fill(&check[0][0], &check[50][51], 0);
		fill(v.begin(), v.end(), make_pair(0, 0));
		open = 0;
	}
	cout << ret << "\n";
	return 0;
}
