#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include<vector>
#include<tuple>
using namespace std;
int n, m;
int a[100001];
int main() {
	freopen("tp6.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int j = n - 1;
	int total_sum = 0;
	int ans = INT_MAX;
	for (int i = 0; i < n-1; i++) {
		ans = min(abs(a[j] + a[i]), ans);
		while (j > i+1 && a[i] + a[j] > 0) {
			j--;
			ans = min(abs(a[j] + a[i]), ans);
		}
	}
	cout << ans;
	return 0;
}