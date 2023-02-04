#include<iostream>
#include<queue>
using namespace std;
priority_queue<int> pq;
int a[100001];
int n, m;
int main() {
	ios_base::sync_with_stdio;
	cout.tie(NULL); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x = 0; cin >> x;
		a[i] = x;
	}
	double sum = a[n - 1];
	double ret = 0;
	pq.push(-a[n - 1]);
	for (int i = n - 2; i >= 2; --i) {
		pq.push(-a[i]);
		sum += a[i];
		int min_num = pq.top();
		sum += min_num;
		double ave = sum / (pq.size() - 1);
		ret = max(ret, ave);
		sum -= min_num;
	}
	printf("%.2f", ret);
	return 0;
}