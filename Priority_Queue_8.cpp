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
��� ���� ���� �ִ� 10�� * 10�� = 100���� �˴ϴ�.

�̶�, c++�� �������� int�� 2õ���� ����� �� 
80MB���� �ҿ�ȴٴ� ����� ����ϰ� ��ø� �����ϴ�. 
�׷��ٸ� �뷫 100���� ��� 2õ���� 500�� �̹Ƿ� 
40000MB�� �Ǿ� �޸� �ʰ��� �߻��� ���̶�� ���� �̸� �� �� �ֽ��ϴ� :)
*/