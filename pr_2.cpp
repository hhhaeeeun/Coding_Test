#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
const int max_num = 1 << 20;
int n;
int box[21][3];
int dp[21][max_num][3];
int box_go(int row, int col, int idx, int dir, int mode) {
	int& ret = dp[idx][dir][mode];
	if (ret) return ret;

	for (int i = 1; i <= n; i++) {
		if (dir & (1 << (i-1)))continue;
		if (row >= box[i][0] && col >= box[i][1]) {
			ret = max(ret, box[i][2] + box_go(box[i][0], box[i][1], i, (dir | (1 << (i-1))), 0));
		}
		if (row >= box[i][0] && col >= box[i][2]) {
			ret = max(ret, box[i][1] + box_go(box[i][0], box[i][2], i, (dir | (1 << (i - 1))), 1));
		}
		if (row >= box[i][1] && col >= box[i][2]) {
			ret = max(ret, box[i][0] + box_go(box[i][1], box[i][2], i, (dir | (1 << (i - 1))), 2));
		}
	}
	return ret;
}


int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("sample_sample_input_pr_2.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d\n", &n);
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < 1 << (n); j++) {
				for (int k = 0; k < 3; k++) dp[i][j][k] = 0;
			}
		}
		int a_max = 0;
		for (int i = 1; i <= n; i++) {
			int t[3] = { 0, };
			cin >> t[0] >> t[1] >> t[2];
			sort(t, t + 3);
			a_max = max(a_max, t[0]);
			for (int j = 0; j < 3; j++)
				box[i][j] = t[j];
		}
		box[0][2] = box[0][0] = box[0][1] = 0x3f3f3f3f;
		a_max = box_go(0x3f3f3f3f, 0x3f3f3f3f, 0, 0, 0);
		cout << "#" << test_case << " " << a_max << '\n';
		//fill(&box[0][0], &box[20][3], 0);
		//fill(&dp[0][0][0], &dp[20][max_num][3], 0);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

#if 0
int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("sample_sample_input_pr_2.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		{
			scanf("%d\n", &n);
			for (int i = 0; i <= n; i++) {
				for (int j = 0; j < 1 << (n); j++) {
					for (int k = 0; k < 3; k++) dp[i][j][k] = 0;
				}
			}
			for (int i = 1; i <= n; i++) {
				scanf("%d %d %d\n", &box[i][0], &box[i][1], &box[i][2]);
				if (box[i][0] > box[i][1]) swap(box[i][0], box[i][1]);
				if (box[i][1] > box[i][2]) swap(box[i][1], box[i][2]);
				if (box[i][0] > box[i][1]) swap(box[i][0], box[i][1]);
			}
			int a_max = 0;
			box[0][2] = box[0][0] = box[0][1] = 0x3f3f3f3f;
			a_max = box_go(0x3f3f3f3f, 0x3f3f3f3f, 0, 0, 0);

			cout << "#" << test_case << " " << a_max << '\n';
		}
		return 0;//정상종료시 반드시 0을 리턴해야합니다.
	}
}
#endif