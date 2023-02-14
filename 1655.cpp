#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>

using namespace std;
int n;
int a[100001];
priority_queue<int> min_heap;
priority_queue<int> max_heap;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		int x = a[i];
		if ((i + 1) % 2 == 1) {
			int y = INT_MIN;
			if (max_heap.size())
				y = max_heap.top();
			if (x < y) {
				max_heap.pop();
				min_heap.push(-y);
				max_heap.push(x);
			}
			else {
				min_heap.push(-x);
			}
			cout << min_heap.top() * (-1) << '\n';
		}
		else {
			int y = INT_MAX;
			if (min_heap.size())
				y = min_heap.top() * (-1);
			if (y < x) {
				min_heap.pop();
				max_heap.push(y);
				min_heap.push(-x);
			}
			else {
				max_heap.push(x);
			}
			cout << max_heap.top() << '\n';
		}
	}
	return 0;
}