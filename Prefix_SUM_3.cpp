#include<iostream>
using namespace std;
int n, k;
int a[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> n >> k;
	int sum = 0;
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] - a[j] == k) {
				++ret;
			}
		}
	}
	cout << ret;
	return 0;
}