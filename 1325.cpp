#include<bits/stdc++.h>
using namespace std;
int n, m;

vector<vector<int>> A;
vector<bool> visited;
vector<int> c_number;


void bfs(int v)
{
	queue<int> q;
	q.push(v);
	visited[v] = true;
	while (q.size())
	{
		int now = q.front(); q.pop();
		for (int i = 0; i < A[now].size(); i++)
		{
			if (visited[A[now][i]] == false)
			{
				q.push(A[now][i]);
				visited[A[now][i]] = true;
				c_number[A[now][i]]++;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;

	A.resize(n + 1);
	visited.resize(n + 1, 0);
	c_number.resize(n + 1, 0);
	for (int i = 0; i < m; i++)
	{
		int s = 0;
		int e = 0;
		cin >> s >> e;
		A[s].push_back(e);
	}

	for (int i = 1; i < n+1; i++)
	{
		bfs(i);
		fill(visited.begin(), visited.end(), 0);
	}
	
	vector<int> answer;
	int max = 0;
	for (int i = 1; i < n+1; i++)
	{
		if (max < c_number[i])
		{
			answer.resize(1,0);
			answer[0] = i;
			max = c_number[i];
		}
		else if (max == c_number[i])
		{
			answer.push_back(i);
		}
	}
	for(int i : answer)
	{
		cout << i << " ";
	}
	

	/*
	int maxVal = 0;
	for (int i = 1; i <= n; i++) {
		maxVal = max(maxVal, c_number[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (c_number[i] == maxVal) //answer배열에서 maxVal와 같은 값을 가진 index를 정답으로 출력
			cout << i << " ";
	}
	*/
	return 0;
}
