#include<bits/stdc++.h>
using namespace std;
int n , m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n = 0;
	cin >> n;

	int s_point = 0;
	int e_point = 0;
	int sum = 0;
	int count = 0;
	while (e_point != n) {
		if (sum < n)
		{
			sum += ++e_point;
		}
		else if (sum > n)
		{
			sum -= s_point++;
		}
		else if (sum == n)
		{
			count++;
			sum += ++e_point;
		}
	}

	cout << count+1 << '\n';
	return 0;
}
