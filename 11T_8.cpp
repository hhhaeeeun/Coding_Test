#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<unordered_set>
using namespace std;
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("11T_1.txt", "r", stdin);
	vector<tuple<int, int,int>>v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x = 0; int y = 0;
		cin >> x >> y;
		v.push_back(make_tuple(x, 1, i));
		v.push_back(make_tuple(y+1, -1, i));
	}
	sort(v.begin(), v.end());

	int ret = 0;
	int prev_x;
	unordered_set<int> s;
	for (int i = 0; i < 2 * n; i++) {
		if (get<1>(v[i]) == 1) {
			s.insert(get<2>(v[i]));
		}
		else if (get<1>(v[i]) == -1) {
			s.erase(get<2>(v[i]));
		}
		
		int r = s.size();
		ret = max(r, ret);
	}
	cout << ret;
	return 0;
}
