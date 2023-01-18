#if 0
#include<algorithm>
#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
int n;
int A[501][501];
int visited[501][501];
struct b {
	int val; int y; int x;
};
vector<b>v;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0,-1,0,1 };
bool cmp(b a_, b b_) {
	return a_.val < b_.val;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
			v.push_back(b{ A[i][j], i, j });
		}
	}
	sort(v.begin(), v.end(),cmp);
	fill(&visited[0][0], &visited[500][501], 1);
	for (int num = 0; num < v.size(); num++) {
		int y = v[num].y; int x = v[num].x;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)continue;
			if (A[ny][nx] > A[y][x])
				visited[ny][nx] = max(visited[ny][nx], visited[y][x] + 1);
		}
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			ret = max(ret, visited[i][j]);
		}
	}



	cout << ret << endl;
	return 0;
}

#endif

#include<algorithm>
#include<iostream>
using namespace std;
int n;
int A[101][101];
int dp[101][101];
const int INF = 987654321;
void init() {

	dp[0][0] = A[0][0];

	for (int i = 1; i < n; i++) {
		dp[0][i] = max(A[0][i], dp[0][i - 1]);
	}

	for (int i = 1; i < n; i++) {
		dp[i][0] = max(A[i][0], dp[i - 1][0]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	}

	init();
	int ret = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			dp[i][j] = max(min(dp[i - 1][j], dp[i][j - 1]), A[i][j]);
		}
	}
	ret = dp[n - 1][n - 1];
	cout <<ret << '\n';

	return 0;
}


