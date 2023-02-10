#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
int n;
string a[50001];
bool cmp(string a, string b) {
	if (a + b > b + a) {
		return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++) {
		cout<<a[i];
	}
	return 0;
}