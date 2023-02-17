#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
string A;
string B;
int n;
int a[200001];
bool skip[200001];
bool is_possible(int mid) {

	for (int i = 0; i < mid - 1; i++) {
		skip[a[i] - 1] = true;
	}

	int j = 0;
	for (int i = 0; i < A.size(); i++) {
		if (skip[i] == true)continue;
		if (B[j] == A[i] && j < B.size())
			j++;
	}

	for (int i = 0; i < mid; i++) {
		skip[a[i] - 1] = false;
	}

	if (j == B.size())
		return true;
	return false;


}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("ps15.txt", "r", stdin);
	
	cin >> A >> B;
	for (int i = 0; i < A.size(); i++) {
		cin >> a[i];
	}

	int lo = 0;
	int hi = A.size();
	int ret = 0;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (is_possible(mid)) {
			lo = mid + 1;
			ret = max(ret, mid);
		}
		else {
			hi = mid - 1;
		}
	}
	cout << ret;
	return 0;
}