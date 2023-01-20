#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int a[18][18];
int dp[18][18][3];
//0 가로
//1 세로
//2 대각선

void init() {

	dp[0][1][0] = 1;
	for (int i = 2; i < n - 1; i++) {
		if (a[0][i] == 0) {
			dp[0][i][0] = dp[0][i - 1][0];
		}
	}
	return;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	init();
	

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (a[i][j] == 1)continue;
			if (a[i - 1][j] != 1 && a[i][j - 1] != 1)
			{
				for(int k =0; k<3; k++)
					dp[i][j][2] += dp[i - 1][j - 1][k];
			}
			dp[i][j][1] = dp[i - 1][j][2];
			dp[i][j][1] += dp[i - 1][j][1];
			dp[i][j][0] = dp[i][j - 1][2];
			dp[i][j][0] += dp[i][j - 1][0];
		}
	}
	int ret = 0;
	for (int i = 0; i < 3; i++)
		ret += dp[n - 1][n - 1][i];
	
	cout << ret;
	return 0;
}