#include<bits/stdc++.h>
using namespace std;

int m, n, l, k;

int main()
{

	int sum[10001] = { 0, };

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
		cout << sum[k] - sum[l - 1] << endl;
	}
	return 0;
}