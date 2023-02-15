#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<set>
#include<climits>
using namespace std;
int n, k;
int a[50001];
int L[50001];
int R[50001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("tp8.txt", "r", stdin);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int sum = 0;
	int j = 0;
	L[0] = 1;
	for (int i = 1; i < n; i++) {
		sum += a[i] - a[i - 1];
		while(sum > k) {
			sum -= a[j + 1] - a[j];
			j++;
		}
		L[i] = max(L[i-1], i - j +1);
	}
	R[n - 1] = 1;
	sum = 0;
	j = n - 1;
	for (int i = n-2; i >= 0; --i) {
		sum += a[i + 1] - a[i];
		while (sum > k) {
			sum -= a[j] - a[j - 1];
			--j;
		}
		R[i] = max(R[i+1], j - i + 1);
	}
	int ans = 0;

	for (int i = 0; i <n-1; ++i) {
		ans = max(ans, L[i] + R[i + 1]);
	}
	cout << ans;
	return 0;
}