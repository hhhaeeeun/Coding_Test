#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int A[21][21];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0,-1,0,1 };
vector<int> v;
const int INF = 987654321;
int ret = INF;

void start_link() {
	int team[21]= {0,};
	for (int i : v) {
		team[i] = 1;
	}
	vector<int> s;
	for (int i = 0; i < n; i++)
	{
		if (team[i] == 0) s.push_back(i);
	}
	int first = 0;
	for (int i = 0; i < v.size()-1; i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			first += A[v[i]][v[j]];
		}
	}

	int second = 0;
	for (int i = 0; i < s.size() - 1; i++)
	{
		for (int j = i + 1; j < s.size(); j++)
		{
			second += A[s[i]][s[j]];
		}
	}

	int tem = abs(second - first);
	ret = min(tem, ret);
	return;
}

void combi(int start) {
	if (v.size() == k)
	{
		start_link();
		return;
	}

	for (int i = start + 1; i < n; i++)
	{
		v.push_back(i);
		combi(i);
		v.pop_back();
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n ;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tem = 0;
			cin >> tem;
			if (i > j)	A[j][i] += tem;
			else A[i][j] += tem;
		}
	}
	k = n / 2;

	combi(-1);

	cout << ret << "\n";

	return 0;
}