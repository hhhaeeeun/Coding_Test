#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
int a[101][101];
int dir[101];
bool visited[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("fw1.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = (int)1e9;
		}
	}
	for (int i = 0; i < m; i++) {
		int s = 0; int e = 0; int w = 0;
		cin >> s >> e >> w;
		a[s][e] = min(a[s][e], w);
	}
	for (int i = 1; i <= n; i++) {
		a[i][i] = 0;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == (int)1e9)
				cout << -1 << " ";
			else
				cout << a[i][j] << " ";
		}
		cout << endl;
	}

	return 0;

	return 0;
}