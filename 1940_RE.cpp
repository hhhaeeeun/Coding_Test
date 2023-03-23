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
	cin >> n>>m;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int s_idx = 0;
	int e_idx = n - 1;
	int ret = 0;
	while (s_idx < e_idx) {
		int sum = v[s_idx] + v[e_idx];

		if (sum == m) {
			ret++;
			s_idx++;
		}
		else if (sum > m) {
			e_idx--;
		}
		else if (sum < m) {
			s_idx++;
		}
	}
	cout << ret;
	return 0;
}