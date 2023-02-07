#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
vector<pair<int, int>>v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("11t_2.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x = 0; int y = 0; 
		cin >> x >> y;
		v.push_back({ x,1 });
		v.push_back({ y,-1 });
	}
	sort(v.begin(), v.end());

	int ret = 0;
	int total = 0;
	for (int i = 0; i < v.size(); i++) {
		total += v[i].second;

		if (total == 0)
			ret++;
		cout << total << endl;
	}
	return 0;
}