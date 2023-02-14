#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
int T, k;
typedef struct ABC {
	long long value;
	bool dead;
	ABC() {
		value = 0;
		dead = false;
	}
	ABC(long long a) {
		value = a;
		dead = false;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("7662.txt", "r", stdin);
	cin >> T;
	for (int i = 0; i < T; i++) {
		int index = 0;
		int num = 0;
		vector<ABC> v;
		priority_queue<pair<long long, int>> minq;
		priority_queue<pair<long long, int>> maxq;
		cin >> k;
		for (int j = 0; j < k; j++) {
			string s = ""; long long x = 0;
			cin >> s >> x;
			if (s == "D" && x == -1) {
				if (num == 0)continue;
				int ind = 0;
				tie(ignore, ind) = minq.top(); minq.pop();
				while (v[ind].dead == true) {
					tie(ignore, ind) = minq.top(); minq.pop();
				}
				v[ind].dead = true;
				--num;
			}
			if (s == "D" && x == 1) {
				if (num == 0)continue;
				int ind = 0;
				tie(ignore, ind) = maxq.top(); maxq.pop();
				while (v[ind].dead == true) {
					tie(ignore, ind) = maxq.top(); maxq.pop();
				}
				v[ind].dead = true;
				--num;
			}
			if (s == "I"){
				v.push_back(ABC(x));
				minq.push({ -x, index });
				maxq.push({ x, index });
				++index;
				++num;
			}
		}
		if (num == 0) {
			cout << "EMPTY" << '\n';
			continue;
		}
		if (maxq.size()) {
			int ind = 0;
			tie(ignore, ind) = maxq.top(); maxq.pop();
			while (v[ind].dead == true) {
				tie(ignore, ind) = maxq.top(); maxq.pop();
			}
			cout << v[ind].value << ' ';
		}
		if (minq.size()) {
			int ind = 0;
			tie(ignore, ind) = minq.top(); minq.pop();
			while (v[ind].dead == true) {
				tie(ignore, ind) = minq.top(); minq.pop();
			}
			cout << v[ind].value << '\n';
		}
	}
	return 0;
}