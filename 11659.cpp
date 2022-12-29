#include<bits/stdc++.h>
using namespace std;

int m, n, l, k;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int sum[100001] = { 0, };

	cin >> m;
	cin >> n;
	for (int i = 1; i < m + 1; i++)
	{
		int tmp;
		cin >> tmp;
		sum[i] = sum[i - 1] + tmp;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> l;
		cin >> k;
		cout << sum[k] - sum[l - 1] << "\n";
	}
	return 0;
}