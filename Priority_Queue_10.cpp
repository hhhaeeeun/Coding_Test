#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<tuple>
#include<climits>
#include<algorithm>
using namespace std;
priority_queue<tuple<int, int, int>> pq;
int n;
int main() {
	ios_base::sync_with_stdio;
	cout.tie(NULL); cin.tie(NULL);
	freopen("pq10.txt", "r", stdin);
	cin >> n;
	vector<tuple<int, int, int>> people(n);
	for (int i = 0; i < n; i++) {
		int a = 0; int t = 0;
		cin >> a >> t;
		people[i] = make_tuple(a, i, t);
	}
	people.push_back(make_tuple(INT_MAX, INT_MAX, 0));
	sort(people.begin(), people.end());
	int ret = 0;
	int wait = 0;
	for (int k = 0; k <= n; k++) {
		int a = 0; int t = 0; int i = 0;
		tie(a, i, t) = people[k];
		while (1) {
			if (wait <= a && pq.empty()) {
				wait = a + t;
				break;
			}
			else if (wait > a) {
				pq.push(make_tuple(-i, a, t));
				break;
			}
			else {
				int a = 0; int t = 0; int i = 0;
				tie(i, a, t) = pq.top();
				ret = max(ret, wait - a);
				wait += t;
				pq.pop();
			}
		}
	}
	cout << ret;
	return 0;
}