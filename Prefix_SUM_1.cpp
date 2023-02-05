#include<iostream>
using namespace std;
int n, k;
int a[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> n >> k;
	int sum = 0;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		if (i == 0) continue;
		ret = max(ret, sum);
		if (i == 1)continue;
		sum -= a[i - 2];
	}
	return 0;
}