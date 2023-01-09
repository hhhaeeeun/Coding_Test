#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> answer;
int dy[3] = { -1, 1, 2 };
int visited[100001];
long long cnt[100001];
void bfs(int y)
{
	queue<int> q;
	q.push(y);
	visited[y] = 1;
	cnt[y] = 1;
	while (q.size())
	{
		int now = q.front(); q.pop();
		for (int next : {now - 1, now + 1, now * 2})
		{
			if (next < 0 || next > 100001) continue;
			if (visited[next] == 0)
			{
				visited[next] = visited[now] + 1;
				cnt[next] += cnt[now];
				q.push(next);
			}
			else if (visited[next] == visited[now] + 1)
			{
				cnt[next] += cnt[now];
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
	visited[n] = 1;
	if (n == m) {
		cout << 0 << endl;
		cout << 1 << endl;
		return 0;
	}
	bfs(n);
	sort(answer.begin(), answer.end());
	int i = 0;
	int ret = 0;
	int min_num = answer[0];


	cout << visited[m]-1 << "\n";
	cout << cnt[m] << "\n";
	return 0;
}
