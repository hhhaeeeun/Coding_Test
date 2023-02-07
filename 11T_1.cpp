#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("11T_1.txt", "r", stdin);
	vector<pair<int, int>>v;
	
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
	for (int i = 0; i < 2 * n; i++) {
		total += v[i].second;
		ret = max(ret, total);
	}

	return 0;
}
