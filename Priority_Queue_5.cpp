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
		pq.push(x);
	}

	while (pq.size() != 1) {
		int x = 0; int y = 0;
		x = pq.top(); pq.pop();
		y = pq.top(); pq.pop();

		if (x == y)continue;
		pq.push(abs(x - y));
	}

	if (pq.size()) {
		cout << pq.top();
	}
	cout << "-1\n";
	return 0;
}