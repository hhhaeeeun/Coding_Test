#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
#include<unordered_map>
using namespace std;
char a[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("tp9.txt", "r", stdin);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		a[i] = s[i];
	}

	int i = 0;
	int ret = 0;
	unordered_map<char, int> m;
	for (int j = 0; j < s.size(); j++) {
		while (i<s.size() && m[a[i]] == 0) {
			++m[a[i]];
			++i;
		}

		ret = max(ret, i - j);
		--m[a[j]];
	}

	cout << ret;
	return 0;
}