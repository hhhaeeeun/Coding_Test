#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> A;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	A.resize(n);
	int max = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
		if (A[i] > max)
			max = A[i];
		sum += A[i];
	}

	int start_index = max;
	int end_index = sum;
	while (start_index <= end_index)
	{
		int mid = (start_index + end_index) / 2;
		int count = 0;
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (sum + A[i] > mid)
			{
				count++;
				sum = 0;
			}
			sum += A[i];
		}

		if (sum)
			count++;
		if (count > m)
		{
			start_index = mid + 1;
		}
		else
			end_index = mid - 1;

	}
	cout << start_index<<"\n";
	return 0;
}