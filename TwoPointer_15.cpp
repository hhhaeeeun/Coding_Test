#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
int n, k;
int a[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("tp15.txt", "r", stdin);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int j = 0;
	int num = 0;
	int ret = INT_MAX;
	for (int i = 0; i < n; i++) {
		while (num < k && j < n) {
			if (a[j] == 1) num++;
			j++;
		}
		if(num >= k)
			ret = min(ret, j - i);
		if (a[i] == 1) num--;
	}
	if (ret == INT_MAX) {
		cout << "-1\n";
	}
	else
		cout << ret;

	return 0;
}