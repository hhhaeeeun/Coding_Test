#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
#include<tuple>
#include<stack>
using namespace std;
int n, m, s, e;
vector<pair<int, int>> v[1001];
int dir[1001];
int path[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("d3.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a = 0; int b = 0; int w = 0;
		cin >> a >> b >> w;
		v[a].push_back({ b,w });
		v[b].push_back({ a,w });
	}
	cin >> s >> e;
	for (int i = 1; i <= n; i++) {
		dir[i] = (int)1e9;
	}
	dir[s] = 0;
	priority_queue<pair<int, int>>q;
	q.push({ 0,s });
	while (q.size()) {
		int min_index = 0; int w = 0; tie(w, min_index) = q.top(); q.pop();
		if (dir[min_index] != -w) continue;	
		for (auto i : v[min_index]) {
			if (dir[i.first] > dir[min_index] + i.second)
			{
				path[i.first] = min_index;
				dir[i.first] = dir[min_index] + i.second;
				q.push({ -dir[i.first], i.first });
			}
		}
	}
	stack<int> sta;
	int next = path[e];
	sta.push(e);
	while (next != s) {
		sta.push(next);
		next = path[next];
	}
	sta.push(s);
	while (sta.size()) {
		cout << sta.top() << ' ';
		sta.pop();
	}
	return 0;
}