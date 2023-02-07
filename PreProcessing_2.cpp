#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
int n, k;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	unordered_map<int, int>m;
	cin >> n >> k;
	int ret = -1;
	for (int i = 0; i < n; i++) {
		int x = 0;
		cin >> x;
		if (m.find(x) == m.end()) {
			m[x] = i;
		}
		else {
			if ((i - m[x] )<= k) {
				ret = max(ret, x);
			}
			else {
				m[x] = i;
			}
		}
	}
	cout << ret;
	return 0;
}
