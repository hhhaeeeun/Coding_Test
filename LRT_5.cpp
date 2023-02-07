#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
vector<pair<int, int>>point;
int R[100001];
int L[100001];
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("LRT_5.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int y = 0; int x = 0; cin >> y >> x;
		point.push_back({ y,x });
	}
	sort(point.begin(), point.end());
	R[n] = INT_MAX;
	for (int i = n - 1; i >= 0; --i) {
		R[i] = min(point[i].second, R[i + 1]);
	}
	L[0] = point[0].second;
	for (int i = 1; i < n; i++) {
		L[i] = max(point[i].second, L[i - 1]);
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (point[i].second > R[i]) continue;
		if (point[i].second < L[i]) continue;
		++ret;
	}
	cout << ret << '\n';
	return 0;
}