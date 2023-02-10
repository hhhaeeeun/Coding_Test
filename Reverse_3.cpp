#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
int n;
int a[1001];
int b[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("r3.txt", "r", stdin);
	cin >> n;
	string s = "";
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'G')
			a[i] = 0;
		else
			a[i] = 1;
	}
	string e = "";
	cin >> e;
	for (int i = 0; i < n; i++) {
		if (e[i] == 'G')
			b[i] = 0;
		else
			b[i] = 1;
	}
	int ans = 0;
	int push = 0;
	for (int i = n; i >= 0; --i) {
		int now = a[i] ^ push;
		if (now != b[i]) {
			push ^= 1;
			ans++;
		}
	}
	cout << ans;
	return 0;
}