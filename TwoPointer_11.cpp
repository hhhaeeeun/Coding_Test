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
int n, k;
unordered_map<int, int> m;
bool is_possible(int index) {
	if (index >= n)
		return false;
	if (m[a[index]] >= k) {
		return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ret = 0;
	int i = 0;
	for (int j = 0; j < n; j++) {
		while (is_possible(i)) {
			++m[a[i]];
			++i;
		}
		ret = max(ret, i - j);
		--m[a[j]];
	}
	cout << ret;
	return 0;
}