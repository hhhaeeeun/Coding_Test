#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
char a[100001];
int sum[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s = "";
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		a[i + 1] = s[i];
	}
	
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[i - 1] && a[i] == '(') {
			sum[i] = 1;
		}
		sum[i] += sum[i - 1];
	}
	int ret = 0;
	for (int i = n; i > 0; --i) {
		if (a[i] == a[i - 1] && a[i] == ')') {
			ret += sum[i];
		}
	}
	cout << ret;
	return 0;
}
