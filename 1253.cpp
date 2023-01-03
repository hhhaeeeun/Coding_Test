#include<bits/stdc++.h>
using namespace std;
int num[2001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num, num + n);

	int i = 0; int j = 0; int sum = 0; int count = 0;
	for (int k = 0; k < n; k++)
	{
		i = 0; j = n - 1;
		while (i < j)
		{
			sum = num[i] + num[j];
			if (sum == num[k])
			{
				if (i != k && j != k)
				{
					count++;
					break;
				}
				else if (i == k)
				{
					i++;
				}
				else if (j == k)
				{
					j--;
				}
			}
			else if (sum > num[k])
			{
				j--;
			}
			else if (sum < num[k])
			{
				i++;
			}
		}
	}

	cout << count << "\n";
	return 0;
}