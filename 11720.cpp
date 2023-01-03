#include<bits/stdc++.h>
using namespace std;

int main()
{
	string number;
	int n;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> number;

	int result = 0;
	for (int i = 0; i < n; i++)
	{
		result += number[i] - '0';
	}

	cout << result << "\n";
	return 0;
}
