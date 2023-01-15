#include<bits/stdc++.h>
using namespace std;
int n, m, ret;
int visited[101][101];
//¿À À§ ¿Þ ¾Æ·¡
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };
const int INF = 987654321;
struct b
{
	int y; int x; vector<int> dir; int g;
	void rotate() {
		for (int j = 0; j < g; j++) {
			int num = dir.size();
			for (int i = num; i > 0; i--)
			{
				dir.push_back((dir[i-1]+1) % 4);
			}
		}
	}
	void go() {
		int ny = y; int nx = x;
		visited[ny][nx] = 1;
		for (int i = 0; i < dir.size(); i++)
		{
			ny += dy[dir[i]];
			nx += dx[dir[i]];
			visited[ny][nx] = 1;
		}
	}

};
void check() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (0 == visited[i][j])continue;
			if (0 == visited[i + 1][j])continue;
			if (0 == visited[i][j + 1])continue;
			if (0 == visited[i + 1][j + 1])continue;
			ret++;
		}
	}
	return;
}
vector<pair<int, int>> v;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		b temp; int dir;
		cin >> temp.x >> temp.y >> dir >> temp.g;
		temp.dir.push_back(dir);
		temp.rotate();
		temp.go();
	}
	check();
	cout << ret << "\n";
	return 0;
}