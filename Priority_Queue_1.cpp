#include<iostream>
#include<queue>
using namespace std;
priority_queue<int> pq;
int n;
int main() {
	ios_base::sync_with_stdio;
	cout.tie(NULL); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s = "";
		cin >> s;
		if (s == "push") {
			int x = 0; cin >> x;
			pq.push(x);
		}
		if (s == "pop") {
			int x = 0;
			x = pq.top();
			cout << x << '\n';
			pq.pop();
		}
		if (s == "size") {
			cout << pq.size() << '\n';
		}
		if (s == "empty") {
			if (pq.empty()) {
				cout << "1\n";
			}
			else
				cout << "0\n";
		}
		if (s == "top") {
			cout << pq.top() << '\n';
		}
	}
	return 0;
}