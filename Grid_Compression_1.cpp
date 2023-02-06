#include<iostream>
#include<set>
#include<unordered_map>
#include<climits>
using namespace std;
int n, q;
int a[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> n >> q;
	set<int>s;
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++) {
		int x = 0; cin >> x;
		s.insert(x);
	}
	int cnt = 1;
	for (auto i : s) {
		m[i] = cnt;
		cnt++;
	}
	for (int i = 0; i < q; i++) {
		int x = 0; int y = 0; cin >> x >> y;
		cout << m[y] - m[x] + 1 << '\n';
	}
	return 0;
}