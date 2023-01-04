#include<bits/stdc++.h>
using namespace std;
int n, m, start;

vector<vector<int>> A;
vector<bool> visited;

void dfs(int v)
{
	if (visited[v] == true)return;
	cout << v << " ";
	visited[v] = true;

	for (int i = 0; i < A[v].size(); i++)
	{
		if (visited[A[v][i]] == false)
		{
			dfs(A[v][i]);
		}
	}
}

void bfs(int v)
{
	queue<int> q;
	q.push(v);
	visited[v] = true;
	while (q.size() != 0)
	{
		cout << q.front() << ' ';
		vector<int> tmp = A[q.front()];
		for (int i = 0; i < tmp.size(); i++)
		{
			if (visited[tmp[i]] == false)
			{
				visited[tmp[i]] = true;
				q.push(tmp[i]);
			}
		}
		q.pop();
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n >> m >> start;
	A.resize(n+1);
	visited = vector<bool>(n+1, false);

	for (int i = 0; i < m; i++)
	{
		int s = 0;
		int e = 0;
		cin >> s >> e;
		A[s].push_back(e);
		A[e].push_back(s);
	}

	for (int i = 1; i < n + 1; i++)
	{
		sort(A[i].begin(), A[i].end());
	}

	dfs(start);
	cout << "\n";
	visited = vector<bool>(n+1, false);
	bfs(start);
	return 0;
}