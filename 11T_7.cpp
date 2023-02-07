#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<set>
#include<climits>
#include<unordered_set>
using namespace std;
int n;
int weight[100001];
vector<tuple<int, int, int>> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("11T_7.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int y = 0; int x = 0; cin >> y >> x;
		v.push_back({ y, 1, i });
		v.push_back({ x, -1,i });
	}
	sort(v.begin(), v.end());
	int prev_x = get<0>(v[0]); 
	int tot_length = 0;
	int sum = 0;
	unordered_set<int> s;
	for (int i = 0; i < v.size(); i++) {
		int x = 0; int r = 0; int index = 0;
		tie(x, r, index) = v[i];
		if (tot_length == 1) {
			weight[*s.begin()] += x - prev_x;
		}
		if (tot_length != 0)
			sum += (x - prev_x);
		tot_length += r;
		if (r == 1) s.insert(index);
		if (r == -1)s.erase(index);
		prev_x = x;
	}
	int ret = INT_MAX;
	for (int i = 1; i <= n; i++) {
		ret = min(weight[i], ret);
	}

	cout << prev_x - ret;
	return 0;
}
