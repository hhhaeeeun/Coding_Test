#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, k;
vector<pair<int, int>>v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("11t_4.txt", "r", stdin);
	cin >> n;
	int now = 0;
	for (int i = 0; i < n; i++) {
		int x = 0; int y = 0;
		cin >> x >> y;
		v.push_back({ x,1 });
		v.push_back({ y,-1 });
	}
	sort(v.begin(), v.end());
	queue<int> q;
	int ret = 0;
	int total = 0;
	for (int i = 0; i < v.size(); i++) {
		total += v[i].second;
		if (total >= 1) {
			if (q.size() == 0) {
				q.push(v[i].first);
			}
		}
		else {
			if (q.size()) {
				int sum = v[i].first - q.front(); q.pop();
				ret = max(ret, sum);
			}
		}
	}
	cout << ret;
	return 0;
}