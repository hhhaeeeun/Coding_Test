#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
int a[50001];
int sum[50001];
unordered_map<int, int> m;
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("pp_4.txt", "r", stdin);
	cin >> n;
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = (sum[i - 1] + a[i]) % 7;
		if (m.find(sum[i]) == m.end()) {
			m[sum[i]] = i;
		}
		else
		{
			ret = max(ret, i - m[sum[i]]);
		}
	}
	cout << ret;
	return 0;
}