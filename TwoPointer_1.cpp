#include<iostream>
#include<climits>
using namespace std;
int n, s;
int a[100001];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int sum_val = 0;
	int j = 0;
	int ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		while (j + 1 <= n && sum_val < s) {
			sum_val += a[j + 1];
			j++;
		}
		if (sum_val < s)
			break;
		ans = min(ans, j - i + 1);
		sum_val -= a[i];
	}
	if (ans == INT_MAX)
		cout << "-1\n";
	else
		cout << ans;
	return 0;
}