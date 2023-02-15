#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
#include<unordered_map>
#include<unordered_set>
using namespace std;
char a[100001];
int k;
string s;
unordered_map<char, int> m;
unordered_set<char>se;
bool is_possible(int index) {
	if (index >= s.size())
		return false;
	se.insert(a[index]);
	if (se.size() > k) {
		se.erase(a[index]);
		return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("tp10.txt", "r", stdin);

	cin >> s >> k;
	for (int i = 0; i < s.size(); i++) {
		a[i] = s[i];
	}

	int ret = 0;
	int i = 0;
	for (int j = 0; j < s.size(); j++) {
		while(is_possible(i)) {
			++m[a[i]];
			++i;
		}
		ret = max(ret, i - j);
		--m[a[j]];
		if (m[a[j]] == 0) {
			se.erase(a[j]);
		}
	}
	cout << ret;
	return 0;
}