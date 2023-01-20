#include <iostream>
#include<algorithm>
#include<climits>
#include<cstring>
using namespace std;
int n;
int a[18][18];
int dp[18][1 << 16];
const int INF = 987654321;
int tsp(int now, int visited) {
	if (dp[now][visited] != -1)
		return dp[now][visited];
	//다 돌았을 때
	if (visited == (1 << n) - 1)
	{
		if (!a[now][0])
			return INF;
		return a[now][0];
	}
	dp[now][visited] = INF;

	for (int i = 0; i < n; i++) {
		//간적있거나 갈수 없으면 pass
		if (visited & (1 << i) || a[now][i] == 0) continue;
		dp[now][visited] = min(dp[now][visited], tsp(i, visited | (1 << i)) + a[now][i]);
	}
	return dp[now][visited];
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << tsp(0, 1) << endl;
	return 0;
}