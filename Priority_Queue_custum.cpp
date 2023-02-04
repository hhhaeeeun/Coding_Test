#include<iostream>
#include<queue>
using namespace std;
int n, m;
struct compare {
	bool operator()(int a, int b) {
		return a > b;
	}
};
int main() {
	priority_queue<int, vector<int>, compare> pq;
	for (int i = 10; i > 0; --i) {
		pq.push(i);
	}
	while (pq.size()) {
		cout << pq.top() << endl;
		pq.pop();
	}
	return 0;
}