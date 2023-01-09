#include<bits/stdc++.h>
using namespace std;
int n, m;
char A[1004][1004];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0,-1,0,1 };
int J_visited[1004][1004];
int F_visited[1004][1004];
pair<int, int> J;
vector<pair<int, int>> F;
void J_bfs(int sy, int sx)
{
	J_visited[sy][sx] = 1;
	queue<pair<int, int>> q;
	q.push({ sy,sx });
	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (A[ny][nx] == '#') continue;
			if (J_visited[ny][nx]) continue;
			J_visited[ny][nx] = J_visited[y][x] + 1;
			q.push({ ny,nx });
		}
	}
}

void F_bfs(int sy, int sx)
{
	F_visited[sy][sx] = 1;
	queue<pair<int, int>> q;
	q.push({ sy,sx });
	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (A[ny][nx] == '#') continue;
			if (F_visited[ny][nx] == 0)
			{
				F_visited[ny][nx] = F_visited[y][x] + 1;
				q.push({ ny,nx });
			}
			else if (F_visited[ny][nx]>F_visited[y][x] + 1)
			{
				F_visited[ny][nx] = F_visited[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}
}

int main()
{
	int ret = 987654321;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
			if (A[i][j] == 'J')
				J = make_pair(i, j);
			if (A[i][j] == 'F')
			{
				F.push_back(make_pair(i, j));
			}
		}
	}
	for(int i = 0; i<F.size();i++)
		F_bfs(F[i].first,F[i].second);
	J_bfs(J.first, J.second);


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//가장자리
			if (i == n - 1 || i == 0 || j == 0 || j == m - 1)
			{
				if (A[i][j] == '#')continue;
				if (J_visited[i][j] == 0)continue;
				if (J_visited[i][j] < F_visited[i][j])
				{
					ret = min(ret, J_visited[i][j]);
				}
				else if (F_visited[i][j] == 0)
				{
					ret = min(ret, J_visited[i][j]);
				}
			}
		}
	}

	if (ret == 987654321)
		cout << "IMPOSSIBLE\n";
	else
		cout << ret<< "\n";
	return 0;
}






#if 0
#include<bits/stdc++.h>
using namespace std;
int n, m;
char A[1004][1004];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0,-1,0,1 };
int now_FIRE[1004][1004];
int visited[1004][1004];
pair<int, int> J;
vector<pair<int, int>> F;
struct b {
	int x, y, count;
};
void fire()
{
	if (J.first == n - 1 || J.first == 0 || J.second == 0 || J.second == m - 1)
	{
		cout << "1\n";
		return;
	}

	queue<b> q;
	q.push(b{ J.first,J.second,1 });
	visited[J.first][J.second] = 1;
	queue<pair<int, int>>new_fire;
	int now_count = 0;
	while (1) {
		now_count++;
		for (int i = 0; i < F.size(); i++)
		{
			for (int j = 0; j < 4; j++)
			{
				int fy = F[i].first + dy[j];
				int fx = F[i].second + dx[j];
				if (fy < 0 || fy >= n || fx < 0 || fx >= m) continue;
				if (A[fy][fx] == '#') continue;
				if (now_FIRE[fy][fx]) continue;
				now_FIRE[fy][fx] = 1;
				new_fire.push({ fy,fx });
			}
		}
		while (new_fire.size())
		{
			F.push_back({ new_fire.front().first, new_fire.front().second });
			new_fire.pop();
		}
		int is_possible = 0;
		while (q.front().count == now_count)
		{
			int y = q.front().x;
			int x = q.front().y;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int jy = y + dy[i];
				int jx = x + dx[i];
				if (jy < 0 || jy >= n || jx < 0 || jx >= m) continue;
				if (now_FIRE[jy][jx]) continue;
				if (A[jy][jx] == '#') continue;
				if (visited[jy][jx]) continue;
				if (jy == n - 1 || jy == 0 || jx == 0 || jx == m - 1)
				{
					//가장자리 도착!
					cout << visited[y][x] + 1 << "\n";
					return;
				}
				visited[jy][jx] = visited[y][x] + 1;
				q.push(b{ jy,jx,visited[jy][jx] });
				//길이 있다는 것을 확인
				is_possible = 1;
			}
		}
		if (is_possible == 0)
		{
			cout << "IMPOSSIBLE\n";
			return;
		}
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
			if (A[i][j] == 'J')
				J = make_pair(i, j);
			if (A[i][j] == 'F')
			{
				F.push_back(make_pair(i, j));
				now_FIRE[i][j] = 1;
			}
		}
	}
	fire();
	return 0;
}
#endif