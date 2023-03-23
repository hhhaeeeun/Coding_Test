#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<tuple>
#include<climits>
using namespace std;
int n, L;
vector<int> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> n >> L;
	deque<pair<int, int>> deq;
	int f = 0;
	cin >> f;
	deq.push_back({ f, 0 });
	cout << f << ' ';
	for (int i = 1; i < n; i++) {
		int num = 0;
		cin >> num;
		if (deq.front().second <= i - L) {
			deq.pop_front();
		}
		while(deq.size()&& deq.back().first>=num ){
			deq.pop_back();
		}
		deq.push_back({ num,i });
		cout << deq.front().first << ' ';
	}

	return 0;
}