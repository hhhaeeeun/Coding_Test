#include<bits/stdc++.h>
using namespace std;
int matrix[1025][1025];
int n,m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;


	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			int num;
			cin >> num;
			matrix[i][j] = matrix[i][j - 1] + matrix[i - 1][j] - matrix[i - 1][j - 1] + num;
		}
	}
	int x1, x2, y1, y2;

	for (int i = 0; i < m; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cout << matrix[x2][y2] - matrix[x1 - 1][y2] - matrix[x2][y1 - 1] + matrix[x1 - 1][y1 - 1] << '\n';
	}
	return 0;
}
