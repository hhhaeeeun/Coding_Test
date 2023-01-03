#include<bits/stdc++.h>
using namespace std;
int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string resultV = "";
	stack<int> s;
	bool fail = false;
	int number = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int now = 0;
		cin >> now;
		if (now >= number)
		{
			while (now >= number) {
				s.push(number++);
				resultV += '+';
			}
			s.pop();
			resultV += '-';
		}
		else
		{
			int last = s.top();
			s.pop();
			if (last > now)
			{
				cout << "NO" << '\n';
				fail = true;
				break;
			}
			else
			{
				resultV += '-';
			}
		}
	}

	if (fail == false)
	{
		for(int i = 0; i<resultV.size();i++)
		cout << resultV[i] << '\n';
	}

	return 0;
}
