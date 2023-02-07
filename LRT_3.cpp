#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
int n;
int a[100002];
int L[100002];
int R[100002];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("LRT_3.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		L[i] = max(L[i - 1], a[i]);
	}
	for (int i = n; i >= 1; --i) {
		cin >> a[i];
		R[i] = max(R[i + 1], a[i]);
	}
	int ret = INT_MIN;
	for (int i = 3; i <= n-2; ++i) {
		int tem = L[i - 2] + R[i + 2] + a[i];
		ret = max(ret, tem);
	}
	cout << ret << '\n';
	return 0;
}