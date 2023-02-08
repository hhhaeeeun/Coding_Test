#include<iostream>
using namespace std;
int n, m;
int a[100001];
int find(int target) {
	int left = 0; int right = n;
	while (left<=right) {
		int mid = (left + right) / 2;
		if (a[mid] == target) {
			return mid + 1;
		}
		if (a[mid] > target)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n>>m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		int target = 0;
		cin >> target;
		cout << find(target) << endl;
	}
	return 0;
}