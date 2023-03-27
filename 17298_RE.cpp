#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<tuple>
#include<climits>
using namespace std;
int n;
vector<int> v;
vector<int>big;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
	big.resize(n, -1);
	stack<int> s;
	s.push(0);
	for (int i = 1; i < n; i++) {
		while (s.size() && v[s.top()] < v[i]) {
			big[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}
	for (int i = 0; i < n; i++) {
		cout << big[i] << ' ';
	}
	return 0;
}