#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> d;

bool binary_find(int v)
{
	int mid = 0;
	int start = 0;
	int end = n - 1;
	while (start <= end)
	{
		mid = start + ((end - start) / 2);
		if (d[mid] > v)
			end = mid - 1;
		else if (d[mid] < v)
			start = mid + 1;
		else
			return true;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	d.resize(n,0);
	for (int i = 0; i < n; i++)
	{
		cin >> d[i];
	}
	sort(d.begin(), d.end());

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int now = 0;
		cin >> now;

		bool result = binary_find(now);
		cout << result << "\n";
	}

	return 0;
}