#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
int n, m;
vector<int> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		int num = 0;
		cin >> num;
		auto k = lower_bound(v.begin(), v.end(), num);
		if (*k == num) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}
	}
	return 0;
}