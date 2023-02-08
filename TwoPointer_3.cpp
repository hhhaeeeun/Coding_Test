#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int a[100001];
int b[100001];
int main() {
	cin >> n >>m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	int j = 1;
	for (int i = 0; i <= n; i++) {
		if (a[i] == b[j]) {
			j++;
		}
	}
	if (j > m)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}