#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
int n, m;
priority_queue<tuple<int, int, int>>pq;
int main() {
	ios_base::sync_with_stdio;
	cout.tie(NULL); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x = 0;  int y = 0; cin >> x >> y;
		pq.push(make_tuple(-(x + y), -x, -y));
	}
	for (int i = 0; i < m; i++) {
		int x = 0; int y = 0;
		tie(ignore, x, y) = pq.top();
		x -= 2;
		y -= 2;
		pq.pop();
		pq.push(make_tuple(x + y, x, y));
	}
	int x = 0; int y = 0;
	tie(ignore, x, y) = pq.top();
	cout << -x << ' ' << -y << '\n';

	return 0;
}