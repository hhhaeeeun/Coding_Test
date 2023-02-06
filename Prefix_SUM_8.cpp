#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int n, k;
int a[401][401];
int sum[401][401];
int get_sum(int y, int x1, int x2) {
	if (y < 1 || y > n) return 0;
	if (x1 < 1)
		x1 = 1;
	if (x2 > n)
		x2 = n;
	return sum[y][x2] - sum[y][x1 - 1];
}
int bfs_sum(int sy, int sx) {
	int ret = 0;
	ret += get_sum(sy, sx - k, sx + k);
	for (int i = 1; i <= k; i++) {
		ret += get_sum(sy-i, sx - k + i, sx + k - i);
		ret += get_sum(sy+i, sx - k + i, sx + k - i);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	freopen("ps8.txt", "r", stdin);
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum[i][j] = sum[i][j - 1] + a[i][j];
		}
	}
	//get_sum(1, -1, n + 1);
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ret = max(ret, bfs_sum(i, j));
		}
	}
	cout << ret << '\n';
	return 0;
}