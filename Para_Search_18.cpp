#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
int n, m;
int a[100001];
bool is_possible(int mid) {

	int k = 1;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum + a[i] > mid) {
			k++;
			sum = a[i];
		}
		else {
			sum += a[i];
		}
	}
	if (k > m)return false;
	return true;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("ps18.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int lo = 1;
	int hi = 100001;
	int ret = INT_MAX;
	while (lo <= hi) {

		int mid = (lo + hi) / 2;
		if (is_possible(mid)) {
			hi = mid - 1;
			ret = min(ret, mid);
		}
		else {
			lo = mid + 1;
		}
	}
	cout << ret;
	return 0;
}