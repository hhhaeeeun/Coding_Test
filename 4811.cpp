#include<algorithm>
#include<iostream>
#include<climits>
using namespace std;
int n;
int a[1001];
int dp[1001][1001];

void init(int num) {

	for (int i = 1; i < num; i++) {
		dp[i][0] = 1;
	}
}
//num : 알약개수
int go(int num) {


	for (int i = 1; i < num; i++) {
		for (int j = 1; j < num; j++) {
			if (dp[i][j]) continue;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	return dp[num - 1][num - 1];
}

int main() {

	int ret = 1;
	while (1) {
		cin >> ret;
		if (ret == 0)break;
		a[n++] = ret;
	}
	
	for (int i = 0; i < n; i++) {

		cout << go(a[i]) << endl;
	}
	return 0;
}