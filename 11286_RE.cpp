#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("11286_input.txt", "r", stdin);
	cin >> n;
	priority_queue<int> plus_q;
	priority_queue<int> mir_q;

	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		if (num < 0) {
			mir_q.push(num);
		}
		if (num > 0) {
			plus_q.push(num*(-1));
		}
		if (num == 0) {
			if (mir_q.size() && plus_q.size()) {
				if (mir_q.top() >= plus_q.top()) {
					cout << mir_q.top() << '\n';
					mir_q.pop();
				}
				else{
					cout << plus_q.top()*(-1) << '\n';
					plus_q.pop();
				}				
			}
			else if (mir_q.size()) {
				cout << mir_q.top()<< '\n';
				mir_q.pop();
			}
			else if (plus_q.size()) {
				cout << plus_q.top() * (-1) << '\n';
				plus_q.pop();
			}
			else
				cout <<"0\n";
		}
	}
	return 0;
}