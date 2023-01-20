#include<algorithm>
#include<iostream>
#include<climits>
using namespace std;

int n, m;
int a[50][50];
//À§, ¿Þ, ¾Æ·¡, ¿À
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0, -1, 0, 1 };
int dp[51][51];
int visited[51][51];

bool in(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= m)
		return false;
	return true;
}

int down(int y, int x) {
	if (a[y][x] == 0 || in(y, x) == false)
	{
		return 0;
	}
	if (visited[y][x]) {
		cout << -1 << "\n";
		exit(0);
	}
	if (dp[y][x]) return dp[y][x];


	int jump = a[y][x];
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + jump * dy[i];
		int nx = x + jump * dx[i];
		dp[y][x] = max(dp[y][x], down(ny, nx) + 1);
	}
	visited[y][x] = 0;
	return dp[y][x];
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s = "";
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'H') a[i][j] = 0;
			else a[i][j] = s[j] - '0';
		}
	}

	cout << down(0, 0) << '\n';


}

