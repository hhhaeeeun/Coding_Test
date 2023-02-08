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
	cin >> n >>m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < m; i++) {
		int target = 0;
		cin >> target;
		auto u = upper_bound(a, a + n, target);
		auto l = lower_bound(a, a + n, target);
		if (l == a + n || u == l) {
			cout << "0\n";
		}
		else {
			cout << *u - *l << '\n';
		}
	}
	return 0;
}
