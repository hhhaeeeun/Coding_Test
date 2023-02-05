#include<iostream>
#include<queue>
using namespace std;
priority_queue<int> pq;
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> n;
	int m1 = 0; int m2 = 0;
	for (int i = 0; i < n; i++) {
		int x = 0; cin >> x;

		if (i == 0) {
			cout << "-1\n";
			m1 = x;
			continue;
		}
		if (i == 1) {
			cout << "-1\n";
			m2 = m1;
			m1 = min(m1, x);
			m2 = max(m2, x);
			continue;
		}
		if (x <= m1) {
			pq.push(-m2);
			m2 = m1;
			m1 = x;
		}
		else if (x <= m2) {
			pq.push(-m2);
			m2 = x;
		}
		else {
			pq.push(-x);
		}
		cout << (long long)m1 * m2 * pq.top() * -1 << endl;
	}
	return 0;
}