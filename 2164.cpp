#include<bits/stdc++.h>
using namespace std;
int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	queue<int> q;

	for (int i = 1; i < n+1; i++)
	{
		q.push(i);
	}

	int num = 0;
	while (q.size()>1)
	{
		q.pop();
		num = q.front();
		q.pop();
		q.push(num);
	}

	cout << q.front();

	return 0;
}