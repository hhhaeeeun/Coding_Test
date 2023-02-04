#include<iostream>
#include<queue>
using namespace std;
priority_queue<int> pq;
int n,m;
int main() {
	ios_base::sync_with_stdio;
	cout.tie(NULL); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x = 0; cin >> x;
		pq.push(x);
	}
	for (int i = 0; i < m; i++) {
		int x = pq.top();
		pq.pop();
		pq.push(x - 1);
	}
	return 0;
}