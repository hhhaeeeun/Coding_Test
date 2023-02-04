#include<iostream>
#include<queue>
#include<algorithm>
#include<tuple>
#include<cmath>
using namespace std;
int pq1[100001];
int pq2[100001];
int n, m, k;
priority_queue<tuple<int, int, int>> pq;
int main() {
	ios_base::sync_with_stdio;
	cout.tie(NULL); cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> pq1[i];
	}
	sort(pq1, pq1 + n);
	for (int i = 0; i < m; i++) {
		cin >> pq2[i];
	}
	sort(pq2, pq2 + m);
	for (int i = 0; i < n; i++) {
		pq.push(make_tuple(-pq1[i] - pq2[0], i, 0));
	}
	for (int i = 0; i < k - 1; i++) {
		int x = 0; int y = 0;
		tie(ignore, x, y) = pq.top(); pq.pop();
		++y;
		if (y < m) {
			pq.push(make_tuple(-pq1[x] - pq2[y], x, y));
		}
	}
	int sum = 0;
	tie(sum, ignore, ignore) = pq.top();
	cout << -sum << endl;
	return 0;
}
/*
모든 쌍의 수는 최대 10만 * 10만 = 100억이 됩니다.

이때, c++을 기준으로 int로 2천만을 잡았을 때 
80MB정도 소요된다는 사실을 기억하고 계시면 좋습니다. 
그렇다면 대략 100억의 경우 2천만의 500배 이므로 
40000MB가 되어 메모리 초과가 발생할 것이라는 것을 미리 알 수 있습니다 :)
*/