#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
int n;
double a[100001];
double v[100001];
vector<int> pos;
bool is_poss(double mid) {

	double l = 0;
	double r = 1e9;

	for (int i = 0; i < n; i++) {
		l = max(l, a[i] - v[i] * mid);
		r = min(r, a[i] + v[i] * mid);
	}

	if (l <= r)
		return true;
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pos.push_back(a[i]);
	}
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(pos.begin(), pos.end());
	double lo = 0;
	double hi = 1000000000;
	double ret = INT_MAX;
	for (int i = 1; i <= 100; i++)
	{
		double mid = (lo + hi) / 2;
		if (is_poss(mid)) {
			hi = mid;
			ret = min(ret, mid);
		}
		else {
			lo = mid;
		}
	}
	printf("%.4f", ret);
	return 0;
}