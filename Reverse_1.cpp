#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("r1.txt", "r", stdin);
	cin >> n;
	string s = "";
	cin >> s;
	s = '0' + s;
	string e = "";
	cin >> e;
	e = '0' + e;
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		if (s[i] != e[i]) {
			if (s[i - 1]  == e[i - 1]) {
				++ans;
			}
		}
	}
	cout << ans;
	return 0;
	return 0;
}