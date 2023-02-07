#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
int n, q;
int a[100002];
int L[100002];
int R[100002];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("LRT_7.txt", "r", stdin);
	cin >> n>>q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		L[i] = max(L[i - 1], a[i]);
	}
	for (int i = n; i >= 1; --i) {
		R[i] = max(R[i + 1], a[i]);
	}
	for (int i = 0; i < q; i++) {
		int x = 0; int y = 0;
		cin >> x >> y;
		cout << max(L[x - 1], R[y + 1]) << endl;
	}
	return 0;
}