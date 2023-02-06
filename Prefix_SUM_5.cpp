#include<iostream>
using namespace std;
int n, q;
int a[1000001];
int sum[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> n >> q;
	int ret = 0;
	int max_num = 0;
	for (int i = 0; i < n; i++) {
		int x = 0; cin >> x;
		++a[x];
		max_num = max(x, max_num);
	}
	for (int i = 1; i <= max_num; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 0; i < q; i++) {
		int x = 0; cin >> x; int y = 0; cin >> y;
		if (x > max_num) {
			cout << "0\n";
			continue;
		}
		y = min(y, max_num);
		cout << sum[y] - sum[x - 1] << '\n';
	}
	return 0;
}