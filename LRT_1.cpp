#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
int n;
vector<pair<int, int>>a;
vector<pair<int, int>>L;
vector<pair<int, int>>R;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("LRT_1.txt", "r", stdin);
	cin >> n;
	a = vector<pair<int, int>>(n+1, { 0,0 });
	L = vector<pair<int, int>>(n+1, { 0,0 });
	R = vector<pair<int, int>>(n+1, { 0,0 });

	for (int i = 0; i < n; i++) {
		int y = 0; int x = 0;
		cin >> y >> x;
		a[i] = { y,x };
	}
	for (int i = 1; i < n; i++) {
		L[i].first = L[i - 1].first + abs(a[i - 1].first - a[i].first);
		L[i].second = L[i - 1].second + abs(a[i - 1].second - a[i].second);
	}

	for (int i = n-2; i >0; --i) {
		R[i].first = R[i + 1].first + abs(a[i + 1].first - a[i].first);
		R[i].second = R[i + 1].second + abs(a[i + 1].second - a[i].second);
	}
	int ret = INT_MAX;
	for (int i = 1; i < n-1; ++i) {
		int tmp = L[i - 1].first + R[i + 1].first + L[i - 1].second + R[i + 1].second;
		tmp += abs(a[i - 1].first - a[i + 1].first);
		tmp += abs(a[i - 1].second - a[i + 1].second);
		ret = min(ret, tmp);
	}
	cout << ret;
	return 0;
}