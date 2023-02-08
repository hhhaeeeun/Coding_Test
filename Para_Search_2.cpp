#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
int a[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("ps1.txt", "r", stdin);
	cin >> n >> m;
	int total_sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		total_sum += a[i];
	}
	int right = total_sum/m;
	int left = 0;

	while (left <= right) {
		int mid = (right + left) / 2;
		if (mid == 0)
			break;
		int ret = 0;
		for (int i = 0; i < n; i++) {
			ret += a[i] / mid;
		}
		if (ret >= m) {
			left = mid + 1;
			//여기서 정답을 저장해도 됨
		}
		if (ret < m) {
			right = mid - 1;
		}
	}
	cout << right;
	return 0;
}