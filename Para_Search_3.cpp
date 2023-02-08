#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<climits>
using namespace std;
int n;

int main() {
	cin >> n;
	long long left = 0;
	long long right = (n * 14) / 7;
	long long ans = LLONG_MAX;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long ret = mid;
		ret -= mid / 3;
		ret -= mid / 5;
		ret += mid / 15;

		if (ret >= n) {
			right = mid - 1;
			ans = min(mid, ans);
		}
		else if (ret < n) {
			left = mid + 1;
		}
	}
	cout << ans;
	return 0;
}