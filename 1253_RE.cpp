#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
int n;
vector<int> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int ret = 0;
	for (int i = 0; i < n; i++) {
		int s_idx = 0;
		int e_idx = n - 1;
		while (s_idx < e_idx) {
			int sum = v[s_idx] + v[e_idx];
			if (sum == v[i]) {

				if (s_idx != i && e_idx != i) {
					ret++;
					break;
				}
				else if (s_idx == i) {
					s_idx++;
				}
				else if (e_idx == i) {
					e_idx--;
				}
			}
			else if (sum < v[i]) {
				s_idx++;
			}
			else if (sum > v[i]) {
				e_idx--;
			}
		}
	}
	cout << ret;
	return 0;
}