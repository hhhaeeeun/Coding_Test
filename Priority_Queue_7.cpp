#include<iostream>
#include<queue>
using namespace std;
int t, n, m;
int main() {
	ios_base::sync_with_stdio;
	cout.tie(NULL); cin.tie(NULL);
	cin >> t;
	int mid = 0;
	for (int i = 0; i < t; i++) {
		priority_queue<int> big;
		priority_queue<int> small;
		cin >> n;
		cin >> mid;
		cout << mid << ' ';
		for (int i = 1; i < n; i++) {
			int x = 0; cin >> x;
			if (mid <= x) {
				big.push(-x);
				if (big.size() == small.size() + 2) {
					int r = -big.top(); big.pop();
					small.push(mid);
					mid = r;
				}
			}
			if (mid > x) {
				small.push(x);
				if (small.size() == big.size() + 2) {
					int r = small.top(); small.pop();
					big.push(-mid);
					mid = r;
				}
			}
			if (i % 2 == 0) cout << mid << ' ';
		}
		cout << '\n';
	}
	return 0;
}