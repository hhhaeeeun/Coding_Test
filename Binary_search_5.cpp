#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
long long n, m;
long long a;
long long b;
bool in_range(long long target) {
	if (target >= a && target <= b)
		return true;
	return false;
}
long long find(long long target) {
	long long left = 1; long long right = n;
	long long mid = (left + right) / 2;
	long long ret = 0;
	while (1) {
		mid = (left + right) / 2;
		if (mid == target) {
			ret++;
			return ret;
		}

		if (mid < target) {
			ret++;
			left = mid + 1;
		}
		else {
			ret++;
			right = mid - 1;
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	cin >> a >> b;

	long long min_r = LLONG_MAX;
	long long max_r = LLONG_MIN;
	long long left = 1; long long right = n;
	long long mid = 0;

	long long ret = 0;
	while (1) {
		mid = (left + right) / 2;
		if (in_range(mid)) {
			ret++;
			min_r = ret;
			break;
		}
		else {
			if (mid < a) {
				ret++;
				left = mid + 1;
			}
			else if (mid > b) {
				ret++;
				right = mid - 1;
			}
		}
	}
	if (in_range(mid - 1))
		max_r = max(max_r, find(mid - 1));
	else if (in_range(mid + 1))
		max_r = max(max_r, find(mid + 1));
	else
		max_r = min_r;
	cout << min_r << ' ' << max_r << '\n';
	return 0;
}
