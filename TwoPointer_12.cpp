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
int a[100001];
int n, m;
unordered_map<int, int> out;
unordered_set<int> out_n;
unordered_map<int, int> now;
unordered_set<int> now_n;
bool is_possible(int index) {
	if (index >= n)
		return false;
	now_n.insert(a[index]);
	if (now_n.size() == m) {
		return false;
	}

	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("tp12.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		++out[a[i]];
		out_n.insert(a[i]);
	}
	for (int j = 1; j <= m; j++) {
		if (out[j] < 2) {
			cout << "-1\n";
			return 0;
		}
	}

	int ret = INT_MAX;
	int i = 0;
	for (int j = 0; j < n; j++) {
		while (now_n.size() < m && i < n) {
			now_n.insert(a[i]);
			++now[a[i]];
			--out[a[i]];
			if (out[a[i]] == 0)
				out_n.erase(a[i]);
			++i;
		}
		if (out_n.size() == m && now_n.size() == m) {
			ret = min(ret, i - j);
		}
		--now[a[j]];
		if (now[a[j]] == 0)
			now_n.erase(a[j]);
		out_n.insert(a[j]);
		++out[a[j]];
	}
	if (ret == INT_MAX)
		cout << "-1\n";
	else
		cout << ret;
	return 0;
}