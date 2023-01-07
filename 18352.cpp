#include<bits/stdc++.h>
using namespace std;
int n, m, k, x;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k >> x;
	vector<vector<int>> A(n+1);
	vector<int> m_distance(n + 1,0);
	vector<bool> visited(n + 1, 0);
	for (int i = 0; i < m; i++)
	{
		int s = 0;
		int e = 0;
		cin >> s >> e;
		A[s].push_back(e);
	}

	queue<int> q;
	q.push(x);
	visited[x] = true;
	while (q.size()) {
		int now = q.front(); q.pop();
		for(int i = 0; i<A[now].size();i++)
		{
			if (visited[A[now][i]] == false)
			{
				q.push(A[now][i]);
				visited[A[now][i]] = true;
				m_distance[A[now][i]] = m_distance[now] + 1;
			}
		}
	}
	bool answer = false;
	for (int i = 1; i < n + 1; i++)
	{
		if (m_distance[i] == k)
		{
			cout << i << endl;
			answer = true;
		}
	}
	if(answer == false)
		cout << "-1" << endl;

	return 0;
}