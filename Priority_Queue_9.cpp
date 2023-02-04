#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
priority_queue<pair<int, int>> pq;
int n, m;
int main() {
	ios_base::sync_with_stdio;
	cout.tie(NULL); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x = 0; cin >> x;
		if (x == 0) {
			int y = 0;
			if (pq.size()) {
				tie(ignore, y) = pq.top();
				cout << -y << endl;
				pq.pop();
			}
			else
				cout << "0\n";
		}
		else {
			pq.push({ -abs(x), -x });
		}
	}
	return 0;
}