#include<bits/stdc++.h>
using namespace std;
int n, b, c;
int A[10000001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	cin >> b >> c;

	long long ret = 0;
	for (int i = 0; i < n; i++)
	{
		ret++;
		if (A[i] <= b) continue;
		if ((A[i] - b) < c)	{
			ret++;
			continue;
		}
		else
		{
			int temp = (A[i] - b) / c;
			if ((A[i] - b) % c)
				ret++;
			ret += temp;			
		}
	}
	cout << ret << "\n";
	return 0;
}