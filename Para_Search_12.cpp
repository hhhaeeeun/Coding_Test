#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
int n, m;
int a[50001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("ps12.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);

	int lo = 1;
	int hi = 20;
	int ret = INT_MAX;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int k = 1;
		int sum = a[0];
		for (int i = 0; i < n; i++) {
			if (a[i] <= sum + (2 * mid)) {
				
			}
			else {
				sum = a[i];
				k++;
			}
		}

		if (k <= m) {
			hi = mid - 1;
			ret = min(ret, mid);
		}
		else
		{
			lo = mid + 1;
		}
	}
	cout << ret;
	return 0;
}