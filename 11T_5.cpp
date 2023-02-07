#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<tuple>
#include<vector>
#include<queue>
using namespace std;
int n;
int a[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("11T_5.txt", "r", stdin);
	vector<tuple<int, int, int>>v;
	cin >> n;
	priority_queue<int> q;
	for (int i = 0; i < n; i++) {
		int x = 0; int y = 0;
		cin >> x >> y;
		v.push_back({ x,1, i });
		v.push_back({ y,-1, i });
		q.push(-(i + 1));
	}
	sort(v.begin(), v.end());
	int ret = 0;
	int total = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (get<1>(v[i]) == 1) {
			a[get<2>(v[i])] = -q.top();
			q.pop();
		}
		else {
			q.push(-a[get<2>(v[i])]);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	return 0;
}
