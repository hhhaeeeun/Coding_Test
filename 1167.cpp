#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<pair<int, int>>> A;
vector<bool> visited;
vector<int>m_distance;

void bfs(int v)
{
	queue<int> q;
	q.push(v);
	m_distance[v] = 0;
	visited[v] = true;
	while (q.size())
	{
		int index = q.front(); q.pop();
		for (int i = 0; i < A[index].size(); i++) {
			if (visited[A[index][i].first] == false)
			{
				m_distance[A[index][i].first] = m_distance[index] + A[index][i].second;
				visited[A[index][i].first] = true;
				q.push(A[index][i].first);
			}
		}
		
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	A.resize(n + 1);

	for (int i = 0; i < n; i++)
	{
		int next = 0;
		int num = 0;
		cin >> num;
		cin >> next;
		while (next != -1)
		{
			int a = 0; int b = 0;
			a = next;
			cin >> b;			
			A[num].push_back(make_pair(a, b));
			cin >> next;
		}
	}

	visited = vector<bool>(n + 1, false);
	m_distance = vector<int>(n + 1, 0);

	bfs(1);
	int now = m_distance[1];
	int index = 1;
	for (int i = 2; i < n+1; i++)
	{
		if (m_distance[i] > now)
		{
			now = m_distance[i];
			index = i;
		}
	}
	visited = vector<bool>(n + 1, false);
	m_distance = vector<int>(n + 1, 0);
	bfs(index);

	now = m_distance[1];
	for (int i = 2; i < n+1; i++)
	{
		if (m_distance[i] > now)
		{
			now = m_distance[i];
		}
	}
	cout << now << "\n";
	return 0;
}