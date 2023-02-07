#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
int n;
int a[100002];
int L[100002];
int R[100002];
int tL[100002];
int tR[100002];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("LRT_6.txt", "r", stdin);
	cin >> n;
	int max_sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		L[i] = L[i - 1] + a[i];
		max_sum += a[i];
	}
	if ((max_sum %= 4) != 0) {
		cout << "0\n";
		return 0;
	}
	int target = max_sum / 4;
	for (int i = 1; i <= n; i++) {
		L[i] = L[i - 1] + a[i];
		if (L[i] == target) {
			++tL[i];
		}
		tL[i] += tL[i - 1];
	}

	for (int i = n; i >= 1; --i) {
		R[i] =R[i + 1]+ a[i];
		if (R[i] == target) {
			++tR[i];
		}
		tR[i] += tR[i + 1];
	}

	int ret = 0;

	for (int i = 2; i <= n - 2; i++) {
		if (L[i] == R[i + 1] && L[i] == target * 2) {
			if (tR[i-1] && tL[i+2]) {
				ret += tL[i-1] * tR[i+2];
			}
		}
	}
	cout << ret;
	return 0;
}