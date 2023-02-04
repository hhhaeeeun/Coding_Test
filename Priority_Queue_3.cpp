#include<iostream>
#include<queue>
using namespace std;
priority_queue<int> pq;
int n, m;
int main() {
	ios_base::sync_with_stdio;
	cout.tie(NULL); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x = 0; cin >> x;
		if (x == 0) {
			if (pq.empty()) {
				cout << 0 << '\n';
			}
			else
			{
				x = pq.top();
				cout << -x << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(-x);
		}
	}

	return 0;
}