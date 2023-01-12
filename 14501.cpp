#include<bits/stdc++.h>
using namespace std;
int n, m;
int T[1001];
int M[1001];
int visited[1001];
int ret, sum;
void dfs(int y)
{
	if (y + T[y] > n)
	{
		ret = max(ret, sum);
		return;
	}
	if (y >= n)
	{
		ret = max(ret, sum);
		return;
	}
	sum += M[y];
	for (int i = 0; i < n; i++)
	{
		int ny = y + T[y] + i;
		dfs(ny);
	}
	sum -= M[y];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n ;
	for (int i = 0; i < n; i++) {
		int a = 0; int b = 0;
		cin >> a >> b;
		T[i] = a;
		M[i] = b;
	}
	for (int i = 0; i < T[0]; i++)
	{	
		sum = 0;
		dfs(i);
	}
	cout << ret << "\n";
	return 0;
}