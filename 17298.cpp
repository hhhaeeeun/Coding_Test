#include<bits/stdc++.h>
using namespace std;
int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	stack<int> s;

	vector<int> v;
	vector<int> a(n,0);

	for (int i = 0; i < n; i++)
	{
		int now = 0;
		cin >> now;
		v.push_back(now);
	}

	s.push(0);
	for (int i = 1; i < n; i++)
	{
		while(s.size() != 0 && v[i] > v[s.top()])
		{
			a[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}
	while (s.size())
	{
		int k = s.top(); s.pop();
		a[k] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			cout << "-1" << ' ';
			continue;
		}
		cout << a[i] << ' ';
	}

	return 0;
}