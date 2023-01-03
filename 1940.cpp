#include<bits/stdc++.h>
using namespace std;

int num[15001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n=0;
	cin >> n;


	for (int i = 0; i < n; i++)
		cin >> num[i];

	int i = 0;
	int j = n-1;
	int count = 0;
	sort(num, num + n);
	while (i != j)
	{
		int sum = 0;
		sum = num[i] + num[j];
		if (sum == m)
		{
			count++;
			i++;
		}
		else if (sum > m)
		{
			j--;
		}
		else if (sum < m)
		{
			i++;
		}
	}
	cout << count << endl;

	return 0;
}
