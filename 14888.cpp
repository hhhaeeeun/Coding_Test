#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int A[12];
int dir[4];
ll m_min, m_max;

ll calculator(int a, int b, int c)
{
	if (c == 0)
	{
		return a + b;
	}
	if (c == 1)
	{
		return a - b;
	}
	if (c == 2)
	{
		return a * b;
	}
	if (c == 3)
	{
		return a / b;
	}
	return -1;

}

ll dfs(vector<int> v)
{
	ll temp = calculator(A[0], A[1], v[0]);
	for (int i = 2; i < n; i++)
	{
		temp = calculator(temp, A[i], v[i - 1]);
	}
	return temp;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	vector<int> q;
	for (int i = 0; i < 4; i++)
	{
		int temp;
		cin >> temp;
		for(int j =0;j<temp;j++)
		{
			q.push_back(i);
		}
	}

	vector<vector<int>> v;
	do {
		v.push_back(q);
	} while (next_permutation(q.begin(), q.end()));

	m_min = 100000001;
	m_max = -100000001;

	for (int i = 0; i < v.size(); i++)
	{
		m_min = min(m_min, dfs(v[i]));
		m_max = max(m_max, dfs(v[i]));
	}
	cout << m_max << "\n";
	cout << m_min << "\n";

	return 0;
}