#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<set>
#include<unordered_set>
using namespace std;
int n, k;
//int a[50001];
vector<tuple<int, int, int,int>>v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("11t_6.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int y = 0; int x1 = 0; int x2 = 0; cin >> y >>x1 >>x2;
		v.push_back({ x1, y, 1,i });
		v.push_back({ x2, y, -1,i });
	}
	sort(v.begin(), v.end());
	int ret;
	set<pair<int, int>>q;
	unordered_set<int> s;
	for (int i = 0; i < v.size(); i++) {
		if (get<2>(v[i]) == 1) {
			q.insert({ get<1>(v[i]), get<3>(v[i]) });
			s.insert(q.begin()->second);
		}
		else {
			q.erase({ get<1>(v[i]), get<3>(v[i]) });
			if(q.size())
				s.insert(q.begin()->second);
		}
	}
	cout << s.size();
	return 0;
}