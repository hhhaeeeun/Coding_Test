#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
int n, m;
int fire[100001];
int water[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("tp13.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> fire[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> water[i];
	}
	sort(fire, fire + n);
	sort(water, water + m);
	int j = 0;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		while (1) {
			int n1 = abs(fire[i] - water[j]);
			if (j == m-1) {
				ret = max(ret, abs(fire[i] - water[j]));
				break;
			}
			int n2 = 0;
			if(j < m-1)
				n2 = abs(fire[i] - water[j + 1]);
			if (n1 > n2) {
				j++;
			}
			else {
				ret = max(ret, abs(fire[i] - water[j]));
				break;
			}
		}
	}
	cout << ret;


	return 0;
}