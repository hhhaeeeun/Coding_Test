#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
#include<tuple>
using namespace std;
int n, m;
vector<pair<int, int>> v[100001];
int dir[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i <m; i++) {
		int a = 0; int b = 0; int w = 0;
		cin >> a >> b >> w;
		v[b].push_back({ a,w });
	}
	for (int i = 0; i < n; i++) {
		dir[i] = (int)1e9;
	}
	priority_queue<pair<int, int>>q;
	q.push({ 0, n });
	dir[n] = 0;
	while (q.size()) {
		int min_index = 0; int w = 0; 
		tie(w, min_index) = q.top(); q.pop();
		if (dir[min_index] != -w)continue;
		for (auto i : v[min_index]) {
			if (dir[i.first] > dir[min_index] + i.second) {
				dir[i.first] = dir[min_index] + i.second;
				q.push({ -dir[i.first], i.first });
			}
		}
	}
	int ret = INT_MIN;
	for (int i = 1; i < n; i++) {
		ret = max(ret, dir[i]);
	}
	return 0;
}