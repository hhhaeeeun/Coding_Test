#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
int n;
int a[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (a[i - 1] == 0) {
			a[i - 1] = 1;
			a[i] ^= 1;
			a[i + 1] ^= 1;
			ans++;
		}
	}
	if (a[n - 1] == 0) {
		cout << -1;
	}
	else
		cout << ans;

	return 0;
}