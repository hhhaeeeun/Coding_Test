#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
int n, m;
int a[100001];
int b[100001]; 
int L[100001];
int R[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("tp14.txt", "r", stdin);
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}

	int j = 1;
	for (int i = 1; i <= m; i++) {
		while (j <= n && a[j] != b[i]) j++;
		L[i] = j;
	}

	j = n;
	for (int i = m; i > 0; --i) {
		while (j > 0 && a[j] != b[i]) --j;
		R[i] = j;
	}

	int ret = 0;
	R[m + 1] = n + 1;
	for (int i = 1; i <= m; i++) {
		if (L[i-1] < R[i+1]) {
			ret++;
		}
	}
	


	cout << ret;
	return 0;
}