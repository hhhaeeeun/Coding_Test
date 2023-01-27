#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int H, W, ans;
int map[10][25];
int dp[(1 << 10)][24];

bool check(int x, int y) {
    if (x + 1 >= H || y + 1 >= W) return false;
    if (map[x][y] || map[x + 1][y] || map[x][y + 1] || map[x + 1][y + 1]) return false;
    return true;
}

void dfs(int x, int y, int cnt) {
    if (x >= H - 1) {
        x = 0;
        y++;
    }
    if (y == W - 1) {
        if (ans < cnt)
            ans = cnt;
        return;
    }
    if (x == 0) {
        int bit = 0;
        for (int i = 0; i < H; i++)
            bit |= (map[i][y] << i);
        if (dp[bit][y] >= cnt) return;
        dp[bit][y] = cnt;
    }
    if (check(x, y)) {
        map[x][y] = map[x + 1][y] = map[x][y + 1] = map[x + 1][y + 1] = 1;
        dfs(x + 2, y, cnt + 1);
        map[x][y] = map[x + 1][y] = map[x][y + 1] = map[x + 1][y + 1] = 0;
    }
    dfs(x + 1, y, cnt);
}

int main() {

	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	int test_case;
	int T;
	freopen("sample_sample_input_pr_5.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
        cin >> H >> W;
        int i, j;
        for (i = 0; i < H; i++)
            for (j = 0; j < W; j++)
                cin >> map[i][j];

        for (i = 0; i < (1 << H); i++)
            for (int j = 0; j < W; j++)
                dp[i][j] = -1;

        ans = 0;
        dfs(0, 0, 0);
        cout << "#" << test_case << " " << ans << '\n';
	}
	return 0;
}