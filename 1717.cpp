#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> A;
int find(int v)
{
	
	if (A[v] == v)
	{
		return v;
	}
	else
	{
		return A[v] = find(A[v]);
	}
}

void union_func(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a != b)
		A[b] = a;

}

bool checkSame(int a, int b) { // 두 원소가 같은 집합인지 확인
	a = find(a);
	b = find(b);
	if (a == b) {
		return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n >> m;
	A.resize(n+1, 0);
	for (int i = 0; i < n+1; i++)
		A[i] = i;



	for (int i = 0; i < m; i++)
	{
		int k = 0; int s = 0; int e = 0;
		cin >> k >> s >> e;
		if (k == 0)
		{ 
			union_func(s, e);
		}
		else if (k == 1)
		{

			if (checkSame(s, e))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}