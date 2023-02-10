#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
int n;
priority_queue<int> q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("g2.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x = 0;
		cin >> x;
		q.push(-x);
	}
	int sum = 0;
	while (q.size()) {
		int x = 0; int y = 0;
		x = q.top() * (-1); q.pop();
		if (q.empty()) {
			break;
		}
		y = q.top() * (-1); q.pop();

		q.push(-(x + y));
		sum += x + y;
	}
	cout << sum << endl;
	return 0;
}