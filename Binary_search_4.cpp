#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
int a[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < m; i++) {
		int x = 0; int y = 0;
		cin >> x >> y;
		auto start = lower_bound(a, a + n, x);
		auto end = upper_bound(a, a + n, y);
		if (start == end) {
			cout << "0\n";
		}
		else {
			cout << end - start << '\n';
		}

	}
	return 0;
}
