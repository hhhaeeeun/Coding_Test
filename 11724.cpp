#include<bits/stdc++.h>
using namespace std;
int n, m;

static vector<vector<int>> A;
static vector<bool> visited;
void dfs(int v) {
	if (visited[v] == true)return;

	visited[v] = true;

	for (int i = 0; i < A[v].size(); i++)
	{
		if(visited[A[v][i]] == false )
			dfs(A[v][i]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	A.resize(n + 1);
	visited = vector < bool>(n + 1, false);

	for (int i = 0; i < m; i++)
	{
		int s = 0;
		int e = 0;
		cin >> s >> e;
		A[s].push_back(e);
		A[e].push_back(s);
	}

	int count = 0;

	for (int i = 1; i < n+1; i++)
	{
		if (visited[i] != true)
		{
			count++;
			dfs(i);
		}
	}

	cout << count << "\n";
	return 0;
}