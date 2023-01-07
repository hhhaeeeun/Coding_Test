#include<bits/stdc++.h>
using namespace std;
int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	int count = 0;
	int number = 666;
	while (1)
	{
		if (string::npos != to_string(number).find("666"))
		{
			count++;
			if (count == n)
				break;
		}
		number++;
	}
	
	cout << number << "\n";
	return 0;
}