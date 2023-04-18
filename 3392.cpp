#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
#include<queue>
using namespace std;
struct point {
	int x, y1, y2, se;
};
struct compare {
	bool operator()(point &a, point &b) {
		return a.x > b.x;
	}
};
priority_queue<point, vector<point>, compare> q;
int tree[65536];
int N = 32768;
int n;

void range_push(int y1, int y2, int val) {

	for (int i = y1; i < y2; i++) {
		tree[i + N] += val;
	}
	y1 += N; y2 += N;
	y1 >>= 1; y2 >>= 1;
	//리프노드를 자식으로 갖는 트리는 무조건 합이 아님(2여도 1로 처리)
	for (int i = y1; i <= y2; i++) {
		bool a = tree[i << 1]; bool b = tree[i << 1 | 1];
		tree[i] = a + b;
	}

	while (y1 > 1) {
		y1 >>= 1; y2 >>= 1;
		for (int i = y1; i <= y2; i++) {
			tree[i] = tree[i << 1] + tree[i << 1 | 1];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input_3392.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		point s = { x1, y1, y2, 1 }; point e = { x2, y1, y2, -1 };
		q.push(s);
		q.push(e);
	}
	int dx = q.top().x;
	int ret = 0;
	while (q.size()) {
		point now = q.top(); q.pop();
		ret += (now.x-dx) * tree[1];
		range_push(now.y1, now.y2, now.se);
		dx = now.x;
	}
	cout << ret << '\n';
	return 0;
}