#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
int n;
char a[100002];
int csum[100002];
int wsum[100002];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("LRT_4.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = n; i > 0; --i) {
		if (a[i] == 'W') {
			++wsum[i];
		}
		wsum[i] += wsum[i + 1];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == 'C') {
			++csum[i];
		}
		csum[i] += csum[i - 1];
	}
	long long ret = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != 'O')continue;
		ret += csum[i - 1] * wsum[i + 1];
	}
	cout << ret << '\n';
	return 0;
}