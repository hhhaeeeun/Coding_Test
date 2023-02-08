#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int a[100001];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int j = 0;
	int ans = 0;
	int total_sum = 0;
	for (int i = 1; i <= n; i++) {
		while (j + 1 <= n && total_sum + a[j + 1] <= m) {
			j++;
			total_sum += a[j];
		}
		if (total_sum == m) {
			++ans;
		}
		total_sum -= a[i];
	}
	cout << ans << endl;
	return 0;
}