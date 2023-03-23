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

	int s_ind = 1;
	int e_ind = 1;
	int ret = 1;
	int sum = 1;

	while (e_ind != n) {
		if (sum < n) {
			sum += ++e_ind;
		}
		if (sum == n) {
			ret++;
			sum -= s_ind++;
		}
		if (sum > n) {
			sum -= s_ind++;
		}
	}
	cout << ret;


	return 0;
}