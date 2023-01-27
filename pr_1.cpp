#pragma warning(disable:4996)
#include<iostream>
#define MAXN	50
using namespace std;
int n;
int A[51][51];
int dp[51][51][4];
//¿ì: 0, ¾Æ·¡ : 1, ÁÂ : 2, À§ : 3
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int visited[51][51];
int ans;
const int temp_max = MAXN * MAXN + 1;
int er, ec;
void go(int y, int x, int dir, int length) {
	if (y == er && x == ec)
	{
		ans = min(ans, length);
		return;
	}
	if (y < 0 || y >= n || x < 0 || x >= n)return;
	if (A[y][x] == 0)return;
	if (visited[y][x] == 1)return;
	int& ret = dp[y][x][dir];

	if (ans < length) return;
	if (ret < length) return;
	visited[y][x] = 1;
	ret = length;
	if (A[y][x] < 3)
		go(y + dy[dir], x + dx[dir], dir, length + 1);
	else
	{
		if (dir == 0 || dir == 2) {
			go(y + 1, x, 1, length + 1);
			go(y - 1, x, 3, length + 1);
		}
		if (dir == 1 || dir == 3) {
			go(y, x + 1, 0, length + 1);
			go(y, x - 1, 2, length + 1);
		}
	}
	visited[y][x] = 0;
	return;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> A[i][j];
			}
		}
		
		ans = (51 * 51) + 1;
		er = n - 1, ec = n;
		fill(&visited[0][0], &visited[50][51], 0);
		fill(&dp[0][0][0], &dp[50][51][4], temp_max);
		go(0, 0, 0, 0);
		fill(&visited[0][0], &visited[50][51], 0);
		fill(&dp[0][0][0], &dp[50][51][4], temp_max);
		er = 0, ec = -1;
		go(n - 1, n - 1, 2, 0);
		cout << "#" << test_case << " " << ans << "\n";
		fill(&A[0][0], &A[50][51], 0);
	}
	return 0;
}