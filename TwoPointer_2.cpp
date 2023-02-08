#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[100001];
int counting_arr[100001];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int j = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		while (j + 1 <= n && counting_arr[a[j + 1]] != 1) {
			++counting_arr[a[j]];
			j++;
		}
		ans = max(ans, j - i + 1);
		counting_arr[a[i]]--;
	}
	cout << ans << endl;
	return 0;
}