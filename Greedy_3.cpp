#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
int n;
vector<pair<int, int>> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("g3.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s = 0; int e = 0;
		cin >> s >> e;
		v.push_back({ e,s });
	}
	sort(v.begin(), v.end());
	int e = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if(v[i].second >= e ){
			++ans;
			e = v[i].first;
		}
	}
	cout << ans;
	return 0;
}