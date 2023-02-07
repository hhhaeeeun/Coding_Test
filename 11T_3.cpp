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
	freopen("11t_2.txt", "r", stdin);
	cin >> n >> k;
	int now = 0;
	for (int i = 0; i < n; i++) {
		int x = 0; string y = "";
		cin >> x >> y;
		if (y == "R") {
			v.push_back({ now,1 });
			v.push_back({ now + x,-1 });
			now += x;
		}
		else {
			v.push_back({ now,-1 });
			v.push_back({ now - x,1 });
			now -= x;
		}
	}
	sort(v.begin(), v.end());
	queue<int> q;
	int ret = 0;
	int total = 0;
	for (int i = 0; i < v.size(); i++) {
		total += v[i].second;
		if (total >= k) {
			if (q.size() == 0) {
				q.push(v[i].first);
			}
		}
		else {
			if (q.size()) {
				ret += v[i].first - q.front(); q.pop();
			}
		}
	}
	cout << ret;
	return 0;
}