#include<iostream>
using namespace std;
int n, q;
int a[3][100001];
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int x = 0; cin >> x;
		++a[x - 1][i];
	}
	for (int k = 0; k <3; k++) {
		for (int i = 1; i <= n; i++) {
			a[k][i] += a[k][i - 1];
		}
	}
	for (int i = 0; i < q; i++) {
		int x = 0; cin >> x;
		int y = 0; cin >> y;
		for (int k = 0; k < 3; k++) {
			cout << a[k][y] - a[k][x - 1] << ' ';
		}
		cout << '\n';
	}
	return 0;
}