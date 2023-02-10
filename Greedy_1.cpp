#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
int n, m;
double ans;
vector<tuple<double, int, int>> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("g1.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int w = 0; int val = 0;
		cin >> w >> val;
		v.push_back(make_tuple(-(double)val / (double)w, w, val));
	}
	sort(v.begin(), v.end());
	for(int i =0; i<v.size();i++){
		double value = 0;
		int w = 0; int val = 0;
		tie(value, w, val) = v[i];
		if (m < w) {
			ans +=(double)m * value * (-1);
			break;
		}
		else {
			ans += val;
			m -= w;
		}
	}

	cout << fixed;
	cout.precision(3);
	cout << ans;

	return 0;
}